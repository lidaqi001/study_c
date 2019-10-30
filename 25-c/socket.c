/**
 * 一整套完整的创建网络服务器流程
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int listener_d;

char *advice[] = {
    "Take smaller bites\r\n",
    "Go for the tight jeans. No they do NOT make you look fat.\r\n",
    "One word: inappropriate\r\n",
    "Just for today, be honest. Tell your boss what you *really* think\r\n",
    "You might want to rethink that haircut\r\n"
};

void _error(char *msg, int isExit)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    if (isExit == 0)
        exit(1);
}
// 因为c不支持函数默认参数
// 所以用宏模拟
#define DEFARG(arg, defval) ((#arg[0])?(arg+0):defval)
#define error(arg0, arg1) _error(DEFARG(arg0, 0), DEFARG(arg1, 0))

void open_listener_socket()
{
    // 创建套接字
    listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1) 
        error("不能创建套接字",);
}

void bind_to_port()
{
    // 创建一个"互联网30000端口"的套接字名
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    // 设置套接字选项: "重新使用端口"
    // 绑定端口有延时,30 秒 ,加上该选项, 去除延时, 端口立即生效
    int reuse = 1;
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error(" 无法设置套接字的“重新使用端口”选项 ",);

    // 套接字绑定端口
    if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1) 
        error("无法绑定接口",);
}

int say(int connect_d,char *s)
{
    // 发送消息,开始通信
    int result = send(connect_d, s, strlen(s), 0);
    if ( result == -1) 
        error("和客户端通信发生错误", 1);
    
    return result;
}

int read_in(int socket, char *buf, int len)
{   
    // 读取
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c-1] != '\n')) {
        s += c; slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';
    else
        s[c-1]='\0';
    return len - slen;
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}

void handle_shutdown(int sig)
{
    // 关闭连接
    if (listener_d) 
        close(listener_d);

    fprintf(stderr, "Bye~\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    // 自定义信号处理器
    if (catch_signal(SIGINT, handle_shutdown) == -1) {
        error("Can't set the interrupt handler",);
    }

    // 创建套接字
    open_listener_socket();
    
    // 套接字绑定端口
    bind_to_port();

    // 监听端口
    if (listen(listener_d, 10) == -1) 
        error("无法监听",);
    
    puts("Waiting for connection");

    char buf[255];
    while (1)
    {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        // 接收连接
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
        char *msg = advice[rand() % 5];
        
        // fork子进程中处理多任务
        if (!fork()){
            // 在子进程钟,需要关闭主监听套接字(子进程只用connect_d套接字和客户端通信)
            close(listener_d);
            // 发送消息,开始通信
            if (say(connect_d, msg) != -1)
                read_in(connect_d, buf, sizeof(buf));
                if (strncasecmp("Who's there?", buf, 12)) 
                    say(connect_d, "You should say 'Who's there?'");
                else
                {
                    if (say(connect_d, "Oscar\r\n> ") != -1) {
                        read_in(connect_d, buf, sizeof(buf));
                        if (strncasecmp("Oscar who?", buf, 10)) 
                            say(connect_d, "youshould say 'Oscar who?'");
                        else
                            say(connect_d, "Oscar silly question, you set a silly answer \r\n");
                    }
                }
            // 关闭连接
            close(connect_d);
            // 通信结束,子进程退出程序,防止子进程进入服务器的主循环
            exit(0);
        }
    }
    
    return 0;
}
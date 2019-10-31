#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void open_url(char *url)
{
    if(execl("/opt/google/chrome/chrome", 
        "/opt/google/chrome/chrome", 
        url,
        NULL) == -1) {
            error("打开网页失败");
        }
}

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"./output", NULL};

    FILE *f = fopen("stories.txt", "w");
        if (!f) {
            error("Can't open stories.txt");
    }

    // 管道
    int fd[2];
    if (pipe(fd) == -1) {
        error("创建管道失败");
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    if (!pid) {
        // 重定向标准输出到文件
        // if (dup2(fileno(f),1) == -1) {
        //     error("Can't redirect Standard Output");
        // }

        // 重定向标准输出到管道写入端
        dup2(fd[1], 1);
        close(fd[0]);   // 关闭管道的读取端, 因为子进程不会读取管道
        
        if (execle("./test", "./test", "",
            phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    
    // 父进程标准输入重定向子进程管道的读取端
    dup2(fd[0], 0);
    close(fd[1]);   // 关闭管道的写入端, 因为管道连接的是标准输入

    // 监测子进程状态,子进程退出后主进程退出
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("等待子进程时发生错误");
    }

    char line[255];
    // 将从标准输入读取数据, 因为管道连到了标准输入
    while (fgets(line, 255, stdin))
    {
        open_url(line);
    }
    
    return 0;
}
13-1message.o:13-1message.c 13-3encrypt.h
	gcc -c 13-1message.c
13-2encrypt.o:13-2encrypt.c 13-3encrypt.h
	gcc -c 13-2encrypt.c
encrypt:13-1message.o 13-2encrypt.o
	gcc 13-1message.o 13-2encrypt.o -o encrypt
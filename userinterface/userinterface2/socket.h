#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>


class Socket
{
public:
    Socket();
    ~Socket();
    void socketwrite(char);

private:
    int sock;
    unsigned short portno;
    int n;
    struct sockaddr_in serv_addr;
};

#endif // SOCKET_H

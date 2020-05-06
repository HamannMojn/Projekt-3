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


class Socket
{
public:
    Socket();
    ~Socket();
    void read();
    void socketwrite(char);

private:
    int sock;
    int portno;
    int n;
    char buffer_;
    struct sockaddr_in serv_addr;
    struct hostent *server;
};

#endif // SOCKET_H

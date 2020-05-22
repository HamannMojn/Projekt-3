#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include "psoccom.h"

using namespace std;

class TCPServer
{
public:
    TCPServer(string ipAdr, int portno);
    int sockfd();
    int call(int sock);
    void run();

private:
    int clisocket;
    char buf[1];
    string m_ipAdr;
    int m_portno;
    struct sockaddr_in adr, cli;
    socklen_t clilen = sizeof(cli);
    int sock;
    comsock psoc;

};
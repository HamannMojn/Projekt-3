#include "socket.h"

using namespace std;

Socket::Socket()
    : sock{0}, portno{51717}, n{0}
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock==-1)
    {
        cout << "Fejl i opsætning af socket"<<endl;
    } else
    {
        cout<<"Socket opsat"<<endl;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.0.1");
}

Socket::~Socket()
{
    close(sock);
}

void Socket::write(char buffer)
{
    bzero(buffer_, sizeof(buffer_));
    for(unsigned int i =0; i<sizeof(buffer)-1; i++)
    {

    }
}


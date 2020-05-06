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
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    n = 0;

    if(connect(sock,(struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
        cout<<"fejl med forbindelse"<<endl;
}

Socket::~Socket()
{
    close(sock);
}

void Socket::socketwrite(char buffer)
{
   cout<<"sender"<<endl;
   n = write(sock, &buffer, sizeof(buffer));
   if(n<0)
       cout<<"kæft noget lårt"<<endl;
   else
       cout<<"it naue alliwel do"<<endl;

   cout<<"sender"<<buffer<<endl;
}



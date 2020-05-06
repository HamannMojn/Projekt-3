#include "socket.h"

using namespace std;

Socket::Socket()
    :portno{51717}, n{0}
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
    struct hostent *server;
    server = gethostbyname("10.9.8.2");
    if(server == NULL){
      std::cout << "No such host as " <<std::endl;
    }
    bcopy((char *)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
    //serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    n = 0;

    if(connect(sock,(struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
        cout<<"fejl med forbindelse"<<errno<<endl;
}

Socket::~Socket()
{
    close(sock);
}

void Socket::socketwrite(char buffer)
{
   cout<<"sender"<<endl;
   n = write(sock, &buffer, 1);
   if(n<0)
       cout<<"kæft noget lårt"<<endl;
   else
       cout<<"it naue alliwel do"<<endl;

   cout<<"sender"<<buffer<<endl;
}



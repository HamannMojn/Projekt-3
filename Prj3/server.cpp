#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include "server.h"

using namespace std;


TCPServer::TCPServer(string ipAdr, int portno) : m_ipAdr(ipAdr.c_str()),m_portno(portno)
{
    
}
int TCPServer::sockfd()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return -1;
    }
    else 
        cout << "Socket lavet - pisse fedt" << endl;
    
        bzero(&adr, sizeof(adr));
        adr.sin_family = AF_INET;
        adr.sin_port = htons(m_portno);
        inet_pton(AF_INET, m_ipAdr.c_str(), &adr.sin_addr);

        if (bind(sock, (sockaddr*)&adr, sizeof(adr)) == -1)
        {
            cout << "Kan ikke binde til IP og port" << endl;
            return -1;
        }
        else  
            cout << "Det lykkedes at binde socket" << endl;
            if (listen(sock,5) == -1)
            {
                cout << "Alt er lort" << endl;
                return -1;
            }
            else 
                cout << "Server lytter" << endl;


    return sock;
}

int TCPServer::call(int sock)
{
    clisocket = accept(sock, (sockaddr*)&cli, &clilen);
    if (clisocket == -1)
    {
        cout << "Alt er lort med client socket" << endl;
        return 0;
    }
    else
    {
        cout << "Du har modtaget et opkald" << endl;
    }
    return clisocket;

}
void TCPServer::run()
{
    sock = sockfd();
    
    while(true)
    {
        if (sock != -1)
        {
            cout << "run kører" << endl;
        }
            
        clisocket = call(sock);
        if(clisocket != -1)
        {
            close(sock);
                //psoc.open_port();
            do
            {
                bzero(buf, sizeof(buf));
                bRead = read(clisocket, buf, sizeof(buf));
                switch(buf[0])
                {
                    case '1':
                        psoc.forward();
                        break;
                    case '2':
                        psoc.backward();
                        break;
                    case '3':
                        psoc.left();
                        break;
                    case '4':
                        psoc.right();
                        break;
                    case '8':
                        psoc.lift();
                        break;
                    case '9':
                        psoc.lower();
                        break;
                    case '0':
                        psoc.stop();
                        break;
                    default:
                    cout << buf[0] << endl;
                }
            } while (bRead > 0);
            close(clisocket);
        }
    }
}

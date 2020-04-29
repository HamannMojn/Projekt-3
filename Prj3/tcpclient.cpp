#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>

using namespace std;

void chat(int sock)
{
    char buf[4096];
    int n;
    for (;;)
    {
        bzero(buf, sizeof(buf));
        cout << "Indtast besked" << endl;
        n = 0;
        while((buf[n++]=getchar()) != '\n');
        write(sock, buf, sizeof(buf));
        bzero(buf, sizeof(buf));
        read(sock, buf, sizeof(buf));
        cout << "Server: " << buf << endl;
        if ((strncmp(buf, "luk", 3)) == 0)
        {
            cout << "Client Lukker" << endl;
            break;
        }
    }
}

int main()
{
    // Lav socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        cout << "Socket virker ikke" << endl;
        return -1;
    }
    else
    {
        cout << "socket lavet" << endl;
    }
    
    // bind socket til IP og port
    int portno = 51717;

    sockaddr_in adr;
    adr.sin_family = AF_INET;
    adr.sin_port = htons(portno);
    adr.sin_addr.s_addr = inet_addr("192.168.0.1");
    // Connect til server
    int con = connect(sock, (sockaddr*)&adr, sizeof(adr)); 
    if (con != 0)
    {
        cout << "Kan ikke connecte til socket" << endl;
        return -2;
    }
    
    chat(sock);
    // Luk socket
    close(sock);

    return 0;
}
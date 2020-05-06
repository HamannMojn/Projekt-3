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

void chat(int listening)
{
    char buf[4096];
    int n;
    for(;;)
    {
        bzero(buf, sizeof(buf));
        
        read(listening, buf, sizeof(buf));
        cout << "Client: " << buf << endl;
        bzero(buf, sizeof(buf));
        n = 0;
        while ((buf[n++] = getchar()) != '\n');

        write(listening, buf, sizeof(buf));

        if (strncmp("luk", buf, 3) == 0)
        {
            cout << "lukker server " << endl;
            break;
        }
    }
    
}

int main()
{
    //Lav socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cout << "Kan ikke oprette socket" << endl;
        return -1;
    }
    else 
        cout << "Socket lavet - pisse fedt" << endl;
    
    // Bind socket til IP og port
    sockaddr_in adr;
    string ipAdr = "127.0.0.1";
    int portno = 51717;

    adr.sin_family = AF_INET;
    adr.sin_port = htons(portno);
    inet_pton(AF_INET, ipAdr.c_str(), &adr.sin_addr);
    
    if (bind(listening, (sockaddr*)&adr, sizeof(adr)) == -1)
    {
        cout << "Kan ikke binde til IP og port" << endl;
        return -2;
    }
    else  
        cout << "Det lykkedes at binde socket" << endl;

    // Listen
    if (listen(listening,5) == -1)
    {
        cout << "Alt er lort" << endl;
        return -3;
    }
    else 
        cout << "Server lytter" << endl;
    
    // Accepter call
    sockaddr_in cli;
    socklen_t clilen = sizeof(cli);
    int clisocket = accept(listening, (sockaddr*)&cli, &clilen);
    if (clisocket == -1)
    {
        cout << "Alt er lort med client socket" << endl;
        return -4;
    }

    chat(clisocket);
    
    // luk socket
    close(listening);

}
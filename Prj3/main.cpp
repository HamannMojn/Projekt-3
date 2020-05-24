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

int main()
{
    TCPServer tester("127.0.0.1", 51717);
    tester.run();
    return 0;
}
    #include <stdio.h>   
    #include <string.h>    
    #include <unistd.h>   
    #include <fcntl.h>    
    #include <errno.h> 
    #include <termios.h> 
    #include <iostream>
    #include "psoccom.h"

    using namespace std;

    comsock::comsock()
    {
        struct termios options;
   

        tcgetattr(fd, &options);


        cfsetispeed(&options, B115200);
        cfsetospeed(&options, B115200);


        options.c_cflag |= (CLOCAL | CREAD);


        options.c_cflag &= ~CSIZE; 
        options.c_cflag |= CS8;    
    
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;


        tcsetattr(fd, TCSANOW, &options);
    }


    /*int comsock::open_port()
    {
        fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);   
            
        if(fd == -1) 
        {               
        perror("open_port: Unable to open /dev/ttyAMA0 − ");      
        }      
        return (fd);   
    }

    int comsock::close_port()
    {    
        close(fd);
        return (fd);
    }
    */
    int comsock::forward()
    {
        write(fd, "1", 1);
        cout << "Lyfter! kører fremad" << endl;
        return(fd);
    }

    int comsock::backward()
    {
        write(fd, "2", 1);
        cout << "Lyfter! kører baglæns" << endl;
        return (fd);
    }

    int comsock::right()
    {
        write(fd,"4", 1);
        cout << "Lyfter! drejer til højre" << endl;
        return (fd);
    }

    int comsock::left()
    {
        write(fd,"3", 1);
        cout << "Lyfter! drejer til venstre" << endl;
        return (fd);
    }

    int comsock::stop()
    {
        write(fd,"0",1);
        cout << "Lyfter! stopper" << endl;
        return (fd);
    }

    int comsock::lift()
    {
        write(fd,"8",1);
        cout << "Lyfter! løfter" << endl;
        return (fd);
    }

    int comsock::lower()
    {
        write(fd,"9",1);
        cout << "Lyfter! sænker" << endl;
        return (fd);
    }
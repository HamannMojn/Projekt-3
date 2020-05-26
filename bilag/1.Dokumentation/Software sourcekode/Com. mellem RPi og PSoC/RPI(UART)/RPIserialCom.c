    #include <stdio.h>   /* Standard input/output definitions */    
    #include <string.h>  /* String function definitions */    
    #include <unistd.h>  /* UNIX standard function definitions */    
    #include <fcntl.h>   /* File control definitions */    
    #include <errno.h>   /* Error number definitions */    
    #include <termios.h> /* POSIX terminal control definitions */    
    
    /*     * 'open_port()' − Open serial port 1.     *     
    * Returns the file descriptor on success or −1 on error.     */    
   
   int fd; /* File descriptor for the port */

   struct protocol
   {
      int stop;
      int forward;
      int back;
      int left;
      int right;
      int lift;
      int lower;
   };
   
   int open_port(void)    
   {            
     fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);   
         
     if(fd == -1) 
     {       
       /*        * Could not open the port.        */        
       perror("open_port: Unable to open /dev/ttyAMA0 − ");      
     }      
     
    return (fd);    
  }

  int close_port(void)
  {
    close(fd);
    return (fd);
  }

  int stop(void)
  {
    struct protocol id;

    id.stop = write(fd, "0", 1);
    if (id.stop < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);

    return(fd);
  }

  int forward(void)
  {
    struct protocol id;

    id.forward = write(fd, "1", 1);
    if (id.forward < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  int backwards(void)
  {
    struct protocol id;

    id.back = write(fd, "2", 1);
    if (id.back < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  int left(void)
  {
    struct protocol id;

    id.left = write(fd, "3", 1);
    if (id.left < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  int right(void)
  {
    struct protocol id;

    id.right = write(fd, "4", 1);
    if (id.right < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  int lift(void)
  {
    struct protocol id;

    id.lift = write(fd, "8", 1);
    if (id.lift < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  int lower(void)
  {
    struct protocol id;

    id.lower = write(fd, "9", 1);
    if (id.lower < 0)
    fputs("Writing 1 byte to BCM 14 TXD failed!\n", stderr);
    return(fd);
  }

  void uart_options()
  {
    struct termios options;
    /*
    * Get the current options for the port...
    */
    tcgetattr(fd, &options);
    /*
    * Set the baud rates to 9600...
    */
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    /*
    * Enable the receiver and set local mode...
    */
    options.c_cflag |= (CLOCAL | CREAD);
    /*
    * Set to 8 data bits
    */
    options.c_cflag &= ~CSIZE; /* Mask the character size bits */
    options.c_cflag |= CS8;    /* Select 8 data bits */
    /*
    * Set to no parity
    */
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    /*
    * Set the new options for the port...
    */
    tcsetattr(fd, TCSANOW, &options);
  }

  int main()
  {
    uart_options(); //Initialize UART options
    printf("Serial transmitter program has started...\n\n");
    
    printf("Press 0 to stop\nPress 1 to move forward\nPress 2 to move backwards\nPress 3 to turn left\nPress 4 to turn right\nPress 8 to lift the arm\nPress 9 to lower the arm\nPress 5 to stop program\n\n");
    
    open_port();
    while(1)
    {
      char input = getchar();
      switch(input)
      {
        case '0' :
        {
          printf("You entered %c", input);
          printf("\nStop the car\n\n");
          stop();
        }
        break;
        case '1' :
        {
          printf("You entered %c", input);
          printf("\nDrive forwards\n\n");
          forward();
          sleep(1);
        }
        break;
        case '2' :
        {
          printf("You entered %c", input);
          printf("\nDrive backwards\n\n");
          backwards();
          sleep(1);
        }
        break;
        case '3' :
        {
          printf("You entered %c", input);
          printf("\nTurn left\n\n");
          left();
          sleep(1);
        }
        break;
        case '4' :
        {
          printf("You entered %c", input);
          printf("\nTurn right\n\n");
          right();
          sleep(1);
        }
        break;
        case '5' :
        {
          printf("You entered %c", input);
          printf("\nExiting the program\n\n");
          goto exit;
        }
        break;
        case '8' :
        {
          printf("You entered %c", input);
          printf("\nLift object\n\n");
          lift();
          sleep(1);
        }
        break;
        case '9' :
        {
          printf("You entered %c", input);
          printf("\nLower object\n\n");
          lower();
          sleep(1);
        }
        break;
      }
    }
    exit:
    close_port();

    return 0;
  }

  
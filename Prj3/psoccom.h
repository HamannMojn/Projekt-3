    #include <stdio.h>   
    #include <string.h>    
    #include <unistd.h>   
    #include <fcntl.h>    
    #include <errno.h> 
    #include <termios.h> 
    


class comsock
{
    public:
    comsock();

    int open_port();
    int close_port();
    int forward();
    int backward();
    int right();
    int left();
    int stop();
    int lift();
    int lower();

    private:
    int fd; 
};
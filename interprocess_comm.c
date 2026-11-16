#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main_interprocess_comm() {
    
    int mypid, myppid;
    
    printf( "program to know PID and PPID's information\n" );
    
    mypid = getpid();
    printf( "My process ID is %d\n", mypid );
    
    myppid = getppid();
    printf( "My parent process ID is %d\n", myppid );
    
    printf( "Cross validation of pid's by executing process commands on shell\n" );
    system( "ps -ef" );
    
    return 0;
    
}
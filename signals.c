#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main_signals() {
    
    alarm(5);  // alarm signal will be raised in 5 seconds
    
    for( int i=1 ; i < 10 ; i++ ) {
        printf( "%d\n", i );
        sleep(1);
    }
    
    // SIGSTOP stopps execution but program is still alive
    printf( "Testing SIGSTOP\n" );
    raise(SIGSTOP);
    return 0;
}
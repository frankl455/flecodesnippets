#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_attr_t attr;

void *dowork( void *threadid ) {
    long tid;
    size_t mystacksize;
    tid = (long) threadid;
    pthread_attr_getstacksize( &attr, &mystacksize );
    
    printf( "Thread %ld: stack size = %li bytes \n", tid, mystacksize );
    
    pthread_exit( NULL );
}

int main_threadfunc() {
    
    pthread_t myThread;
    size_t stacksize;
    int myID;
    long t = 0;
    
    pthread_attr_init( &attr );
    pthread_attr_getstacksize( &attr, &stacksize );
    printf( "Default stack size = %li\n", stacksize );
    stacksize = 9000000;
    printf( "Amount of stack needed per thread = %li\n", stacksize );
    pthread_attr_setstacksize( &attr, stacksize );
    
    printf( "Creating thread with stack size = %li bytes\n", stacksize );
    
    myID = pthread_create( &myThread, &attr, dowork, (void*) t );
    
    if( myID ) {
        printf( "ERROR; return code from pthread_create is %d\n", myID );
    }
    pthread_exit( NULL );
}
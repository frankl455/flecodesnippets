#define _POSIX_C_SOURCE 200809L // without the strdup is unknown by string.h
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>

struct thread_data {
    int thread_id;
    int sum;
    char *message;
};

void * printHello( void *thread_arg ) {
    struct thread_data *my_data;
    
    int taskid = 0, sum = 0;
    char hello_msg[255];
    char *hello = strdup( "Return string from thread\n" );
    
    printf( "In function \nthread id = %d\n", *(int*)pthread_self() );
    
    my_data = (struct thread_data *) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strcpy( hello_msg, my_data->message);
        
    printf( "taskid = %d, sum = %d, message = %s\n", taskid, sum, hello_msg );
    return (void*) hello;
}

int main_threadargs() {
    
    pthread_t my_thread;
    struct thread_data my_thread_data;
    char * str;
    
    my_thread_data.message = malloc( sizeof(char) * 255 );
    
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Hello World";
    
    pthread_create( &my_thread, NULL, printHello, (void*) &my_thread_data );
    printf( "In main \nthread id = %d\n", *(int*)my_thread );
    pthread_join( my_thread, (void **) &str );
    printf( "Return string from thread function: %s\n", str );
    pthread_exit( NULL );
    return 0;
}
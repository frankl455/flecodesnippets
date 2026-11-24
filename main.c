#include <stdio.h>

int main_function_pointers();
int main_interprocess_comm();
int main_signals();
int main_signal_function();
int main_signal_handler();
int main_ipc();
int main_threads();
int main_threadargs();
int main_threadfunc();
int main_mutex();
int main_conditions();
int main_socketserver();
int main_socketclient();

long long convertDecimalToBinary( int n );

int main(int argc, char **argv) {

//    main_function_pointers();
//    main_interprocess_comm();
//    main_signals();
//    main_signal_function();
//    main_signal_handler();
//    main_ipc();
//    main_threads();
//    main_threadargs();
//    main_threadfunc();
//    main_mutex();
//    main_conditions();
//    main_socketserver();
 main_socketclient();

    return 0;
}


/*
int main(int argc, char **argv) {

	printf("fle code snippets\n");

    int n = 0;
    long long result = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &n);
    
    result = convertDecimalToBinary( n );
    
    printf( "%d in decimal = %lld in binary", n, result);
}
*/
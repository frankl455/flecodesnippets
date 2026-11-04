#include <stdio.h>

long long convertDecimalToBinary( int n );

int main(int argc, char **argv) {

	printf("fle code snippets\n");

    int n = 0;
    long long result = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &n);
    
    result = convertDecimalToBinary( n );
    
    printf( "%d in decimal = %lld in binary", n, result);
}

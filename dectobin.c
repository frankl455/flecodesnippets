#include <stdio.h>
#include <math.h>

long long convertDecimalToBinary( int n ) {
    
    long long binaryNumber = 0;
    int i = 1, reminder = 0;
    
    while (n != 0) {
        reminder = n % 2;
        n = n / 2;
        binaryNumber += reminder * i;
        i = i * 10;
    }
    return binaryNumber;
}

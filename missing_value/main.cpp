#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    long int n;
    long int x;
    long int missing = 0;
    
    // Read number of numbers
    scanf("%ld", &n);

    /*
        Use Gauss formula to compute the sum from 1 to n
            n * (n + 1) / 2
        and substract each input number to get the missing one.
        To prevent overflow
        n * (n + 1) / 2 - \sum_{j}^{n-1} x_j =
        \sum_{i=1}^{n} i \sum_{j=1}^{n-1} x_j =
        n + \sum_{i=1}^{n-1} (i - x_j)
    */
    for(long int i = 0; i < n - 1; i++) {
        scanf("%ld", &x);
        missing += i + 1 - x;
    }
    missing += n;

    // Output
    printf("%ld", missing);

    return 0;
}

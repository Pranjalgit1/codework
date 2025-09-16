#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sieve of Eratosthenes to find all primes up to N
void sieveOfEratosthenes(int n) {
    // Create boolean array "isPrime[0..n]" and initialize all entries as true
    int* isPrime = (int*)malloc((n + 1) * sizeof(int));
    memset(isPrime, 1, (n + 1) * sizeof(int));
    
    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime
    
    // Mark non-primes using Sieve of Eratosthenes
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
            }
        }
    }
    
    // Print all prime numbers
    int first = 1;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            if (!first) {
                printf(" ");
            }
            printf("%d", p);
            first = 0;
        }
    }
    printf("\n");
    
    free(isPrime);
}

int main() {
    int n;
    
    // Read input
    scanf("%d", &n);
    
    // Validate input constraints
    if (n < 2 || n > 1000000) {
        printf("Invalid input! N must be between 2 and 10^6\n");
        return 1;
    }
    
    // Find and print all primes up to N
    sieveOfEratosthenes(n);
    
    return 0;
} 
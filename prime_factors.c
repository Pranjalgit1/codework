#include <stdio.h>
#include <math.h>

// Optimized function to count prime factors
int countPrimeFactors(long long n) {
    if (n <= 1) return 0;
    
    int count = 0;
    
    // Handle even numbers (factor 2) - most common case
    while (n % 2 == 0) {
        count++;
        n = n / 2;
    }
    
    // Handle odd factors from 3 to sqrt(n) - optimized loop
    long long sqrt_n = (long long)sqrt(n);
    for (long long i = 3; i <= sqrt_n && n > 1; i += 2) {
        while (n % i == 0) {
            count++;
            n = n / i;
            sqrt_n = (long long)sqrt(n); // Recalculate sqrt for efficiency
        }
    }
    
    // If n is still > 1, it's a prime factor
    if (n > 1) {
        count++;
    }
    
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        int result = countPrimeFactors(n);
        printf("%d\n", result);
    }
    
    return 0;
} 
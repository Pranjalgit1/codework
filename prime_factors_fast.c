#include <stdio.h>
#include <math.h>

// Fast prime factor counting using wheel factorization
int countPrimeFactors(long long n) {
    if (n <= 1) return 0;
    
    int count = 0;
    
    // Handle factor 2
    while (n % 2 == 0) {
        count++;
        n >>= 1; // Faster than division
    }
    
    // Handle factor 3
    while (n % 3 == 0) {
        count++;
        n /= 3;
    }
    
    // Handle factors 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
    // Using wheel factorization with primes up to 47
    long long wheel[] = {5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int wheel_size = 13;
    
    for (int i = 0; i < wheel_size && n > 1; i++) {
        while (n % wheel[i] == 0) {
            count++;
            n /= wheel[i];
        }
    }
    
    // Handle remaining factors using optimized trial division
    if (n > 1) {
        long long sqrt_n = (long long)sqrt(n);
        for (long long i = 53; i <= sqrt_n && n > 1; i += 2) {
            // Skip multiples of 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
            int skip = 0;
            for (int j = 0; j < wheel_size; j++) {
                if (i % wheel[j] == 0) {
                    skip = 1;
                    break;
                }
            }
            if (skip) continue;
            
            while (n % i == 0) {
                count++;
                n /= i;
                sqrt_n = (long long)sqrt(n);
            }
        }
        
        // If n is still > 1, it's a prime factor
        if (n > 1) {
            count++;
        }
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
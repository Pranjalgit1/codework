#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    
    // Array to store results
    long long results[1000]; // Assuming max 1000 test cases
    
    // Read all input first
    for (int test = 0; test < t; test++) {
        int n;
        scanf("%d", &n);

        long long first = LLONG_MIN, second = LLONG_MIN, x;
        int count_first = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            
            if (x > first) {
                second = first;
                first = x;
                count_first = 1;
            } else if (x == first) {
                count_first++;
            } else if (x > second) {
                second = x;
            }
        }

        // If we have more than one occurrence of the largest element,
        // then the second largest is also the largest element
        if (count_first > 1) {
            second = first;
        }
        
        // Store the result
        results[test] = second;
    }
    
    // Print all results
    for (int test = 0; test < t; test++) {
        printf("%lld\n", results[test]);
    }

    return 0;
} 
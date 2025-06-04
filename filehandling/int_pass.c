#include <stdio.h>

// Function that takes regular integer (pass by value)
void modifyValue(int x) {
    x = x + 10;  // This change won't affect the original variable
    printf("Inside modifyValue: x = %d\n", x);
}

// Function that takes integer pointer (pass by reference)
void modifyPointer(int *x) {
    *x = *x + 10;  // This change will affect the original variable
    printf("Inside modifyPointer: *x = %d\n", *x);
}

int main() {
    int num = 5;
    int *ptr = &num;  // Pointer to num
    
    printf("Before function calls:\n");
    printf("num = %d\n", num);
    
    // Passing regular integer
    modifyValue(num);
    printf("After modifyValue: num = %d\n", num);  // num is still 5
    
    // Passing integer pointer
    modifyPointer(&num);  // or modifyPointer(ptr)
    printf("After modifyPointer: num = %d\n", num);  // num is now 15
    
    return 0;
} 
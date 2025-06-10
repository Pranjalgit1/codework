#include <stdio.h>

typedef struct date {
    unsigned int dd : 5;
    unsigned int mm : 4;
    unsigned int yy : 11;
} date;

int main() {
    date d1 = {31, 12, 2024};
    date d2 = {17, 17, 17};
    
    printf("Sizeof date is: %d\n", sizeof(struct date));
    printf("d1 is: %d:%d:%d\n", d1.dd, d1.mm, d1.yy);
    printf("d2 is: %d:%d:%d\n", d2.dd, d2.mm, d2.yy);
    
    return 0;
}

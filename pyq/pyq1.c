#include<stdio.h>
int main()
{ char str[] = "OUR UNIVERSITY";
char *s = str;
printf("%s\n",s++ +5);
return 0;
}
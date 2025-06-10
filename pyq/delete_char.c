#include<stdio.h>
void main()
{
char str1[20] = "Hello";
char str2[20] = "World";
printf("%s\n", strcpy(str2,strcat(str1, str2)));
}
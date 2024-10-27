//4. Demonstrate the use of different conversion specifiers and resulting output to allow the items to be printed.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>
int main(){
    int a = 8;
    float b = 8.8;
    char c = 'x';
    char s[] = "abcdef";
    printf("int = %d\nfloat = %f\nchar = %c\nstring = %s\nhex for int = %x\nexp for float = %e\n", a, b, c, s, a, b);
    return 0;
} 
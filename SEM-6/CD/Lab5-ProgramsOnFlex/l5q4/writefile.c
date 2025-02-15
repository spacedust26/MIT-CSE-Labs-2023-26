#include<stdio.h>

int main(){
    WRITE("abc");
    WRITE("def");
    WRITE("xyz");
    int abc;
    READ("%d", &abc);
    WRITE("abc");
    WRITE("abc");
    float val;
    READ("%f", &val);
    WRITE("abc");
    WRITE("abc");
}
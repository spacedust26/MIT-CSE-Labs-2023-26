// S→a | > | ( T )
// T→T, S|S
// After removing left recursion
// S→a | > | ( T )
// T→ST'
// T'-> ,ST'| epsilon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];

void S();
void T();
void Tprime();


void invalid() {
    printf("-----------------ERROR-------------------\n");
    exit(0);
}
void valid(){
    printf("-----------------SUCCESS-----------------\n");
    exit(0);
}
void S(){
    if(str[curr] == 'a'){
        curr++;
        return;
    }
    else if(str[curr] == '>'){
        curr++;
        return;
    }
    else if(str[curr] == '('){
        curr++;
        T();
        if(str[curr] == ')'){
            curr++;
            return;
        }
        else invalid();
    }
    else invalid();
}

void T(){
   S();
   Tprime();
}

void Tprime(){
    if(str[curr] == ','){
        curr++;
        S();
        Tprime();
    }
}

int main(){
    printf("Enter string: ");
    scanf("%s", str);
    S();
    if(str[curr] == '$') valid();
    else invalid();
}

//output
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ gcc -o l6q1 l6q1.c
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q1
// Enter string: (a,a)$
// -----------------SUCCESS-----------------
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q1
// Enter string: (a)
// -----------------ERROR-------------------
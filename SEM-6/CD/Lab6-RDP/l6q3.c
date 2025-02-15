// S→aAcBe
// A→Ab|b
// B→d

//without left recusrion
// S→aAcBe
// A→bA'
// A'-> bA'| epsilon
// B→d

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];
void S();
void A();
void Aprime();
void B();

void invalid() {
    printf("-----------------ERROR-------------------\n");
    exit(0);
}
void valid(){
    printf("----------------------------SUCCESS--------------------\n");
    exit(0);
}

void S(){
    if(str[curr] == 'a'){
        curr++;
        A();
        if(str[curr] == 'c'){
            curr++;
            B();
            if(str[curr] == 'e'){
                curr++;
                return;
            }else invalid();
        }else invalid();
    }else invalid();
}

void A(){
    if(str[curr] == 'b'){
        curr++;
        Aprime();
    }else invalid();
}

void Aprime(){
    if(str[curr] == 'b'){
        curr++;
        Aprime();
    }
}

void B(){
    if(str[curr] == 'd'){
        curr++;
        return;
    }
}
int main(){
    printf("Enter string: ");
    scanf("%s", str);
    S();
    if(str[curr] == '$') valid();
    else invalid();
}

// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ gcc -o l6q3 l6q3.c
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q3
// Enter string: abbcde$
// ----------------------------SUCCESS--------------------
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q3
// Enter string: accd$
// -----------------ERROR-------------------
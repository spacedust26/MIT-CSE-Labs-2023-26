/*
S→UVW
U →(S) | aSb | d
V → aV | 𝜖
W → cW | 𝜖
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];
void S();
void U();
void V();
void W();

void invalid() {
    printf("-----------------ERROR-------------------\n");
    exit(0);
}
void valid(){
    printf("----------------------------SUCCESS--------------------\n");
    exit(0);
}
void S(){
    U();
    V();
    W();
}
void U(){
    if(str[curr] == '('){
        curr++;
        S();
        if(str[curr] == ')'){
            curr++;
            return;
        }else invalid();
    }
    else if(str[curr] == 'a'){
        curr++;
        S();
        if(str[curr] == 'b'){
            curr++;
            return;
        }else invalid();
    }
    else if(str[curr] == 'd') {
        curr++;
        return;
    }
    else invalid();
}
void V(){
    if(str[curr] == 'a'){
        curr++;
        V();
    }
}
void W(){
    if(str[curr] == 'c'){
        curr++;
        W();
    }
}
int main(){
    printf("Enter string: ");
    scanf("%s", str);
    S();
    if(str[curr] == '$') valid();
    else invalid();
}

// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ gcc -o l6q2 l6q2.c
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q2
// Enter string: dac$
// ----------------------------SUCCESS--------------------
// CD_LAB_A1@debianpc-02:~/Desktop/220905018/Lab6-RDP$ ./l6q2
// Enter string: (ac)$
// -----------------ERROR-------------------
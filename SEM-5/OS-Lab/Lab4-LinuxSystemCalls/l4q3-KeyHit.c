// 3.Write a program to list the files given as arguments, stopping every 20 lines until a key is hit. (a simple version of more UNIX utility)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>

//give set of files as input
int main(int argc, char *argv[]) {
    int f, i = 0, k = 0, p = 0, x;
    char c[200], ch;

    for(x = 1; x < argc; x++) {

        if ((f = open(argv[x], O_RDONLY)) == -1) {
            printf("Error opening file %s ", argv[x]);
            exit(1);
        }

        while ((read(f, &ch, 1)) > 0) {
            if (ch != '\n')
            {
                c[i] = ch;
                i++;
            }

            else {
                k++;
                p++;
                c[i] = '\0';
                i = 0;
                printf("Line: %d \t %s \n", p, c);
                if (k == 20) {
                    fgetc(stdin);
                    k = 0;
                }
            }
        }
        close(f);
    }
}
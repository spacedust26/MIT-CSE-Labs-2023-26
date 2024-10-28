#include <stdio.h>
#include <stdlib.h>
#define dsksz 100
#define sparesz 10
#define filesz 5

int disk[dsksz];
int spare[sparesz];
int bad_block_table[dsksz];

void initDisk() {
    for (int i = 0; i < dsksz; i++) disk[i] = 0;
    for (int i = 0; i < dsksz; i++) bad_block_table[i] = -1;
}

void alloc_file(int start) {
    for (int i = start; i < start + filesz; i++) {
        if (disk[i] == -1) {
            for (int j = 0; j < sparesz; j++) {
                if (spare[j] == 0) {
                    spare[j] = 1;
                    bad_block_table[i] = dsksz + j;
                    printf("Bad block at %d, replaced by spare block %d\n", i, dsksz + j);
                    break;
                }
            }
        } else {
            disk[i] = 1;
        }
    }
}

void acc_blk(int block) {
    if (bad_block_table[block] != -1)
        printf("Accessing spare block %d (replaces bad block %d)\n", bad_block_table[block], block);
    else
        printf("Accessing block %d\n", block);
}

int main() {
    initDisk();

    disk[2] = -1;  
    disk[4] = -1;

    printf("Allocating file starting at block 0:\n");
    alloc_file(0);

    printf("\nAccessing all blocks of the file:\n");
    for (int i = 0; i < filesz; i++) {
        acc_blk(i);
    }

    return 0;
}

// SAMPLE INPUT - OUTPUT

// Allocating file starting at block 0:
// Bad block at 2, replaced by spare block 100
// Bad block at 4, replaced by spare block 101

// Accessing all blocks of the file:
// Accessing block 0
// Accessing block 1
// Accessing spare block 100 (replaces bad block 2)
// Accessing block 3
// Accessing spare block 101 (replaces bad block 4)

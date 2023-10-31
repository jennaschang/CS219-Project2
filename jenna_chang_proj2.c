/**
 * @file jenna_chang_proj2.c
 * @author Jenna Chang
 * @date 30 October 2023
 * @class CS 219.1001
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define OP 50

int getFile(FILE*, char [][OP], int32_t [], int32_t []);

int main(){

   int opCount;
   int32_t r1[OP], r2[OP], r3[OP];
   char operations[OP][OP];

   char add[OP] = "ADD";
   char and[OP] = "AND";
   char asr[OP] = "ASR";
   char lsr[OP] = "LSR";
   char lsl[OP] = "LSL";
   char not[OP] = "NOT";
   char orr[OP] = "ORR";
   char sub[OP] = "SUB";
   char xor[OP] = "XOR";

   FILE *opFile;
   opFile = fopen("Programming-Project-2.txt", "r");
   	if(opFile == NULL){
		printf("Cannot open file.\n");
		return 0;
    }
    else{
        opCount = getFile(opFile, operations, r1, r2);

        printf("%d\n", opCount);
        // Checking the contents of my arrays.
        for (int i = 0; i < opCount; i++) {
            printf("%s ", operations[i]);
            printf("%x %x\n", (unsigned int)r1[i], (unsigned int)r2[i]);
        }

        // for(int i = 0; i < opCount; i++){
        //     if(strcmp(add, operations[i+1]) == 0){
        //         r3[i] = r1[i] + r2[i];
        //         printf("%s 0x%08x 0x%08x: 0x%08x\n\n", operations[i+1], r1[i], r2[i], r3[i]);
        //     }
        //     if(strcmp(and, operations[i+1]) == 0){
        //         printf("Testing AND\n");
        //     }
        //     if(strcmp(asr, operations[i+1]) == 0){
        //         printf("Testing ASR\n");
        //     }
        //     if(strcmp(lsr, operations[i+1]) == 0){
        //         printf("Testing LSR\n");
        //     }
        //     if(strcmp(lsl, operations[i+1]) == 0){
        //         printf("Testing LSL\n");
        //     }
        //     if(strcmp(not, operations[i+1]) == 0){
        //         printf("Testing NOT\n");
        //     }
        //     if(strcmp(orr, operations[i+1]) == 0){
        //         printf("Testing ORR\n");
        //     }
        //     if(strcmp(sub, operations[i+1]) == 0){
        //         printf("Testing SUB\n");
        //     }
        //     if(strcmp(xor, operations[i+1]) == 0){
        //         printf("Testing XOR\n");
        //     }
        // }
    }
   fclose(opFile);
    return 0;
}

int getFile(FILE* opFile, char operations[][OP], int32_t opOne[], int32_t opTwo[]){
	int index = 0;
	while(fscanf(opFile, "%s", operations[index]) == 1){
        if(fscanf(opFile, "%x", &opOne[index]) == 1){
            if(fscanf(opFile, "%x", &opTwo[index]) == 1){
                index++;
            }
            else{
                index++;
            }
        }
    }
	return index;
}
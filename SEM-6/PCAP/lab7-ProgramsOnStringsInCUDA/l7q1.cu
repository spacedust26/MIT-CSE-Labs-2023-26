//Write a program in CUDA to count the number of times a given word is repeated in a sentence. (Use atomic functions)

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__  void  wordMatch(char* str,int len,char* key,int keylen,int * wordindex,int * count){
    int id = threadIdx.x;
    int i = wordindex[id];
    int j = 0;
    int match = 1;
    while(i<len && j<keylen){
        if(str[i]!=key[j]){
            match = 0;
            break;
        }
        i++;
        j++;
    }
    if(j==keylen && match){
        atomicAdd(count,1);
    }
}

int main(){
    char str[100];
    printf("Enter sentence: ");
    scanf("%[^\n]c",str);
    int len = strlen(str);
    
    char key[20];
    printf("Enter key: ");
    scanf(" %[^\n]c",key);
    int keylen = strlen(key);
 
    int wordcount=0;
    for(int i=0;i<len;i++){
        if(str[i]==' ' || i == len -1)
            wordcount++;
    }
    
    int wordindex[wordcount];
    int j=0;
    int k=1;
    wordindex[j++]=0;
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            wordindex[j++]=i+1;
            k++;
        }    
        if(k==wordcount) break;
    } 

    int count = 0;
    char * d_str, * d_key;
    int * d_count,* d_wordindex;

    cudaMalloc((void**)&d_str,len*sizeof(char));
    cudaMalloc((void**)&d_key,keylen*sizeof(char));
    cudaMalloc((void**)&d_count,sizeof(int));
    cudaMalloc((void**)&d_wordindex,wordcount*sizeof(int));

    cudaMemcpy(d_str,str,len*sizeof(char),cudaMemcpyHostToDevice);
    cudaMemcpy(d_key,key,keylen*sizeof(char),cudaMemcpyHostToDevice);
    cudaMemcpy(d_wordindex,wordindex,wordcount*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_count,&count,sizeof(int),cudaMemcpyHostToDevice);

    wordMatch<<<1,wordcount>>>(d_str,len,d_key,keylen,d_wordindex,d_count);

    cudaMemcpy(&count,d_count,sizeof(int),cudaMemcpyDeviceToHost);

    printf("Occurrances: %d\n",count);

    cudaFree(d_str);
    cudaFree(d_key);
    cudaFree(d_count);
    cudaFree(d_wordindex);
    return 0;

}
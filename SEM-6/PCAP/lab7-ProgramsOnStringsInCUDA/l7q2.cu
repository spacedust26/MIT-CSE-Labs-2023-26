// Write a CUDA program that reads a string S and produces the string RS as follows:
// Input string S: PCAP Output string RS: PCAPPCAPCP

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__ void pattern(char* s,int len,char* rs){
    int gtid = threadIdx.x;
    int pos = (gtid *(2*len + (gtid-1)*-1))/2; 
    int finlen = len - gtid;
    for(int i=0;i<finlen;i++){
        rs[pos++]=s[i];
    }

}

int main(){
    char s[20];
    printf("Input string s: ");
    scanf("%s",s);

    int len = strlen(s);
    int rslen = len*(len+1)/2;
    char rs[rslen];
    char * d_s;
    char * d_rs;

    cudaMalloc((void**)&d_s,len*sizeof(char));
    cudaMalloc((void**)&d_rs,rslen*sizeof(char));

    cudaMemcpy(d_s,s,len*sizeof(char),cudaMemcpyHostToDevice);

    pattern<<<1,len>>>(d_s,len,d_rs);

    cudaMemcpy(rs,d_rs,rslen*sizeof(char),cudaMemcpyDeviceToHost);
    rs[rslen]='\0';
    printf("Output string rs: %s\n",rs);

    cudaFree(d_s);
    cudaFree(d_rs);
    return 0;
}
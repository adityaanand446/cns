#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void converttobinary(int hex[16],int bin[64])
{
    int i;

    for(i=0;i<64;i++)
    bin[i]=0;

    long int rem,count;
    for(i=0;i<16;i++){
        count=1;
        while (hex[i]>0)
        {
            rem=hex[i]%2;
            bin[(i+1)*4-count]=rem;

            hex[i]=hex[i]/2;
            count++;
        }
    }
}

int main()
{
	int input[16],key[12];
	int i,j,binval[64],count=0,a,b,c,d,prevl[32],prevr[32],expanded[48],output[48],kbinval[48],result[48],v;
	int etable[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,
					18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	printf("Give the output of previous round\n");
	for(i=0;i<16;i++)
	scanf("%x",&input[i]);
	
	printf("Give the input key for that round\n");
	for(i=0;i<12;i++)
	scanf("%x",&key[i]);
	
	converttobinary(input, binval);
	printf("64 bit input:");
	for(i=0;i<64;i++)
		printf("%d",binval[i]);
	printf("\n");
	count=0;
	
	converttobinary(key, kbinval);
	printf("48 bit key:");
	for(i=0;i<48;i++)
		printf("%d",kbinval[i]);
	printf("\n");
	
	for(i=0;i<32;i++)
		prevl[i]=binval[i];
		
	for(i=0;i<32;i++)
		prevr[i]=binval[32+i];
		
	printf("32 bit right input:");
	for(i=0;i<32;i++)
		printf("%d",prevr[i]);
	printf("\n");
	
	for(i=0;i<48;i++)
		expanded[i]=prevr[etable[i]-1];
	
	printf("48 bit expanded right:");
	for(i=0;i<48;i++)
		printf("%d",expanded[i]);
	printf("\n");
	for(i=0;i<48;i++)
	{
		result[i]=expanded[i]^kbinval[i];
	}
	
	printf("48 bit result:");
	for(i=0;i<48;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n");
	printf("Output:");
		for(j=0;j<48;j=j+4)
		{
			v=result[j]*8+result[j+1]*4+result[j+2]*2+result[j+3]*1;
			printf("%x",v);	
		}
		
	printf("\n");
	
	return 0;
}
	
/*
	
input:

output of i-1 th round: c c 0 0 c c f f f 0 a a f 0 a a
key for i th round    : 1 b 0 2 e f f c 7 0 7 2 

output:

input to s-box of i th round: 6117ba866527

*/


	
	
	

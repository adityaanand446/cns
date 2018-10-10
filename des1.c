#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void shiftit(int a[28],int value)
{
	int t[28],k=0,j=0,i;
	for(i=0;i<value;i++)
		t[i]=a[i];
	for(i=value;i<28;i++)
		a[k++]=a[i];
	for(i=k;i<28;i++)
		a[i]=t[j++];
}
void converttobinary(int hex[16],int bin[64])
{
    int i;

    for(i=0;i<64;i++)
    	bin[i]=0;

    long int rem,count;
    for(i=0;i<16;i++)
    {
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
	int i,j,v;
	int key[16];
	int binval[64],count=0,permuetd1[56];
	int a,b,c,d;int left28[28],right28[28],unionarr[56],finalkey[48];
	int leftshift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	int pc2[48]=		{14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	int pc1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
	
	printf("enter key\n");
	for(i=0;i<16;i++)
	scanf("%x",&key[i]);

	converttobinary( key, binval);
	printf("Biary representation:\n");
	for(i=0;i<count;i++)
		printf("%d",binval[i]);
	printf("\n");
	for(i=0;i<56;i++)
		permuetd1[i]=binval[pc1[i]-1];
	
	printf("After applying permuted choice 1:\n");
	for(i=0;i<56;i++)
		printf("%d",permuetd1[i]);
	printf("\n");
	
	for(i=0;i<28;i++)
		left28[i]=permuetd1[i];
	
	for(i=0;i<28;i++)
		right28[i]=permuetd1[i+28];
	for(i=0;i<16;i++)
	{
		printf("Round %d:\n",i+1);
		
		shiftit(left28,leftshift[i]);
		shiftit(right28,leftshift[i]);
		
		for(j=0;j<28;j++)
			unionarr[j]=left28[j];
		for(j=0;j<28;j++)
			unionarr[28+j]=right28[j];
		
		for(j=0;j<48;j++)
			finalkey[j]=unionarr[pc2[j]-1];
			
		printf("Key:");
		for(j=0;j<48;j=j+4)
		{
			v=finalkey[j]*8+finalkey[j+1]*4+finalkey[j+2]*2+finalkey[j+3]*1;
			printf("%x",v);
			
		}
		printf("\n");
	}
	return 0;
}

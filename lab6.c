#include<stdio.h>
void etable(int er[48],int r[32],int e_bit[8][6])
{
	int i,j,k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			er[k++]=r[e_bit[i][j]-1];
		}
	}
}
void xor48(int er[48],int pc2_key[48])
{
	int i;
	for(i=0;i<48;i++)
	{
		if(er[i]==pc2_key[i])
			er[i]=0;
		else
			er[i]=1;
	}
}
void main()
{
	int i,j,k=0;
	int l[32],r[32],er[48],pt[64];
	int pc2_key[48]={
			0,0,0,1,1,0,1,
			1,0,0,0,0,0,0,
			1,0,1,1,1,0,1,
			1,1,1,1,1,1,1,
			1,1,0,0,0,1,1,
			1,0,0,0,0,0,1,
			1,1,0,0,1,0
			};
	int e_bit[8][6]={
			32,1,2,3,4,5,
			4,5,6,7,8,9,
			8,9,10,11,12,13,
			12,13,14,15,16,17,
			16,17,18,19,20,21,
			20,21,22,23,24,25,
			24,25,26,27,28,29,
			28,29,30,31,32,1
			};
	printf("Enter the 64 bit input :\n");
	for(i=0;i<64;i++)	
		scanf("%d",&pt[i]);
	for(i=0;i<32;i++)
		l[i]=pt[i];
	for(j=i;j<64;j++)
		r[k++]=pt[j];
	etable(er,r,e_bit);
	printf("\n after E-Table\n");
	for(i=0;i<48;i++)
		printf("%d",er[i]);
	printf("\n");
	xor48(er,pc2_key);
	printf("\n after XOR-48:\n");
	for(i=0;i<48;i++)
		printf("%d",er[i]);
	printf("\n");
}

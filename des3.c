#include<stdio.h>

int sbox[32],sbp[32],s[8][6],si=0,l[32],li[8],r[32],er[48],eri[12],v;
int sbox_table[8][4][16]={
                    14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
                    0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
                    4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
                    15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,
                    15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9,
                    10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,
                    7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
                    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
                    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
                    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14,
                    2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
                    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
                    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
                    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,
                    12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
                    10,15,4,2,7,12,9,5,6,1,12,14,0,11,3,8,
                    9,14,15,5,2,8,12,3,7,0,4,10,1,12,11,6,
                    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,
                    4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
                    13,0,11,7,4,9,1,10,14,3,4,12,2,15,8,6,
                    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
                    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,
                    13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
                    1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
                    7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
                    2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
                    };

int ptable[8][4]={
                    16,7,20,21,29,12,28,17,
                    1,15,23,26,5,18,31,10,
                    2,8,24,14,32,27,3,9,
                    19,13,30,6,22,11,4,25
                    };


void sbpermute()
{
    int i,j,k=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<4;j++)
        {
            sbp[k++]=sbox[ptable[i][j]-1];
        }
    }
}
void xor32()
{
    int i;
    for(i=0;i<32;i++)
    {
        if(l[i]==sbp[i])
            r[i]=0;
        else
            r[i]=1;
    }
}

void dec_bin(int n)
{
    int a[4],i=3,j,rem=0;
    for(j=0;j<4;j++)
        a[j]=0;
    while(n!=0)
    {
        a[i]=n%2;
        i--;
        n/=2;
    }

    for(j=0;j<4;j++)
    {
        sbox[si++]=a[j];
    }

}


void sboxf()
{
    printf("\nAfter grouping 6 bits for S box\n");
    int i,j,k=0,row,col;
    for(i=0;i<8;i++)
    {
        for(j=0;j<6;j++)
        {
            s[i][j]=er[k++];
        }
    }
   

    k=0;

    for(i=0;i<8;i++)
    {
        row=(s[i][0]*2)+s[i][5];
        col=(s[i][1]*8)+(s[i][2]*4)+(s[i][3]*2)+s[i][4];
        dec_bin(sbox_table[k++][row][col]);
    }

}


void converttobinary1(int *hex,int *bin)
{
    int i;

    for(i=0;i<48;i++)
    bin[i]=0;

    long int rem,count;
    for(i=0;i<12;i++){
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
void converttobinary2(int *hex,int *bin)
{
    int i;

    for(i=0;i<32;i++)
    bin[i]=0;

    long int rem,count;
    for(i=0;i<8;i++){
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
void main()
{
    int i,j;
    printf("enter sbox input\n");
    for(i=0;i<12;i++)
        scanf("%x",&eri[i]);
    converttobinary1( eri,er);
    
    printf("\ninput for sbox\n");
    for(i=0;i<48;i++)
        printf("%d",er[i]);
    
    printf("\nEnter li\n");
     for(i=0;i<8;i++)
    scanf("%x",&li[i]);
        
    converttobinary2(li,l);
    printf("\nleft 32 bits of input\n");
  	for(i=0;i<32;i++)
    	printf("%d",l[i]);

    sboxf();
    sbpermute();
    xor32();
    
    printf("\nAfter xor-32\n");
    for(j=0;j<32;j=j+4)
    {
    	v=r[j]*8+r[j+1]*4+r[j+2]*2+r[j+3]*1;
        printf("%x",v);
    }
    
    printf("\n");
}



/* sample ip:

input to s:
	6 1 1 7 b a 8 6 6 5 2 7
	
l i-1 : c c 0 0 c c f f 

output:
	e f 4 a 6 5 4 4
	
*/

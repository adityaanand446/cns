#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char plaintext[100],ciphertext[100],matrix[100][100];
	int pllen,ciphlen=0,keylen,i,j,k,m=0,key[100],col,count,b;
	double rows;
	printf("Enter plaintext\n");
	scanf("%s",plaintext);
	
	printf("Enter keylength\n");
	scanf("%d",&keylen);
	
	printf("Enter key\n");								
	for(i=0;i<keylen;i++)
	scanf("%d",&key[i]);
	
	pllen=strlen(plaintext);
	rows=ceil((double)pllen/keylen);
	
	count=pllen;
	while(count!=(keylen*rows))
	{
		plaintext[count]='x';
		count++;
	}
	for(i=0;i<rows;i++)
		for(j=0;j<keylen;j++)
			matrix[i][j]=plaintext[m++];
	
	for(i=1;i<=keylen;i++)
	{
		for(j=0;j<keylen;j++)
		{
			if(key[j]==i)
			{
				col=j;
				break;
			}
		}
		for(k=0;k<rows;k++)
			ciphertext[ciphlen++]=matrix[k][j];
	}
	printf("\nTraspostion matrix:\n");
	for(i=0;i<keylen;i++)
		printf("%d ",key[i]);
	printf("\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<keylen;j++)
			printf("%c ",matrix[i][j]);
		printf("\n");
	}
	printf("Encryption:\n\tCiphertext:");
	for(i=0;i<ciphlen;i++)
	{
		printf("%c",ciphertext[i]);
	}
	printf("\n");
	m=0;b=0;
	for(i=1;i<=keylen;i++)
	{
		for(j=0;j<keylen;j++)
		{
			if(i==key[j])
			{
				col=j;
				break;
			}
		}
		for(k=0;k<rows;k++)
			matrix[k][j]=ciphertext[m++];
	}
	for(i=0;i<rows;i++)
		for(j=0;j<keylen;j++)
			plaintext[b++]=matrix[i][j];
	
	printf("Decryption:\n\tPlaintext :");
	
	for(i=0;i<pllen;i++)
		printf("%c",plaintext[i]);
	printf("\n");
}

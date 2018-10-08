#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randomno()
{
	int a=rand()%26;
	return a;
}

int main()
{
	FILE *fp1,*fp2;
	char plain[100],plain1[100],cipher[100];
	char chars[26]={'0'},t;
	int i,j,k,f=1;
	float sum=0,count[26]={0};
	srand(time(NULL));
	fp1=fopen("plaintext.txt","r");
	fp2=fopen("ciphertext.txt","w");
	if(fp1==NULL || fp2==NULL)
	{
		printf("File openning error\n");
		return 0;
	}
	for(i=0;i<26;i++)
	{
		while(1)
		{
			k=randomno();
			for(j=0;j<=i-1;j++)
			{
				if(chars[j]-97==k)
				{
					f=0;
					break;
				}
			}	
			if(f==0)
			{
				f=1;
				continue;
			}
			else
			{
				chars[i]=k+97;
				break;
			}
			
		}
	}
	while(fscanf(fp1,"%c",&t)!=EOF)
	{
		sum++;
		count[t-97]++;
		fprintf(fp2,"%c",chars[t-97]);
	}
	printf("\nFrequency\tPlaintext\tCiphertext\n");
	for(i=0;i<26;i++)
	{
		printf("%4.2f\t\t%c\t\t%c\n",count[i]/sum*100,i+97,chars[i]);
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
		

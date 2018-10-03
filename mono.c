#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char pt[100],temp,c,temp1;
        int len=0,i,j,count;
        float freq;
	char key[26][2]={{'a','q'},{'b','w'},{'c','e'},{'d','r'},{'e','t'},{'f','y'},{'g','u'},{'h','i'},{'i','o'},{'j','p'},{'k','a'},{'l','s'},{'m','d'},{'n','f'},{'o','g'},
             {'p','h'},{'q','j'},{'r','k'},{'s','l'},{'t','z'},{'u','x'},{'v','c'},{'w','v'},{'x','b'},{'y','n'},{'z','m'}};
	FILE *fp1,*fp2,*fp3;
        fp1=fopen("plaintext.txt","r");
        fp2=fopen("ciphertext.txt","w");
        fp3=fopen("plaintext.txt","r");
	while((temp=fgetc(fp1))!=EOF)
    {
		for(j=0;j<26;j++)
		{
			if(temp==key[j][0])
			{ 
 		        	fputc(key[j][1],fp2);
			}
		}
	}
rewind(fp1);
fclose(fp2);
fp2=fopen("ciphertext.txt","r");
printf("\nFREQUENCY	PLAINTEXT	CIPHERTEXT\n");
	while((fgetc(fp1))!=EOF)
             len++;
rewind(fp1);
while((temp=fgetc(fp1))!=EOF)
	{
		count=0;
		freq=0;
		rewind(fp3);
		temp1=fgetc(fp2);
				while((c=fgetc(fp3))!=EOF)
					if(c==temp)
						count++;
                rewind(fp3);
		freq=(float)count/len*100;
		printf("%f		%c		%c\n",freq,temp,temp1);
	}
}

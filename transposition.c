#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int len,len1,i,j,n,c=0,n1,key1[10],key2[10],small;
char key[10],pt[50],mat[100][100],temp[10],t,ct[50];
printf("Enter the key\n");
scanf("%s",key);
len=strlen(key);
printf("Enter the plain text\n");
scanf("%s",pt);
len1=strlen(pt);
n1=len1%len;
if(n1==0)
    n=len1/len;
else
    n=(len1/len)+1;
for(i=0;i<(len-n1);i++)
    pt[len1-1+(len-n1)-i]='z'-i;
printf("%s\n",pt);
for(i=0;i<n;i++)
	for(j=0;j<len;j++)
		mat[i][j]=pt[c++];	
for(i=0;i<n;i++)
   {
        for(j=0;j<len;j++)
		{
			printf("%c ",mat[i][j]);
		}
	printf("\n");
   }
for(i=0;i<len;i++)
  temp[i]=key[i];
for(i=0;i<len;i++)
	for(j=len-1;j>i;j--)
		if(temp[j]<temp[j-1])
			{
				t=temp[j];
				temp[j]=temp[j-1];
				temp[j-1]=t;
			}
printf("%s\n",temp);
c=0;
for(i=0;i<len;i++)
	key1[i]=999;
for(i=0;i<len;i++)
	for(j=0;j<len;j++)
		if(temp[i]==key[j])
		   if(key1[j]==999)
			key1[j]=c++;
for(i=0;i<len;i++)
  printf("%d ",key1[i]);
printf("\n");
printf("Encrypted Text\n");
for(i=0;i<len;i++)
	key2[i]=key1[i];
n1=0;
for(i=0;i<len;i++)
	{
		small=99;
		for(j=0;j<len;j++)
			{
				if(key2[j]<small)
				{		
					small=key2[j];
					c=j;
				}
			}
		key2[c]=999;
		for(j=0;j<n;j++)
			{
			printf("%c",mat[j][c]);
			ct[n1++]=mat[j][c];
			}
	}		
printf("\n");

for(i=0;i<len;i++)
        key2[i]=key1[i];
n1=0;
for(i=0;i<len;i++)
        {
                small=99;
                for(j=0;j<len;j++)
                        {
                                if(key2[j]<small)
                                {
                                        small=key2[j];
                                        c=j;
                                }
                        }
                key2[c]=999;
                for(j=0;j<n;j++)
                        {
                        mat[j][c]=ct[n1++];
                        }
        }
printf("DECRYPTED TEXT\n");
for(i=0;i<n;i++)
	for(j=0;j<len;j++)
		printf("%c",mat[i][j]);
printf("\n");
}

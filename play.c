#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addtomatrix(char ch,char mat[5][5]);
void display(char mat[5][5]);
void encryption(char ptnew[],int k,char mat[5][5],char encrypt[]);
void decryption(char encrypt[],char mat[5][5]);
int main()
{
 char key[100],pt[100],mat[5][5],ch,ch1,ch2,ptnew[100],encrypt[100];
 int hash[26],i,j,k;

 for(i=0;i<26;i++)
    hash[i]=0;
printf("Enter the key\n");
gets(key);
printf("Enter the  plain text\n");
gets(pt);
printf("Either i or j will be used. Enter the character to be ignored :\n");
scanf("%c",&ch1);
hash[ch1-'a']=1;
ch2=(ch1=='i')?'j':'i';

for(i=0;pt[i]!='\0';i++)
  {
      if(ch1==pt[i])
        pt[i]=ch2;
  }


for(i=0;key[i]!='\0';i++)
 {
   if(hash[key[i]-'a']==0)
     {
       hash[key[i]-'a']=1;
       addtomatrix(key[i],mat);
     }
 }
for(i=0;i<26;i++)
 {
   if(hash[i]==0)
     addtomatrix((i+'a'),mat);
 }
printf("The matrix is :\n");
display(mat);
k=0,i=0;
while(pt[i]!='\0')
 {
   if(pt[i+1]=='\0')
     {
        ptnew[k++]=pt[i];
        ptnew[k++]='x';
        break;
     }
   else if(pt[i]==pt[i+1])
      {
      ptnew[k++]=pt[i];
      ptnew[k++]='x';
      i=i+1;
      }
   else
    {
     ptnew[k++]=pt[i];
     ptnew[k++]=pt[i+1];
     i=i+2;
    }
  }
 ptnew[k]='\0';
 printf("\nEncryption:\n");
 for(i=0;ptnew[i]!='\0';i=i+2)
    printf("%c%c ",ptnew[i],ptnew[i+1]);
  printf("\n");

 encryption(ptnew,k,mat,encrypt);

 printf("\nDecryption:\n");
 for(i=0;encrypt[i]!='\0';i=i+2)
    printf("%c%c ",encrypt[i],encrypt[i+1]);
  printf("\n");

 decryption(encrypt,mat);

return 0;
}
void addtomatrix(char ch,char mat[5][5])
{
 static int i=0,j=0;
 mat[i][j]=ch;
 j++;
 if(j==5)
  {
   j=0;
   i++;
  }
}
void display(char mat[5][5])
{
 int i,j;
 for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
   {
    printf("%c ",mat[i][j]);
   }
  printf("\n");
 }
}

void encryption(char ptnew[],int k,char mat[5][5],char encrypt[100])
{
 int i,j,l,r1,c1,r2,c2,e=0;

 for(i=0;i<k;i=i+2)
 {
     for(j=0;j<5;j++)
     {
         for(l=0;l<5;l++)
         {
             if(ptnew[i]==mat[j][l])
             {
              r1=j;
              c1=l;
             }
             if(ptnew[i+1]==mat[j][l])
             {
                 r2=j;
                 c2=l;
             }
         }
     }

     if(r1==r2)
     {
       encrypt[e++]=mat[r1][(c1+1)%5];
       encrypt[e++]=mat[r2][(c2+1)%5];
     }
     else if(c1==c2)
     {
         encrypt[e++]=mat[(r1+1)%5][c1];
         encrypt[e++]=mat[(r2+1)%5][c2];
     }
     else{
        encrypt[e++]=mat[r1][c2];
        encrypt[e++]=mat[r2][c1];
     }
 }
 encrypt[e]='\0';
 for(i=0;i<e;i=i+2)
 printf("%c%c ",encrypt[i],encrypt[i+1]);
}

void decryption(char encrypt[],char mat[5][5])
{
 int i,j,l,r1,c1,r2,c2,len,d=0,x;
 char decrypt[100];
 len=strlen(encrypt);

 for(i=0;i<len;i=i+2)
 {
     for(j=0;j<5;j++)
     {
         for(l=0;l<5;l++)
         {
             if(encrypt[i]==mat[j][l])
             {
              r1=j;
              c1=l;
             }
             if(encrypt[i+1]==mat[j][l])
             {
                 r2=j;
                 c2=l;
             }
         }
     }

     if(r1==r2)
     {
         if((c1-1)<0)
            x=5+(c1-1);
        else
            x=c1-1;
       decrypt[d++]=mat[r1][x];

       if((c2-1)<0)
            x=5+(c2-1);
        else
            x=c2-1;
       decrypt[d++]=mat[r2][x];
     }
     else if(c1==c2)
     {
         if((r1-1)<0)
            x=5+(r1-1);
        else
            x=r1-1;
         decrypt[d++]=mat[x][c1];

         if((r2-1)<0)
            x=5+(r2-1);
        else
            x=r2-1;
         decrypt[d++]=mat[x][c2];
     }
     else{
        decrypt[d++]=mat[r1][c2];
        decrypt[d++]=mat[r2][c1];
     }
 }
 decrypt[d]='\0';
 for(i=0;i<d;i=i+2)
    printf("%c%c ",decrypt[i],decrypt[i+1]);
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void encryption(int msg[100][100],int key[3][3],int cipher_mat[100][100],int len1,int order);
void decryption(int cipher_mat[100][100],int key[3][3],int order,int len1);

int main()
{
char message[100];
int order,i,j,key[3][3],count,msg[100][100],l,len,len1,cipher_mat[100][100];
printf("Enter the message\n");
gets(message);
printf("Enter the order of key :\t");
scanf("%d",&order);
printf("Enter the key\n");
for(i=0;i<order;i++)
 for(j=0;j<order;j++)
   scanf("%d",&key[i][j]);

len=strlen(message);
l=len%order;
if(l==0)
  len1=len/order;
else
  len1=(len/order)+1;

count=0;
for(i=0;i<len1;i++)
 {
  for(j=0;j<order;j++)
   {
     if(count<len)
       msg[i][j]=message[count++]-97;
     else
       msg[i][j]='x'-97;
   }
 }


printf("Encryption is :\n");
encryption(msg,key,cipher_mat,len1,order);

decryption(cipher_mat,key,order,len1);

return 0;
}

void encryption(int msg[100][100],int key[3][3],int cipher_mat[100][100],int len1,int order)
{
  int i,j,k,u=0;
  char encrypt[100];
  for(i=0;i<len1;i++)
    {
   for(j=0;j<order;j++)
     {
    for(k=0;k<order;k++)
      cipher_mat[i][j]+=msg[i][k]*key[k][j];
     }
   }
 
  for(i=0;i<len1;i++)
   {
   for(j=0;j<order;j++)
     {
      cipher_mat[i][j]=cipher_mat[i][j]%26;
      printf("%c ",cipher_mat[i][j]+97);
      encrypt[u++]=cipher_mat[i][j]+97;
     }
     printf("\n");
   }
 encrypt[u]='\0';  
}


void decryption(int cipher_mat[100][100],int key[3][3],int order,int len1)
{

int det,cc,cofac[100][100],inv_cof[100][100],i,j,k,l,u,count,decrypt_mat[100][100],temp[4];
char decrypt[100];
if(order==2)
  {
     det=(key[0][0]*key[1][1])-(key[0][1]*key[1][0]);
     printf("Determinant is : %d \n",det);
     if(det<0)
      {
        det=det*-1;
        cc=1;
       while((26*cc)<det)
           cc++;
     det=(26*cc)-det;
       }
 
	inv_cof[0][0]=key[1][1];
	inv_cof[1][1]=key[0][0];
	inv_cof[0][1]=-key[0][1];
	inv_cof[1][0]=-key[1][0];
      
        printf("Adjoint of 2*2\n");
        for(i=0;i<order;i++)
         {
          for(j=0;j<order;j++)
            printf("%d",inv_cof[i][j]);
          printf("\n");
         }
   
     printf("Inverse of determinant:\t");
     count=1;
     while((det*count)%26!=1)
        count++;
     printf("%d\n",count);
  
     for(i=0;i<order;i++)
      {
       for(j=0;j<order;j++)
         {
           if(inv_cof[i][j]<0)
             {
               inv_cof[i][j]=inv_cof[i][j]*-1;
               cc=1;
               while((26*cc) < inv_cof[i][j])
                    cc++;
               inv_cof[i][j]=(26*cc)-inv_cof[i][j];
              }
            else
               inv_cof[i][j]=inv_cof[i][j]%26;
           }
       }

    for(i=0;i<order;i++)
     {
      for(j=0;j<order;j++)
        {
          inv_cof[i][j]=inv_cof[i][j]*count;
          inv_cof[i][j]=inv_cof[i][j]%26;
          printf("%d ",inv_cof[i][j]);
        }
       printf("\n");
     }
    for(i=0;i<len1;i++)
     {
      for(j=0;j<order;j++)
        {
         for(k=0;k<order;k++)
           decrypt_mat[i][j]+=cipher_mat[i][k]*inv_cof[k][j];
        }
      }
    
     for(i=0;i<len1;i++)
      {
       for(j=0;j<order;j++)
        {
          decrypt_mat[i][j]=decrypt_mat[i][j]%26;
          printf("%c ",decrypt_mat[i][j]+97);
          decrypt[u++]=decrypt_mat[i][j]+97;
        }
      }
      printf("\n");
      decrypt[u]='\0';
    }

if(order==3)
 {
   det=key[0][0]*((key[1][1]*key[2][2])-(key[1][2]*key[2][1]));
   i=key[0][1]*((key[1][0]*key[2][2])-(key[1][2]*key[2][0]));
   j= key[0][2]*((key[1][0]*key[2][1])-(key[1][1]*key[2][0]));
   
   det = det-i+j;
    printf("Determinant is : %d \n",det);
     if(det<0)
      {
        det=det*(-1);
        cc=1;
       while((26*cc) < det)
            cc++;
      det=(26*cc)-det;
       }
      
      printf("Inverse of determinant:\t");
     count=1;
     while(((det*count)%26)!=1)
        count++;
     printf("%d\n",count);
      
 
     for(i=0;i<order;i++)
       {
        for(j=0;j<order;j++)
          {
             u=0;
            for(k=0;k<order;k++)
             {
               for(l=0;l<order;l++)
                 {
                   if((k!=i)&&(l!=j))
                       temp[u++]=key[k][l];
                  }
                }
              cofac[i][j]=(temp[0]*temp[3])-(temp[1]*temp[2]);
              if(((i+j)%2)!=0)
                 cofac[i][j]=-cofac[i][j];
          }
         }
   for(i=0;i<order;i++)
    {
      for(j=0;j<order;j++)
         inv_cof[i][j]=cofac[j][i];   //transpose
    }
    printf("Adjoint 3*3 \n");
   for(i=0;i<order;i++)
    {
      for(j=0;j<order;j++)
         printf("%d ",inv_cof[i][j]);
      printf("\n");
    }
   

      for(i=0;i<order;i++)
      {
       for(j=0;j<order;j++)
         {
           if(inv_cof[i][j]<0)
             {
               inv_cof[i][j]=inv_cof[i][j]*-1;
               cc=1;
               while((26*cc) < inv_cof[i][j])
                    cc++;
               inv_cof[i][j]=(26*cc)-inv_cof[i][j];
              }
            else
               inv_cof[i][j]=inv_cof[i][j]%26;
           }
       }

     for(i=0;i<order;i++)
     {
      for(j=0;j<order;j++)
        {
          inv_cof[i][j]=inv_cof[i][j]*count;        //mutiply with count before multiplying with adj
          inv_cof[i][j]=inv_cof[i][j]%26;
          printf("%d ",inv_cof[i][j]);
        }
       printf("\n");
     }

    for(i=0;i<len1;i++)
     {
      for(j=0;j<order;j++)
        {
         for(k=0;k<order;k++)
           decrypt_mat[i][j]+=cipher_mat[i][k]*inv_cof[k][j];
        }
      }
    
     for(i=0;i<len1;i++)
      {
       for(j=0;j<order;j++)
        {
          decrypt_mat[i][j]=decrypt_mat[i][j]%26;
          printf("%c ",decrypt_mat[i][j]+97);
          decrypt[u++]=decrypt_mat[i][j]+97;
        }
      }
      printf("\n");
      decrypt[u]='\0';
 }
}
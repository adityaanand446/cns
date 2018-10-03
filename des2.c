#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void converttobinary(int inp_ascii[64],int binarr[64],int l)
{
  int i,x,k=0,j,a[4]={0},u;
 
 for(i=0;i<l;i++)
  {
    if(inp_ascii[i]<65)
       x=inp_ascii[i]-48;
    else
      x=inp_ascii[i]-65+10;
    
    if(x==0)
       k=k+4;
   
   else
    {
    u=0;
    while(x!=0)
      {
      a[u++]=x%2;
       x=x/2;
      }
     while((u%4)!=0)
        a[u++]=0;
  
   u=u-1;
   while(u>=0)
    binarr[k++]=a[u--];
   }
  }
  
  for(i=0;i<k;i++)
    printf("%d",binarr[i]);
printf("\n");
}
void initialpermute(int binarr[64],int initial_permute[64],int up_binarr[64])
{
  int i;
  for(i=0;i<64;i++)
    up_binarr[i]=binarr[initial_permute[i]-1];
 for(i=0;i<64;i++)
    printf("%d",up_binarr[i]);
}
int main()
{
  int n,a[4]={0},i,j,binarr[64]={0},inp_ascii[64],l,after_exptable[48],right32[33];
  char input[64];
  int exp_table[48] = {32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
  int initial_permute[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,  45,37,29,21,13,5,63,55,47,39,31,23,15,7};
  int key[48]={0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,0};
  int up_binarr[64]={0},after_xor_key[48];
   
  printf("Enter the input data\n");
  scanf("%s",input);
  
  l=strlen(input);
  for(i=0;input[i]!='\0';i++)
     inp_ascii[i]=input[i];
 
  printf("\nAfter coverting into binary\n");
  converttobinary(inp_ascii,binarr,l);
  
  printf("\nAfter applying initial permutation\n");
  initialpermute(binarr,initial_permute,up_binarr);
  
  
  for(i=1;i<=32;i++)
     right32[i]=up_binarr[i+31]; 
  
 for(i=0;i<48;i++)
   after_exptable[i]=right32[exp_table[i]];
 
  printf("\nAfter expansion table\n");
  for(i=0;i<48;i++)
    printf("%d",after_exptable[i]);   
 printf("\n");    
printf("\nAfter XOR with key\n");
for(i=0;i<48;i++){
   after_xor_key[i]=after_exptable[i]^key[i];
   printf("%d",after_xor_key[i]);
 }
printf("\n");
return 0;
}

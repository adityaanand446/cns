#include<stdio.h>

int a[100]={0},b[100],i,j,len,k,flag,count=0;//generate polynomial :g(x)=x^16+x^12+x^5+1
int gp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};

void div();

int main(){
	printf("Enter the length of data frame:\n");
	scanf("%d",&len);
	printf("Enter the message: binary input with space like\n");
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	for(i=0;i<len;i++)
		b[i]=a[i];
	k=len-16;
	div();
	for(i=0;i<len;i++)
	     b[i]=b[i]^a[i];
    printf("Data to be transmitted : ");
	for(i=0;i<len;i++)
        printf("%d",b[i]);
	printf("\nWhether you wish to introduce error(1) or not(0) : ");
	scanf("%d",&flag);
	if(flag==0){
        for(i=0;i<len;i++)
		   a[i]=b[i];
	}else{
        for(i=0;i<len;i++){
            a[i]=b[i]^(rand()%2);
		}
	}
	printf("Received message is=");
	for(i=0;i<len;i++)
        printf("%d ",a[i]);
	div();
	for(i=0;i<len;i++){
        if(a[i]!=0){
            printf("\nError in recieved data\n");
            goto END;
        }
    }
   	printf("\nData recieved\n");
    END:printf("Remainder is : ");
	for(i=(len-16);i<len;i++)
        printf("%d",a[i]);
	printf("\n");
    return 0;
}

void div(){
    for(i=0;i<k;i++){
        if(a[i]==gp[0]){
            for(j=i;j<17+i;j++)
                a[j]=a[j]^gp[count++];
        }
        count=0;
    }
}

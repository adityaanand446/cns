#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define frame_length 3
#define max_no_frames 17

struct frame
{
	int seq_no;
	char data[20];
}frames[50],temp[200],t;
char s[200];

int create_frames();
void generate(int *,int);
void shuffle(int);
void frame_sort(int);

int main()
{
	int a;
	printf("\nEnter the message\n");
	scanf("%[^\n]s",s);
	a=create_frames();
	
	if(a>max_no_frames)
	{
		printf("OVERLOAD");
		return 0;
	}
	srand(time(NULL));
	shuffle(a);
	frame_sort(a);
	return 0;
}

int create_frames()
{
	int k=0,i,j;
	for(i=0;i<strlen(s);k++)
	{
		frames[k].seq_no=k;
		for(j=0;j<frame_length && s[j]!='\0';j++)
		{
			frames[k].data[j]=s[i++];
		}
	}
	for(i=0;i<k;i++)
		printf("%d---%s\n",frames[i].seq_no,frames[i].data);
		
	return k;
}

void generate(int *random_ary,int n)
{
	int r,i=0,j;
	
	while(i<n)
	{
		r=random()%n;
		for(j=0;j<i;j++)
			if(random_ary[j]==r)
				break;
				
		if(i==j)
			random_ary[i++]=r;
	}
	return;
}

void shuffle(int no_frames)
{
	int random[200];
	int i;
	generate(random,no_frames);
	
	for(i=0;i<no_frames;i++)
	{
		temp[i]=frames[random[i]];
	}
	
	printf("\nAfter shuffeling\n");
	
	for(i=0;i<no_frames;i++)
	{
		printf("%d---%s\n",temp[i].seq_no,temp[i].data);
	}
}

void frame_sort(int n)
{
	int i,j,flag=1;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(temp[j].seq_no>temp[j+1].seq_no)
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}
	
	printf("\nSorted frames\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d---%s\n",temp[i].seq_no,temp[i].data);
	}
	
	printf("\nMessage at receiver end\n");
	
	for(i=0;i<n;i++)
		printf("%s",temp[i].data);
		
	printf("\n");
}

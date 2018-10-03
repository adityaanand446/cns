#include<bits/stdc++.h>
using namespace std;
char ct[100],ln=0;
char pt1[100];
void encrypt(char matrix1[][100],int key[],int keyLen,int rows){


        for(int i=1;i<=keyLen;i++)
        {
            int loc=0;
            for(int j=0;j<keyLen;j++)
            {

                if(i==key[j])
                {
                    loc=j;
                    break;
                }

            }
            for(int k=0;k<rows;k++)
                  ct[ln++]=matrix1[k][loc];
        }
   ct[ln]='\0';
}

void decrypt(int key[],int keyLen,int rows)
{

  char matrix2[100][100],decryptMatrix[100][100];
  int j=0,k=0,ptLen=strlen(ct);

    while(j<keyLen)
    {
        for(int i=0;i<rows;i++)
        {
            matrix2[i][j]=ct[k++];

        }
        j++;

    }
    int ln=0;
    cout<<endl;
    for(int i=0;i<keyLen;i++)
    {
      j=key[i]-1;
      for(k=0;k<rows;k++)
      {
          decryptMatrix[k][i]=matrix2[k][j];

      }

    }
   cout<<endl;
   for(int l=0;l<rows;l++)
     for(int m=0;m<keyLen;m++)
    {
      cout<<decryptMatrix[l][m];

    }


}

int main()
{
    char pt[100];
    int key[100],keyLen;
    cin>>pt;

    cin>>keyLen;

    for(int i=0;i<keyLen;i++)
    {

        cin>>key[i];
    }
    int ptLen=strlen(pt);
    int chToAppend=keyLen-(ptLen%keyLen);

    if(ptLen%keyLen!=0)
    {
        while(chToAppend--)
        {

            pt[ptLen++]='X';
        }
        pt[ptLen]='\0';
    }
    cout<<pt;
    int noOfRows=strlen(pt)/keyLen;
    char tranMatrix[100][100];
    int i=0,j=0,k=0;

    cout<<endl<<noOfRows<<" "<<keyLen<<endl;

     while(k<ptLen)
    {
      if(i==noOfRows && j== keyLen ) break;

      if(j>=keyLen) {j=j%keyLen; i++;}

      tranMatrix[i][j]=pt[k];
      j++;k++;

     }
     for(int i=0;i<noOfRows;i++)
    {

        for(int j=0;j<keyLen;j++)
            cout<<tranMatrix[i][j]<<" ";
        cout<<endl;

    }

     encrypt(tranMatrix,key,keyLen,noOfRows);
     cout<<endl<<ct;
     decrypt(key,keyLen,noOfRows);
     return 0;
}

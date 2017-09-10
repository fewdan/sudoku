#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

int mat[10][10];
int ap[10];
map<string,bool>mp;

void Myprint ()
{
    for (int i=1;i<=9;i++)
    {
        for (int j=1;j<=8;j++) printf("%d ",mat[i][j]);
        printf("%d\n",mat[i][9]);
    }
}

void work ()
{
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++) scanf("%d",&mat[i][j]);
//    Myprint();cout<<"!!!!"<<endl;
    for (int i=1;i<=9;i++)
    {
        memset(ap,0,sizeof(ap));
        for (int j=1;j<=9;j++)
          ap[mat[i][j]]++;
        for (int j=1;j<=9;j++)
        {
            if (ap[j]!=1)
            {
                printf("错误发生下面矩阵的第%d行\n",i);
                Myprint();
                exit(0);
            }
        }
    }
    for (int i=1;i<=9;i++)
    {
        memset(ap,0,sizeof(ap));
        for (int j=1;j<=9;j++)
          ap[mat[j][i]]++;
        for (int j=1;j<=9;j++)
        {
            if (ap[j]!=1)
            {
                printf("错误发生下面矩阵的第%d列\n",i);
                Myprint();
                exit(0);
            }
        }
    }
    string s="";
    for (int i=1;i<=9;i++)
	  for (int j=1;j<=9;j++) s=s+char(mat[i][j]+'0');
	if (mp[s]==1)
	{
		printf("重复!!\n");
		exit(0);
	}
	mp[s]=1;
}

int main ()
{
    freopen ("sudoku.txt","r",stdin);
    int N=1000000;
    for (int i=1;i<=N;i++) work();
    printf("没有错误\n");
    return 0;
}

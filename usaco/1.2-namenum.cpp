/*
ID:sheshao1
LANG:C++
TASK:namenum
*/
#include <cstdio>
#include <cstring>
using namespace std;
char dict[500][13];
char let[28]={"22233344455566670778889990"};
int main()
{
    FILE *fin1,*fin2,*fout;
    int i,n,l;
    char name[16];
    fin1= fopen("namenum.in","r");
    fout= fopen("namenum.out","w");
    fin2= fopen("dict.txt","r");
    fscanf(fin1,"%s",&name);
    l=strlen(name);
    n=0;
    while(fscanf(fin2,"%s",&dict[n])!=EOF)
    {
        if(let[dict[n][0]-'A']!=name[0] || strlen(dict[n])!=l)
            continue;
        for(i=1;i<l;i++)
        {
            if(let[dict[n][i]-'A']!=name[i])
                break;
        }
        if(i==l)
            n++;
    }
    if(n==0)
        fprintf(fout,"NONE\n");
    else
        for(i=0;i<n;i++)
            fprintf(fout,"%s\n",dict[i]);
    return 0;
} 

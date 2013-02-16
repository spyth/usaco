/*
ID:sheshao1
LANG:C++
TASK:dualpal
*/
#include <cstdio>
using namespace std;
bool transf(int n,int b)
{
    char str[32];
    int l=0,i;
    while(n!=0)
    {
        str[l++]=n%b;
        n/=b;
    }
    for(i=0;i<l;i++)
        if(str[i]!=str[l-1-i])
            return 0;
    return  1;
}
bool check(int n)
{
    int k=2,i;
    int l=0;
    for(i=2;i<=10;i++)
    {
        if(transf(n,i))
            k--;
        if(!k)
            return 1;
    }
    return 0;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("dualpal.in","r");
    fout=fopen("dualpal.out","w");
    
    int N,S,i;
    fscanf(fin,"%d%d",&S,&N);
    for(i=1;i<=S;i++)
    {
        for(N++;;N++)
            if(check(N))
            {
                fprintf(fout,"%d\n",N);
                break;
            }
    }
    return 0;
    
} 

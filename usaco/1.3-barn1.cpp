/*
ID:sheshao1
LANG:C++
TASK:barn1
*/
//区间覆盖问题(贪心)
#include <cstdio>
#include <cstdlib>
using namespace std;
int cmp(const void *a,const void  *b)
{
    return *((int *)a)-*((int *)b);
}
int main()
{
    FILE *fin,*fout;
    fin = fopen("barn1.in","r");
    fout = fopen("barn1.out","w");
    bool stall[201]={0};
    int i,j,t;
    int M,S,C,Max,Min,counter;
    int c[201];
    fscanf(fin,"%d%d%d",&M,&S,&C);
    for(i=0,Max=-1,Min=200;i<C;i++)
    {
        fscanf(fin,"%d",&t);
        stall[t]=1;
        if(t>Max)
            Max=t;
        if(t<Min)
            Min=t;    
    }
    for(i=Min,counter=0;i<=Max;)
    {
        while(i<=Max && stall[i]==1)
            i++;
        counter++;
        j=0;
        while(i<=Max && stall[i]==0)
        {
            i++;
            j++;
        }
        if(i<=Max)
            c[counter]=j;
    }
    if(counter>M)
    {
        qsort(c+1,counter-1,sizeof(c[0]),cmp);
        for(i=1;counter-i>=M;i++)
            C+=c[i];  
    }
    fprintf(fout,"%d\n",C);
    return 0;
}

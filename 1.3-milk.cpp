/*
ID:sheshao1
LANG:C++
TASK:milk
*/
#include <cstdio>
#include <cstdlib>
using namespace std;
struct TT
{
    int price;
    int amount;    
} ;
int cmp(const void *a,const void *b)
{
    TT *c= (TT *)a;
    TT *d= (TT *)b;
    return c->price - d->price;
}
int main()
{
    FILE *fin,*fout;
    fin = fopen("milk.in","r");
    fout = fopen("milk.out","w");
    TT m[5001];
    int N,M;
    int i,ans;
    fscanf(fin,"%d%d",&N,&M);
    for(i=0;i<M;i++)
        fscanf(fin,"%d%d",&m[i].price,&m[i].amount);
    qsort(m,M,sizeof(m[0]),cmp);
    for(i=0,ans=0;N>0;i++)
    {
        if(m[i].amount>=N)
        {
            ans+=N*m[i].price;
            N=0;
        }
        else
        {
            ans+=m[i].amount*m[i].price;
            N-=m[i].amount;
        }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}

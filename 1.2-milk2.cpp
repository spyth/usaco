/*
ID:sheshao1
LANG:C++
TASK:milk2
*/

#include <cstdio>
#include <cstdlib>
using namespace std;

struct time
{
    int s;
    int e;    
};
int cmp_s(const void *a ,const void *b)
{
    time *c =(time *)a;
    time *d =(time *)b;
    return c->s - d->s;    
}
int main()
{
    FILE *fin,*fout;
    time t[5001];
    int s,e;
    int i,n;
    int curr1,curr2,work,rest;
    fin = fopen("milk2.in","r");
    fout = fopen("milk2.out","w");
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fin,"%d%d",&t[i].s,&t[i].e);
    qsort(t,n,sizeof(t[0]),cmp_s);
    curr1=t[0].e-t[0].s;
    work=curr1;
    rest=0;
    e=t[0].e;
    for(i=1;i<n;i++)
    {
        if(t[i].s <= e){
            if(t[i].e <= e)
                continue;
            curr1+=t[i].e-e;
        }
        else{
            curr1=t[i].e-t[i].s;
            curr2=t[i].s-e;
            rest=rest>curr2?rest:curr2;
        }
        e=t[i].e;
        work= work>curr1?work:curr1;
    }
    fprintf(fout,"%d %d\n",work,rest);
    return 0;
}

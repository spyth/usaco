/*
ID:sheshao1
LANG:C++
TASK:packrec
*/
#include <cstdio>
#include <cstring>
struct Rect
{
    int wid;
    int ht;
};
Rect r[4],rcd[4];
bool used[4]={0};
bool bestht[51*2]={0};
int bestarea=100000;

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

void Record(Rect r)
{
    if(r.wid*r.ht < bestarea)
    {
        bestarea=r.wid*r.ht;
        memset(bestht,0,sizeof(bestht));
        bestht[min(r.wid,r.ht)]=1;
    }
    else if(r.wid*r.ht==bestarea)
        bestht[min(r.wid,r.ht)]=1;
}
void Check(Rect *r)
{
    Rect big={0,0};
    int i;
    /*schema 1: 0123 */
    for(i=0;i<4;i++){
        big.wid+=r[i].wid;
        big.ht=max(big.ht,r[i].ht);
    }
    Record(big);
    /*schema 2: 012
                333 */
    big.wid=max(r[3].wid,r[0].wid+r[1].wid+r[2].wid);
    big.ht=max(r[0].ht,max(r[1].ht,r[2].ht))+r[3].ht;
    Record(big);
    /*schema 3: 013
                223 */
    big.wid=max(r[2].wid,r[0].wid+r[1].wid)+r[3].wid;
    big.ht=max(r[3].ht,max(r[0].ht,r[1].ht)+r[2].ht);
    Record(big);
    /*schema 4/5: 023
                  123  */
    big.wid=max(r[0].wid,r[1].wid)+r[2].wid+r[3].wid;
    big.ht=max(r[0].ht+r[1].ht,max(r[2].ht,r[3].ht));
    Record(big);
    /*schema 6: 23
                01 */
    /* 0+1 */
    big.wid=r[0].wid+r[1].wid;
    /* 1+2 */
    if(r[1].ht>r[0].ht)
        big.wid=max(big.wid,r[1].wid+r[2].wid);
    /* 0+3 */
    if(r[0].ht>r[1].ht)
        big.wid=max(big.wid,r[0].wid+r[3].wid);
    /* 2+3 */
    if(r[0].ht+r[2].ht>r[1].ht)
        big.wid=max(big.wid,r[2].wid+r[3].wid);
    /* 2 */
        big.wid=max(big.wid,r[2].wid);
    /* 3 */
        big.wid=max(big.wid,r[3].wid);
    big.ht=max(r[0].ht+r[2].ht,r[1].ht+r[3].ht);
    Record(big);
}


void Rotate(Rect *rcd,int l)
{
    if(l==4){
        Check(rcd);
        return ;
    }
    int t;
    Rotate(rcd,l+1);
    t=rcd[l].wid , rcd[l].wid=rcd[l].ht , rcd[l].ht=t;
    Rotate(rcd,l+1);
    t=rcd[l].wid , rcd[l].wid=rcd[l].ht , rcd[l].ht=t;
}
void Permute(int l)
{
    int i;
    if(l==4){
        Rotate(rcd,0);
        return ;
    }
    for(i=0;i<4;i++){
        if(!used[i]){
            used[i]=1;
            rcd[l]=r[i];
            Permute(l+1);
            used[i]=0;
        }
    }
}
/*
void Permute(Rect *r, int n)
{
    Rect t;
    int i;

    if(n == 4)
        checkrotate(r, 0);

    for(i=n; i<4; i++) {
        t = r[n], r[n] = r[i], r[i] = t;    
        checkpermute(r, n+1);
        t = r[n], r[n] = r[i], r[i] = t;    
    }
}*/

int main()
{
    FILE *fin,*fout;
    fin=fopen("packrec.in","r");
    fout=fopen("packrec.out","w");
    int i;
    for(i=0;i<4;i++)
        fscanf(fin,"%d %d",&r[i].wid,&r[i].ht);
    Permute(0);
    fprintf(fout,"%d\n",bestarea); 
    for(i=1;i<101;i++)
        if(bestht[i])
            fprintf(fout,"%d %d\n",i,bestarea/i);
    return 0;
}

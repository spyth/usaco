/*
ID:sheshao1
LANG:C++
TASK:ariprog
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
struct TT
{
	int a;
	int b;
};
TT record[10001];
int list[21048];
bool b[125001];
int cmp(const void *p,const void *q)
{
	TT *x=(TT *)p;
	TT *y=(TT *)q;
	if(x->b != y->b)
		return x->b - y->b;
	else
		return x->a - y->a;
}
int main()
{
	FILE *fin,*fout;
	int N,M;
	int i,j,l,t,t1,d,len,MAX,ans,tmp;
	fin=fopen("ariprog.in","r");
	fout=fopen("ariprog.out","w");
	fscanf(fin,"%d%d",&N,&M);
	memset(b,0,sizeof(b));
	for(i=0;i<=M;i++)
		for(j=0;j<=i;j++)
			b[i*i+j*j]=1;
	MAX=M*M*2;
	for(i=0,l=0;i<=MAX;i++)
		if(b[i])
			list[l++]=i;
    t=l-N;
	t1=t+1;
	for(i=0,ans=0;i<=t;i++){
		for(j=i+1;j<=t1;j++){
			d=list[j]-list[i];
			if((list[j]+d*(N-2))>MAX)
				break;
			tmp=list[j];
			len=2;
			while(len<N && b[tmp+d])
				len++,tmp+=d;
			if(len==N){
				record[ans].a=list[i];
				record[ans++].b=d;
			}
		}
	}
	if(ans==0){
	   fprintf(fout,"NONE\n");
    }
    else{
    	qsort(record,ans,sizeof(record[0]),cmp);
    	for(i=0;i<ans;i++)
    		fprintf(fout,"%d %d\n",record[i].a,record[i].b);
    }
	return 0;

}

/*
Executing...
   Test 1: TEST OK [0.011 secs, 3296 KB]
   Test 2: TEST OK [0.011 secs, 3296 KB]
   Test 3: TEST OK [0.000 secs, 3296 KB]
   Test 4: TEST OK [0.011 secs, 3296 KB]
   Test 5: TEST OK [0.011 secs, 3296 KB]
   Test 6: TEST OK [0.032 secs, 3296 KB]
   Test 7: TEST OK [0.205 secs, 3296 KB]
   Test 8: TEST OK [0.400 secs, 3296 KB]
   Test 9: TEST OK [0.346 secs, 3296 KB]
*/

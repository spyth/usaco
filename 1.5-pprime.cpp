/*
ID:sheshao1
LANG:C++
TASK:pprime
*/
#include<cstdio>
#include<cstring>
#include<cmath>
bool isprime[10002];
int prime[1300];
int total;
int palind[1000]={2,3,5,7,11};
int len=5;
int a,b;
int get_prime(int n)
{
	memset(isprime,1,sizeof(isprime));
	int i,j;
    total=0;
	for(i=2;i<=n;i++){
		if(isprime[i])
			prime[total++]=i;
		for(j=0;j<total && i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}
	}
	return total;
}
bool judge(int n)
{
	int i;
	for(i=0;i<total && prime[i]*prime[i]<=n;i++)
		if(n%prime[i]==0)
			return false;
	return true;
}
void get_palind()
{
	int p[]={1,3,7,9};
	int d[]={1,10,100,1000};
	int i,j,k,l,t,tmp;
	for(i=1;i<4;i++)
		for(j=0;j<4;j++){
			for(k=0,t=p[j]*d[i];k<d[i];k++,t++){
				tmp=t*d[i];
				for(l=i;l>0;l--)
					tmp+=((t/d[l])%10)*d[i-l];
				if(tmp>b)
					return ;
				if(judge(tmp))
					palind[len++]=tmp;
			}
		}

}
int main()
{
	FILE *fin,*fout;
	int i;
	fin = fopen("pprime.in","r");
	fout = fopen("pprime.out","w");
	fscanf(fin,"%d%d",&a,&b);
	get_prime(int(sqrt(double(b)))+1);	
	get_palind();
	for(i=0;i<len;i++)
		if(palind[i]>=a && palind[i]<=b)
			fprintf(fout,"%d\n",palind[i]);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 3036 KB]
   Test 2: TEST OK [0.000 secs, 3036 KB]
   Test 3: TEST OK [0.022 secs, 3036 KB]
   Test 4: TEST OK [0.000 secs, 3036 KB]
   Test 5: TEST OK [0.011 secs, 3036 KB]
   Test 6: TEST OK [0.022 secs, 3036 KB]
   Test 7: TEST OK [0.022 secs, 3036 KB]
   Test 8: TEST OK [0.011 secs, 3036 KB]
   Test 9: TEST OK [0.011 secs, 3036 KB]
*/

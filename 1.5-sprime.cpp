/*
ID:sheshao1
LANG:C++
TASK:sprime
*/
#include<cstdio>
#include<cstring>
#include<cmath>
FILE *fin,*fout;
bool isprime[10005];
int prime[1300];
int total;
int t[]={0,4,11,32,101,317,1001,3163,10001};
int N;
void get_prime(int n)
{
	int i,j;
	total=0;
	memset(isprime,1,sizeof(isprime));
	for(i=2;i<=n;i++){
		if(isprime[i])
			prime[total++]=i;
		for(j=0;j<total && i*prime[j]<=n;j++){
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}
	}
}
bool judge(int n)
{
	int i;
	for(i=0;i<total && prime[i]*prime[i]<=n;i++)
		if(n%prime[i]==0)
			return 0;
	return 1;
}
int fd[]={2,3,5,7};/*first digit*/
int d[]={1,3,5,7,9};
void superprime(int m,int p)
{
	if(m==N){
		fprintf(fout,"%d\n",p);
		return ;
	}
	int i,pr;
	for(p*=10,i=0,m++;i<5;i++){
		pr=p+d[i];
		if(judge(pr))
			superprime(m,pr);
	}
}
int main()
{
	int i;
	fin=fopen("sprime.in","r");
	fout=fopen("sprime.out","w");
	fscanf(fin,"%d",&N);
	get_prime(t[N]);
	for(i=0;i<4;i++)
		superprime(1,fd[i]);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 3032 KB]
   Test 2: TEST OK [0.000 secs, 3032 KB]
   Test 3: TEST OK [0.011 secs, 3032 KB]
   Test 4: TEST OK [0.011 secs, 3032 KB]
   Test 5: TEST OK [0.011 secs, 3032 KB]
*/

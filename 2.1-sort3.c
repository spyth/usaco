/*
ID:sheshao1
LANG:C
TASK:sort3
*/
#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fin,*fout;
	int a[1005],b[4][4];
	int N,i,j,k,t,ans;
	fin = fopen("sort3.in","r");
	fout = fopen("sort3.out","w");
	fscanf(fin,"%d",&N);
	memset(b,0,sizeof(b));
	for(i=0;i<N;i++){
		fscanf(fin,"%d",a+i);
		b[0][a[i]]++;
	}
	for(i=1,j=0;i<4;i++,j+=b[0][i-1])
		for(k=0;k<b[0][i];k++)
			b[i][a[j+k]]++;
	t=b[1][2]>b[2][1]?b[2][1]:b[1][2];
	b[1][2]-=t;
	ans=t;
	t=b[1][3]>b[3][1]?b[3][1]:b[1][3];
	b[1][3]-=t;
	ans+=t;
	ans+=b[2][3]>b[3][2]?b[3][2]:b[2][3];
	ans+=b[1][2]*2;
	ans+=b[1][3]*2;
	fprintf(fout,"%d\n",ans);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 1968 KB]
   Test 2: TEST OK [0.000 secs, 1968 KB]
   Test 3: TEST OK [0.000 secs, 1968 KB]
   Test 4: TEST OK [0.000 secs, 1968 KB]
   Test 5: TEST OK [0.000 secs, 1968 KB]
   Test 6: TEST OK [0.000 secs, 1968 KB]
   Test 7: TEST OK [0.000 secs, 1968 KB]
   Test 8: TEST OK [0.000 secs, 1968 KB]
*/

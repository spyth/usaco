/*
ID:sheshao1
LANG:C
TASK:subset
*/

#include <stdio.h>
int main()
{
	FILE *fin = fopen("subset.in","r");
	FILE *fout = fopen("subset.out","w");
	unsigned int f[40][400]={0};
	int n;
	fscanf(fin,"%d",&n);
	
	int sum = n * ( n + 1 );
	if((sum & 3 )!= 0){
		fprintf(fout,"0\n");
		return 0;
	}
	sum >>= 2;
	int i,j,m;
	for(i=0;i<=n;i++)
		f[i][0] = 1;
	for(i=1;i<=n;i++)
	{
		m = (i * (i+1)) >> 1 ;
		for(j=1;j<=m && j<=sum;j++)
		{
			if(i<=j)
				f[i][j] = f[i-1][j] + f[i-1][j-i];
			else
				f[i][j] = f[i-1][j];
		}
	}
	fprintf(fout,"%u\n",f[n][sum]>>1);
	return 0;
}

/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 2124 KB]
   Test 2: TEST OK [0.000 secs, 2124 KB]
   Test 3: TEST OK [0.000 secs, 2124 KB]
   Test 4: TEST OK [0.000 secs, 2124 KB]
   Test 5: TEST OK [0.000 secs, 2124 KB]
   Test 6: TEST OK [0.000 secs, 2124 KB]
   Test 7: TEST OK [0.000 secs, 2124 KB]

All tests OK.
*/

/*
ID:sheshao1
TASK:hamming
LANG:C
*/
#include <stdio.h>
#define m1 0x55555555
#define m2 0x33333333
#define m4 0x0f0f0f0f
int distance (int x);
int main()
{
	FILE *fin = fopen("hamming.in","r");
	FILE *fout = fopen("hamming.out","w");
	int N,B,D;
	int MaxV;
	int i,j,len;
	int res[65];
	fscanf(fin,"%d%d%d",&N,&B,&D);
	res[0] = 0;
	len = 1;
	MaxV = 1<<B;
	for(i=1;len<N && i<MaxV;i++)
	{
		for(j=0;j<len;j++){
			if(distance(i^res[j]) < D)
				break;
		}
		if(j == len){
			res[j] = i;
			len ++;
		}
	}
	/*Output the result*/
	for(i=0;i<len-1;i++){
		fprintf(fout,"%d",res[i]);
		if((i+1)%10 == 0)
			fprintf(fout,"\n");
		else
			fprintf(fout," ");
	}
	fprintf(fout,"%d\n",res[i]);
	return 0;
}
/*Count the hamming distance*/
int distance(int x)
{
	x = (x & m1 ) + ((x >>  1) & m1 ); 
	x = (x & m2 ) + ((x >>  2) & m2 );  
	x = (x & m4 ) + ((x >>  4) & m4 );  
	return x;
}

/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 1944 KB]
   Test 2: TEST OK [0.000 secs, 1944 KB]
   Test 3: TEST OK [0.000 secs, 1944 KB]
   Test 4: TEST OK [0.000 secs, 1944 KB]
   Test 5: TEST OK [0.000 secs, 1944 KB]
   Test 6: TEST OK [0.000 secs, 1944 KB]
   Test 7: TEST OK [0.000 secs, 1944 KB]
   Test 8: TEST OK [0.000 secs, 1944 KB]
   Test 9: TEST OK [0.000 secs, 1944 KB]
   Test 10: TEST OK [0.000 secs, 1944 KB]
   Test 11: TEST OK [0.000 secs, 1944 KB]

All tests OK.
*/

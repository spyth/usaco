/*
ID:sheshao1
LANG:C++
TASK:frac1
*/
#include <cstdio>

FILE *fin,*fout;
int N;
void show (int num_l,int den_l,int num_r,int den_r)
{
    int den_m = den_l + den_r;
	if(den_m > N)
		return ;	
	int num_m = num_l + num_r;
	show(num_l,den_l,num_m,den_m);
	fprintf(fout,"%d/%d\n",num_m,den_m);
	show(num_m,den_m,num_r,den_r);
}
int main()
{
	fin = fopen("frac1.in","r");
	fout = fopen("frac1.out","w");
	fscanf(fin,"%d",&N);
	fprintf(fout,"0/1\n");
	show(0,1,1,1);
	fprintf(fout,"1/1\n");
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 3028 KB]
   Test 2: TEST OK [0.000 secs, 3028 KB]
   Test 3: TEST OK [0.000 secs, 3028 KB]
   Test 4: TEST OK [0.000 secs, 3028 KB]
   Test 5: TEST OK [0.000 secs, 3028 KB]
   Test 6: TEST OK [0.000 secs, 3028 KB]
   Test 7: TEST OK [0.000 secs, 3028 KB]
   Test 8: TEST OK [0.000 secs, 3028 KB]
   Test 9: TEST OK [0.000 secs, 3028 KB]
   Test 10: TEST OK [0.000 secs, 3028 KB]
   Test 11: TEST OK [0.000 secs, 3028 KB]
*/

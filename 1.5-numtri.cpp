/*
ID:sheshao1
LANG:C++
TASK:numtri
*/
#include<cstdio>
int tri[500501];
int main()
{
	FILE *fin,*fout;
	int i,j,R,n;
	fin=fopen("numtri.in","r");
	fout=fopen("numtri.out","w");
	fscanf(fin,"%d",&R);
	n=(R*(R+1))>>1;
	for(i=0;i<n;i++)
		fscanf(fin,"%d",&tri[i]);
	for(i=n-R-1,j=1;i>=0;i--,j++){
		tri[i]+=(tri[i+R-1]>tri[i+R]?tri[i+R-1]:tri[i+R]);
		if(j==R-1)
			j=0,R--;
	}
	fprintf(fout,"%d\n",tri[0]);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4968 KB]
   Test 2: TEST OK [0.011 secs, 4968 KB]
   Test 3: TEST OK [0.000 secs, 4968 KB]
   Test 4: TEST OK [0.011 secs, 4968 KB]
   Test 5: TEST OK [0.000 secs, 4968 KB]
   Test 6: TEST OK [0.011 secs, 4968 KB]
   Test 7: TEST OK [0.054 secs, 4968 KB]
   Test 8: TEST OK [0.011 secs, 4968 KB]
   Test 9: TEST OK [0.238 secs, 4968 KB]
*/

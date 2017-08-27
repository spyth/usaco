/*
ID:sheshao1
LANG:C
TASK:preface
*/
#include <stdio.h>
int main()
{
	FILE *fin = fopen("preface.in","r");
	FILE *fout = fopen("preface.out","w");
	int n;
	int i, j, num, tmp;
	char letter[10] = {'I','V','X','L','C','D','M'};
	int sta[10]={0};
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		num=i;
		for(j=0,tmp=num%10;num > 0;j+=2)
		{
			if(tmp<=3)
				sta[j]+=tmp;
			else if(tmp==4){
				sta[j+1]++;
				sta[j]++;
			}
			else if(tmp==9){
				sta[j+2]++;
				sta[j]++;
			}
			else{
				sta[j+1]++;
				sta[j]+=tmp-5;
			}
			num/=10;
			tmp=num%10;
		}
	}
	for(i=0;i<7;i++)
	{
		if(sta[i]){
			fprintf(fout,"%c %d\n",letter[i],sta[i]);
		}
	}
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
   Test 8: TEST OK [0.000 secs, 2124 KB]

All tests OK.
*/

/*
ID:sheshao1
LANG:C
TASK:holstein
*/
#include <stdio.h>

int dig[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int req[26],rec[26];
int type[16][26];
int V,G,m,ans;
void dfs(int r,int dep,int next);
int main()
{
	FILE *fin,*fout;
	int i,j;
	fin = fopen("holstein.in","r");
	fout = fopen("holstein.out","w");
	/* 1<=V<=25 */
	fscanf(fin,"%d",&V);
	for(i=0;i<V;i++)
		fscanf(fin,"%d",&req[i]);
	/* 1<=G<=15*/
	fscanf(fin,"%d",&G);
	for(i=G-1;i>=0;i--)
		for(j=0;j<V;j++)
			fscanf(fin,"%d",&type[i][j]);
	m=20;
	for(i=G-1;i>=0 && m>1;i--){
		for(j=0;j<V;j++)
			rec[j]=type[i][j];
		dfs(dig[i],1,i-1);
	}
	fprintf(fout,"%d ",m);
	for(i=1;i<=G,m;i++){
	    if(ans & dig[G-i]){
            m--;
            if(m)
                fprintf(fout,"%d ",i);
            else
                fprintf(fout,"%d\n",i);
        }
    }
    return 0;
}
void dfs(int r,int dep,int next)
{
	int i,j;
	for(i=0;i<V;i++)
		if(rec[i]<req[i])
			break;
	if(i==V){
		m=dep;
		ans=r;
		return ;
	}
	for(i=next,dep++;i>=0 && dep<m;i--)
	{
		for(j=0;j<V;j++)
			rec[j]+=type[i][j];
		dfs(r+dig[i],dep,i-1);
		for(j=0;j<V;j++)
			rec[j]-=type[i][j];

	}
}
/*
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 1976 KB]
   Test 2: TEST OK [0.000 secs, 1976 KB]
   Test 3: TEST OK [0.000 secs, 1976 KB]
   Test 4: TEST OK [0.000 secs, 1976 KB]
   Test 5: TEST OK [0.000 secs, 1976 KB]
   Test 6: TEST OK [0.000 secs, 1976 KB]
   Test 7: TEST OK [0.000 secs, 1976 KB]
   Test 8: TEST OK [0.000 secs, 1976 KB]
   Test 9: TEST OK [0.000 secs, 1976 KB]
   Test 10: TEST OK [0.000 secs, 1976 KB]

All tests OK.
*/
/*
Executing...
   Test 1: TEST OK [0.011 secs, 3020 KB]
   Test 2: TEST OK [0.000 secs, 3020 KB]
   Test 3: TEST OK [0.011 secs, 3020 KB]
   Test 4: TEST OK [0.011 secs, 3020 KB]
   Test 5: TEST OK [0.022 secs, 3020 KB]
   Test 6: TEST OK [0.000 secs, 3020 KB]
   Test 7: TEST OK [0.000 secs, 3020 KB]
   Test 8: TEST OK [0.011 secs, 3020 KB]
   Test 9: TEST OK [0.011 secs, 3020 KB]
*/
/*
ID: sheshao1
LANG:C++
TASK:clocks
*/
#include <cstdio>
const int set = 57521883;
const int move[9] = {18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
FILE *fin,*fout;
int ans,len;
void record(int p,int l)
{
    if(l<len){
        ans=p;
        len=l;
    }
    else if(l==len && p>ans)
        ans=p;
}
void dfs(int f,int p,int l,int s)
{
    if(l>len)
        return;
    if(s>8){
        if(f==0)
			record(p,l);
        return ;
    }
    int j,pt,ft;
	for(j=0;j<4;j++){
		ft=f+move[s]*j;
		ft&=set;
		pt=p+(1<<(16-2*s))*j;
		dfs(ft,pt,l+j,s+1);
	}      
}
int main()
{
    fin=fopen("clocks.in","r");
    fout=fopen("clocks.out","w");
    int i,j,t;
    int inp=0;
    len=28;
    for(i=8;i>=0;i--){
        fscanf(fin,"%d",&t);
        t=(t/3)%4;
        inp|=t<<(i*3);
    }
	
    dfs(inp,0,0,0);
    for(i=0,j=3<<16;i<=9;i++){
        t=(ans&j)>>(16-2*i);
        while(t--){
            fprintf(fout,"%d",i+1);
            len--;
            if(len)
                fprintf(fout," ");
            else
                fprintf(fout,"\n");
        }
        j>>=2;
    }
    return 0;
}

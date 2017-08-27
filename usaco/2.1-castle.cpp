/*
ID:sheshao1
LANG:C++
TASK:castle
*/
#include <cstdio>
#include <cstring>

int map[51][51];
int room[51][51];
int wall[]={1,2,4,8};
int dir[][2]={0,-1,-1,0,0,1,1,0};
int count[2501];
int num=0;

void FF(int i,int j)
{
	int k;
	for(k=0;k<4;k++)
		if( !(map[i][j] & wall[k]) && !room[i+dir[k][0]][j+dir[k][1]]){
			room[i+dir[k][0]][j+dir[k][1]]=num;
			count[num]++;
			FF(i+dir[k][0],j+dir[k][1]);
		}
}
int main()
{
	FILE *fin,*fout;
	int M,N;
	int i,j,x,y;
	char d;
	int ans=0,big=0;
	fin = fopen("castle.in","r");
	fout = fopen("castle.out","w");
	fscanf(fin,"%d%d",&M,&N);
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			fscanf(fin,"%d",&map[i][j]);
	memset(room,0,sizeof(room));
	memset(count,0,sizeof(count));
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(!room[i][j]){
				num++;
				room[i][j]=num;
				count[num]++;
				FF(i,j);
				if(count[num]>big)
					big=count[num];
			}
	for(i=0;i<M;i++)
		for(j=N-1;j>=0;j--){
			if(j!=0 && (room[j][i] != room[j-1][i]) && (count[room[j][i]]+count[room[j-1][i]] >ans)){
				ans=count[room[j][i]]+count[room[j-1][i]];
				x=j,y=i;
				d='N';
			}
			if(i!=M-1 && (room[j][i] != room[j][i+1]) && (count[room[j][i]]+count[room[j][i+1]] >ans)){
				ans = count[room[j][i]] + count[room[j][i+1]];	
				x=j,y=i;
				d='E';
			}
		}
	fprintf(fout,"%d\n%d\n%d\n",num,big,ans);
	fprintf(fout,"%d %d %c\n",x+1,y+1,d);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 3056 KB]
   Test 2: TEST OK [0.000 secs, 3056 KB]
   Test 3: TEST OK [0.000 secs, 3056 KB]
   Test 4: TEST OK [0.000 secs, 3056 KB]
   Test 5: TEST OK [0.000 secs, 3056 KB]
   Test 6: TEST OK [0.000 secs, 3056 KB]
   Test 7: TEST OK [0.000 secs, 3056 KB]
   Test 8: TEST OK [0.000 secs, 3056 KB]
*/

/*
ID:sheshao1
LANG:C++
TASK:milk3
*/
#include <cstdio>
#include <cstring>
struct TT
{
	int s[3];
};
TT C;
int n;
bool record[21];
void bfs()
{
	TT tmp={0,0,C.s[2]};
	bool visited[21][21][21]={0};
	int step[][2]={{0,1},{1,0},{1,2},{2,1},{0,2},{2,0}};
	TT q[1000];
	int front,rear,i;
	
	front=rear=0;
	visited[tmp.s[0]][tmp.s[1]][tmp.s[2]]=1;
	q[rear++]=tmp;
	while(front<rear)
	{
		tmp=q[front];
		if(tmp.s[0]==0 && !record[tmp.s[2]]){
				record[tmp.s[2]]=1;
				n++;
		}
		for(i=0;i<6;i++)
		{	
            if(tmp.s[step[i][0]]>0 && tmp.s[step[i][1]]<C.s[step[i][1]]){
                /*µ¹Âú*/ 
				if(tmp.s[step[i][0]]>C.s[step[i][1]]-tmp.s[step[i][1]]){
					tmp.s[step[i][0]]-=C.s[step[i][1]]-tmp.s[step[i][1]];
					tmp.s[step[i][1]]=C.s[step[i][1]];
				}
				/*µ¹¿Õ*/ 
				else{
					tmp.s[step[i][1]]+=tmp.s[step[i][0]];
					tmp.s[step[i][0]]=0;
				}
				if(!visited[tmp.s[0]][tmp.s[1]][tmp.s[2]]){
                    visited[tmp.s[0]][tmp.s[1]][tmp.s[2]]=1;
					q[rear++]=tmp;
                }
				tmp=q[front];
            }
		}
		front++;
	}
} 
int main()
{
	FILE *fin,*fout;
	int i;
	fin=fopen("milk3.in","r");
	fout=fopen("milk3.out","w");
	fscanf(fin,"%d%d%d",&C.s[0],&C.s[1],&C.s[2]);
	memset(record,0,sizeof(record));
	n=-1;
	bfs();
	for(i=0;i<21;i++)
	{
		if(record[i]){
			fprintf(fout,"%d",i);
			if(n){
				fprintf(fout," ");
				n--;
            }
			else
				fprintf(fout,"\n");
        }
	}
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 3020 KB]
   Test 2: TEST OK [0.022 secs, 3020 KB]
   Test 3: TEST OK [0.000 secs, 3020 KB]
   Test 4: TEST OK [0.000 secs, 3020 KB]
   Test 5: TEST OK [0.000 secs, 3020 KB]
   Test 6: TEST OK [0.000 secs, 3020 KB]
   Test 7: TEST OK [0.000 secs, 3020 KB]
   Test 8: TEST OK [0.000 secs, 3020 KB]
   Test 9: TEST OK [0.000 secs, 3020 KB]
   Test 10: TEST OK [0.011 secs, 3020 KB]
   */

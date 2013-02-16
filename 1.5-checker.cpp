/*
ID:sheshao1
LANG:C++
TASK:checker
*/
#include<cstdio>
#include<cstring>
int ans[3][15];
bool diag_en[51];
bool col_en[15];
int p[15];
int count,N,M;
void placequeue(int row)
{
	if(row==N){
		if(count<3){
			int i;
			for(i=1;i<=N;i++)
				ans[count][i]=p[i];
		}
		count++;
		return ;
	}
	int col;
	row++;
	for(col=1;col<=N;col++){
		if(col_en[col] && diag_en[row+col-1] && diag_en[row-col+M]){
			col_en[col]=0;
			diag_en[row+col-1]=0;
			diag_en[row-col+M]=0;
			p[row]=col;
			placequeue(row);
			col_en[col]=1;
			diag_en[row+col-1]=1;
			diag_en[row-col+M]=1;
		}
	}
}
int main()
{
	FILE *fin,*fout;
	int col,t,tmp,res;
	fin=fopen("checker.in","r");
	fout=fopen("checker.out","w");
	fscanf(fin,"%d",&N);
	t=(N+1)>>1;
	M=3*N-1;
	memset(diag_en,1,sizeof(diag_en));
	memset(col_en,1,sizeof(col_en));
	count=0;
	for(col=1;col<=t;col++){
		col_en[col]=0;
		diag_en[col]=0;
		diag_en[M+1-col]=0;
		p[1]=col;
		placequeue(1);
		col_en[col]=1;
		diag_en[col]=1;
		diag_en[M+1-col]=1;
		if(col==t-1 && N&1){
			tmp=count;
		}
	}
	if(N&1)
		res=count+tmp;
	else
		res=count<<1;
	if(count<3){
        for(col=1;col<=N;col++)
            ans[count][col]=N+1-ans[count-1][col];
        count++;
    }
	for(t=0;t<3;t++){
		for(col=1;col<N;col++)
			fprintf(fout,"%d ",ans[t][col]);
		fprintf(fout,"%d\n",ans[t][col]);
	}
	fprintf(fout,"%d\n",res);
	fclose(fin);
	fclose(fout);
	return 0;
}

/*
Executing...
   Test 1: TEST OK [0.000 secs, 3020 KB]
   Test 2: TEST OK [0.000 secs, 3020 KB]
   Test 3: TEST OK [0.000 secs, 3020 KB]
   Test 4: TEST OK [0.000 secs, 3020 KB]
   Test 5: TEST OK [0.000 secs, 3020 KB]
   Test 6: TEST OK [0.000 secs, 3020 KB]
   Test 7: TEST OK [0.081 secs, 3020 KB]
   Test 8: TEST OK [0.513 secs, 3020 KB]
*/

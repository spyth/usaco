/*
ID:sheshao1
LANG:C++
TASK:transform
*/
#include<cstdio>
#include<cstring>
using namespace std;

void trans_90(char in[],char out[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            out[i*n+j]=in[n*(n-1-j)+i];
    out[n*n]=in[n*n];
}
void trans_mirror(char in[],char out[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            out[i*n+j]=in[(i+1)*n-j-1];
    out[n*n]=in[n*n];
}
int check(char org[],char tar[],int n)
{
    int i;
    char str1[101],str2[101];
    strcpy(str1,org);
    for(i=1;i<4;i++)
    {
        trans_90(str1,str2,n);
        if(strcmp(str2,tar)==0)
            return i;
        strcpy(str1,str2);
    }
    trans_mirror(org,str1,n); 
    if(strcmp(str1,tar)==0)
        return i;
    for(i=1;i<4;i++)
    {
        trans_90(str1,str2,n);
        if(strcmp(str2,tar)==0)
            return 5;
        strcpy(str1,str2);
    }
    if(strcmp(org,tar)==0)
        return 6;
    return 7;
}

int main()
{
    FILE *fin,*fout;
    fin = fopen("transform.in","r");
    fout = fopen("transform.out","w");
    int N,i;
    char orginal[101],target[101];
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++)
        fscanf(fin,"%s",&orginal[i*N]);
    for(i=0;i<N;i++)
        fscanf(fin,"%s",&target[i*N]);
    fprintf(fout,"%d\n",check(orginal,target,N));
    return 0;
} 

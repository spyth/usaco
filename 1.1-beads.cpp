/*
ID: sheshao1
LANG: C++
TASK: beads
*/
#include <cstdio>
using namespace std;
int bigger(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;    
}
int main()
{
    FILE *fin= fopen("beads.in","r");
    FILE *fout =fopen("beads.out","w");
    int len,ans;
    int i,j,k;
    char str[360];
    char che[2]={'r','b'};
    int counter[2][360][3];//right,left /blue,red,max
    fscanf(fin,"%d",&len);
    fscanf(fin,"%s",&str);
    for(j=0;j<2;j++)
    {
        i=0;
        while(i<len && str[i]!=che[j])
            i++;
        counter[0][0][j]=i;
        
        i=len-1;
        while(i>=0 && str[i]!=che[j])
            i--;
        counter[1][len-1][j]=len-1-i;
    }
    counter[0][0][2]=bigger(counter[0][0][0],counter[0][0][1]);
    counter[1][len-1][2]=bigger(counter[1][len-1][0],counter[1][len-1][1]);
    for(i=1;i<len;i++)
    {
        for(j=0;j<2;j++)
        { 
            if(str[i]!= che[j])
            {
                if(str[i-1]!=che[j])
                    counter[0][i][j]=counter[0][i-1][j]-1;
                else
                {
                    k=1;
                    while(k<len && str[(i+k)%len]!=che[j])
                        k++;
                    counter[0][i][j]=k;
                }
            }
            else
                counter[0][i][j]=0;
        }
        counter[0][i][2]=bigger(counter[0][i][0],counter[0][i][1]);
    }
    ans=counter[0][0][2]+counter[1][len-1][2];
    for(i=len-2;i>=0;i--)
    {
        for(j=0;j<2;j++)
        {
            if(str[i]!=che[j])
            {
                if(str[i+1]!=che[j])
                    counter[1][i][j]= counter[1][i+1][j]-1;
                else
                {
                    k=1;
                    while(k<len && str[(i-k+len)%len]!=che[j])
                        k++;
                    counter[1][i][j]=k;    
                }
            }    
            else
                counter[1][i][j]=0;
        } 
        counter[1][i][2]=bigger(counter[1][i][0],counter[1][i][1]);
        ans=bigger(ans,counter[1][i][2]+counter[0][i+1][2]);
        if(ans>len)
        {
            ans=len;
            break;
        }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}

/*
ID: sheshao1
LANG: C++
TASK: friday
*/

#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int N;
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int daycount[7];
    int i,j,k,t;
    memset(daycount,0,sizeof(daycount));
    FILE *fin = fopen("friday.in","r");
    FILE *fout = fopen("friday.out","w");
    fscanf(fin,"%d",&N);
    N+=1900;
    t=0;
    for(i=1900;i<N;i++)
    {
        for(j=0;j<12;j++)
        {
            daycount[t%7]++;
            if(j==1)
            {
                if((i%100)&&!(i&3)||!(i%400))
                    t+=29;
                else
                    t+=28;
            }
            else
                t+=days[j];
        }
    }
    
    for(i=0;i<6;i++)
        fprintf(fout,"%d ",daycount[i]);
    fprintf(fout,"%d\n",daycount[i]);
    return 0; 
}

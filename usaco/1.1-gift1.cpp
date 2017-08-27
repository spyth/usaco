/*
ID: sheshao1
LANG: C++
TASK: gift1
*/
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    FILE *fin = fopen("gift1.in","r");
    FILE *fout = fopen("gift1.out","w");
    int np;
    char name[11][16],str[16];
    int give[11],get[11];
    int i,j,k,t,m;
    memset(get,0,sizeof(get));
    fscanf(fin,"%d",&np);
    for(i=0;i<np;i++)
    {
        fscanf(fin,"%s",&name[i]);
    }
    for(i=0;i<np;i++)
    {
        fscanf(fin,"%s",&str);
        for(j=0;j<np;j++)
            if(strcmp(str,name[j]) == 0)
                break;
        fscanf(fin,"%d%d",&give[j],&m);
        if(m!=0)    
            t=give[j]/m;
        else
            continue;
        get[j]+=give[j]%m;
        for(k=0;k<m;k++)
        {
            fscanf(fin,"%s",&str);
            for(j=0;j<np;j++)
                if(strcmp(str,name[j]) == 0)
                    break;
            get[j]+=t;
        }
    }
    for(i=0;i<np;i++)
        fprintf(fout,"%s %d\n",name[i],get[i]-give[i]);
    return 0;
}

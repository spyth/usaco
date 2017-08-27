/*
ID:sheshao1
LANG:C++
TASK:crypt1
*/
#include <cstdio>
using namespace std;

bool app[10]={0};
bool check(int n)
{
    while(n>0)
    {
        if(!app[n%10])
            return false;
        n/=10;
    }
    return true;
}
int  main()
{
    FILE *fin,*fout;
    int num[10];
    int i,j,k,l,m,N,t1,t2,t3,a,ans;
    fin = fopen("crypt1.in","r");
    fout = fopen("crypt1.out","w");
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++){
        fscanf(fin,"%d",&t1);
        app[t1]=1;
    }
    for(i=1,t1=0;i<10;i++){
        if(app[i])
            num[t1++]=i;
    }
    for(i=0,ans=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                a=num[i]*100+num[j]*10+num[k];
                for(l=0;l<N;l++){
                    t1=a*num[l];
                    if(t1>=1000)
                        break;
                    if(!check(t1))
                        continue;
                    for(m=0;m<N;m++){
                        t2=a*num[m];
                        if(t2>=1000)
                            break;
                        if(!check(t2))
                            continue;
                        t3=t1*10+t2;
                        if(t3>=10000)
                            break;
                        if(check(t3))
                        {
                            //fprintf(fout,"%d %d %d %d %d\n",num[i],num[j],num[k],num[l],num[m]);
                            ans++;
                        }
                    }
                }
            }
        }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
} 

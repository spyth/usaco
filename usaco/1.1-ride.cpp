/*
ID: sheshao1
LANG: C++
TASK: ride
*/
#include <stdio.h>

int main()
{
    FILE *fin = fopen("ride.in","r");
    FILE *fout = fopen("ride.out","w");
    char a[10],b[10];
    int c,d,i;
    fscanf(fin,"%s%s",&a,&b);
    c=d=1;
    i=0;
    while(a[i])
    {
        c*=(a[i]-'A'+1);
        i++;    
    }
    i=0;
    while(b[i])
    {
        d*=(b[i]-'A'+1);
        i++;    
    }
    c%=47;
    d%=47;
    if(c==d)
        fprintf(fout,"GO\n");
    else
        fprintf(fout,"STAY\n");
    return 0;
} 

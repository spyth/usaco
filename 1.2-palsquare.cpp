/*
ID:sheshao1
LANG:C++
TASK:palsquare
*/
#include <cstdio>
using namespace std;
FILE *fin,*fout;
void reverse(char str[],int l)
{
    int i,j;
    char t;
    j=l>>1;
    for(i=0;i<j;i++)
    {
        t=str[i];
        str[i]=str[l-1-i];
        str[l-1-i]=t;
    }
    for(i=0;i<l;i++)
    {
        str[i]=str[i]+'0';
        if(str[i]>'9')
            str[i]+='A'-'9'-1;
    }
    str[l]='\0';
}
int transf(int n,int b,char str[])
{
    int l=0;
    while(n!=0)
    {
        str[l++]=n%b;
        n/=b;
    }
    return l;
}
bool palsq(char str[],int l)
{
    int i;
    for(i=0;i<l;i++)
    {
        if(str[i]!=str[l-1-i])
            return false;    
    }
    return true;
}

int main()
{
    
    fin = fopen("palsquare.in","r");
    fout = fopen("palsquare.out","w");
    int B,i,j;
    char str1[18],str2[10];
    int l1,l2;
    fscanf(fin,"%d",&B);
    for(i=1;i<=300;i++)
    {
        j=i*i;
        l1=transf(j,B,str1);
        if(palsq(str1,l1))
        {
             l2=transf(i,B,str2);
             reverse(str2,l2);
             reverse(str1,l1);
             fprintf(fout,"%s %s\n",str2,str1);
        }
    }
    return 0;
} 

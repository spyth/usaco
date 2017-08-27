/*
ID:sheshao1
LANG:C++
TASK:calfflac
*/
///在一个含标点符号的字符串里搜索最长的忽略标点符号的回文串 
/*
Executing...
   Test 1: TEST OK [0.000 secs, 2884 KB]
   Test 2: TEST OK [0.011 secs, 2884 KB]
   Test 3: TEST OK [0.011 secs, 2884 KB]
   Test 4: TEST OK [0.000 secs, 2884 KB]
   Test 5: TEST OK [0.011 secs, 2884 KB]
   Test 6: TEST OK [0.011 secs, 2884 KB]
   Test 7: TEST OK [0.000 secs, 2884 KB]
   Test 8: TEST OK [0.659 secs, 2884 KB]
*/
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
	freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    char str[20002];
	char *p;
    int nlen,l,r,L,R,MaxLen,i,j,k,len;
	p= str;
    while(gets(p) !=  NULL)
	{
		nlen = strlen(str);
		str[nlen]='\n'; 
        p= str+nlen+1;
	}
	str[nlen]='\0';
    for(i=0,MaxLen=0;i<nlen;i++)
    {
        if(!isalpha(str[i]))
            continue;
        //str[i] as center
		for(j=i-1,k=i+1,len=1;j>=0 && k<nlen ;j--,k++)
		{
			while(j>=0 && !isalpha(str[j]))
				j--;
			while(k<nlen && !isalpha(str[k]))
				k++;
			if(tolower(str[j]) != tolower(str[k]) )
				break;
			l=j;
			r=k;
			len+=2;
		}
		if(len>MaxLen)
		{
			MaxLen=len;
			L=l;
			R=r;
		}
		//str[i] as middle left
		for(j=i,k=i+1,len=0;j>=0 && k<nlen;j--,k++)
		{
			while(j>=0 && !isalpha(str[j]))
				j--;
			while(k<nlen && !isalpha(str[k]))
				k++;
			if(tolower(str[j]) != tolower(str[k]) )
				break;
			l=j;
			r=k;
			len+=2;
		}
		if(len>MaxLen)
		{
			MaxLen=len;
			L=l;
			R=r;
		}
    }
	str[R+1] ='\0';
	printf("%d\n",MaxLen);
	printf("%s\n",str+L);
    return 0;
}

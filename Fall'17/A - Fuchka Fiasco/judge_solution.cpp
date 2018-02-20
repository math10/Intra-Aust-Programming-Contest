#include<bits/stdc++.h>

#define li long int
#define MAX 1002
#define MOD 1000000007

li ncr_array[MAX+5][MAX+5];

void build_ncr_array()
{

ncr_array[0][0]=ncr_array[1][0]=ncr_array[1][1]=1;
for(int i=2;i<=MAX;i++)
    {
    ncr_array[i][0]=ncr_array[i][i]=1;
    for(int j=1;j<i;j++)
        {
        ncr_array[i][j] = (ncr_array[i-1][j]+ncr_array[i-1][j-1]) % MOD;
        }

    }
}

li find_catalan(int n)
{

if(n==0) return 1;
else
{
li x= ncr_array[2*n][n]-ncr_array[2*n][n+1];
if(x<0) x+=MOD;
return x;
}
}
int main()
{
build_ncr_array();
int n,x;
scanf("%d",&x);
while(x--)
{
scanf("%d",&n);
printf("%lu\n",find_catalan(n));
}
return 0;
}


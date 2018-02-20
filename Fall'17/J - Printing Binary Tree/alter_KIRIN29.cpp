#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define Max(a,b) ((a>=b)? a : b)
#define Min(a,b) ((a<=b)? a : b)
#define pb push_back
#define MOD 1000000000
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define MAX 32001
//typedef __int128 bigll;
ll node[10000];

void gen()
{
    ll p=1,prev=0;
    for(int i=1; prev+p<=10000; i++)
    {
        node[prev+p]=i;
        prev+=p;
        p*=2;
        //cout<<i<<endl;
    }
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    gen();
    int n,t;

    while(scanf("%d",&n)==1)
    {
        int row=node[n];
        int limit=pow(2,row)-1;
        for(int i=row,need=1; i>=1; i--,need++)
        {
            int counter=0;
            int valid=pow(2,need-1);
            int skip=pow(2,i)-1;
            int space = pow(2,i-1)-1;
            for(int j=1; j<=space; j++)printf("-");
            for(int j=space+1,x=1; j<=limit; j++,x++)
            {
                if(x==skip+2)x=1;
                if(x==1)printf("O"),counter++;
                else if(counter<valid)printf("-");

            }
            printf("\n");
        }
        printf("\n");
    }
    //fclose(f);
    //fclose(o);

    return 0;
}



#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int grundy[520];
bool arr[510];

int grun(int n)
{
    if(n==0) return 0;
    if(grundy[n]!=-1) return grundy[n];
    int g[520];
    memset(g, 0, sizeof g);
    for(int i=1; i<=n; i++)
    {
        if(arr[i])
        {
            int x=grun(n-i);
            g[x]=1;
        }
    }
    int ans;
    for(int i=0; i<=520; i++)
    {
        if(g[i]==0)
        {

            ans= i;
            break;
        }
    }
    return grundy[n]=ans;
}

int main()
{
    int tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++)
    {
        ll n, k;
        cin>>n>>k;

        memset(arr, false, sizeof arr);
        memset(grundy, -1, sizeof grundy);
        for(ll i=1; i<=n; i++)
        {
            if(__gcd(k, i)==1 && (k&i))
                arr[i]=true;
        }
        //arr[1]=arr[2]=arr[3]=1;
        int g[520];
        memset(g, 0, sizeof g);
        for(int i=1; i<=n; i++)
        {
            if(arr[i])
            {
                int x=grun(n-i);
               // cout<<x<<endl;
                g[x]=1;
            }
        }
        int ans;
        for(int i=0; i<=n; i++)
        {
            if(g[i]==0)
            {
                ans=i;
                break;
            }
        }
        if(ans) cout<<"Turja"<<endl;
        else cout<<"Akash"<<endl;
        //do mex
    }
    return 0;
}

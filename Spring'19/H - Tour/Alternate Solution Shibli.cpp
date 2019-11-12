#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 102
int n, len, ans;
int dp[1<<15];
vector<int>V[MX];

int check (int mask, int i)
{
    return (mask &(1<<i));
}

void BitmaskDP(int mask)
{
    if(mask == (1<<len))return;
    int k = __builtin_popcount(mask);

    bool visited[MX] = {false};
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(!check(mask, i))continue;
        for(int j = 0; j < V[i].size(); j++)
        {
            if(visited[V[i][j]])continue;
            visited[V[i][j]] = true;
            cnt++;
        }
    }
    if(cnt == n)ans = min(ans, k);
    dp[mask] = ans;
    BitmaskDP(mask+1);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        for(int i = 0; i < MX; i++)V[i].clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            string s;
            cin>>s;
            len = s.size();
            for(int j = 0; j < len; j++)if(s[j] == 'Y')V[j].push_back(i);
        }
        ans = 100000000;
        memset(dp, -1, sizeof(dp));
        BitmaskDP(0);
        printf("Case %d: %d\n", kase, dp[(1<<len)-1]);
    }
}

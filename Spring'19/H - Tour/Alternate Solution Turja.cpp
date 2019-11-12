#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int inf = (int)1e9;
int n, m;
vector <int> adj[MAXN];
bitset <MAXN> bs;
int dp[15][1 << 15][110];
bool vis[110];
bool chk(int pos, int mask) {
  return ( mask & ( 1 << pos ) );
}
int on(int pos, int mask) {
  return ( mask | ( 1 << pos ) );
}
int cnt1 = 0;
int solve( int spos, int mask, int total ) {
    if ( total == n ) return __builtin_popcount(mask);
    if ( spos == m ) {
        if ( total == n ) return __builtin_popcount(mask);
        return inf;
    }
    if ( dp[spos][mask][total] != -1) return dp[spos][mask][total];
    int ret = inf;
    if ( !chk(spos, mask) ) {
        for ( int i = 0; i < adj[spos].size(); ++i ) {
            if ( vis[adj[spos][i]] == 0 ) {
                vis[adj[spos][i]] = 1;
                ++cnt1;
            }
        }
        if ( total + cnt1 <= n ) ret = solve(spos + 1, on(spos, mask), total + cnt1);
        else ret = min(ret, solve(spos + 1, mask, total));
        for ( int i = 0; i < adj[spos].size(); ++i ) {
            vis[adj[spos][i]] = 0;
        }
        cnt1 = 0;
        ret = min(ret, solve(spos + 1, mask, total));
    }
    ret = min(ret, solve(spos + 1, mask, total));
    return dp[spos][mask][total] = ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    for ( int kase = 1; kase <= tc; ++kase ) {
        cin >> n;
        int sz;
        for ( int i = 0; i < n; ++i ) {
            string s;
            cin >> s;
            sz = (int)s.size();
            for ( int j = 0; j < sz; ++j ) {
                if ( s[j] == 'Y' ) {
                    adj[j].push_back(i);
                }
            }
        }
        m = sz;
        memset(dp, -1, sizeof(dp));
        cout << solve(0,0,0) << endl;
        int total = (1 << sz);
        int ans = inf;
        for ( int mask = 0; mask < total; ++mask ) {
            bs.reset();
            for ( int i = 0; i < sz; ++i ) {
                if ( chk(i, mask) ) {
                    for ( int j = 0; j < adj[i].size(); ++j ) {
                        if ( !bs.test(adj[i][j]) ) {
                            bs.set(adj[i][j]);
                        }
                    }
                }
            }
            if ( bs.count() == n ) ans = min(ans, __builtin_popcount(mask));
        }
        cout << "Case " << kase << ": " << ans << endl;
        for ( int i = 0; i < n; ++i ) {
            adj[i].clear();
        }
    }
    return 0;
}

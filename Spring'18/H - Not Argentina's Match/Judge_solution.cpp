#include <bits/stdc++.h>

using namespace std;

int n, w;
int e[100 + 5], p[100 + 5];
int dp[100 + 5][1000 + 5];

int DP(int pos, int tot) {
    if(pos == n)
        return 0;

    int &ret = dp[pos][tot];

    if(ret != -1)
        return ret;

    int p1 = 0, p2 = 0;

    if(tot + e[pos] <= w)
        p1 = p[pos] + DP(pos + 1, tot + e[pos]);

    p2 = DP(pos + 1, tot);

    return ret = max(p1, p2);
}

int main() {
    int t;
    scanf("%d", &t);

    for(int cs = 1; cs <= t; ++cs) {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &n, &w);

        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &e[i], &p[i]);
        }

        int ans = DP(0, 0);

        printf("%d\n", ans);
    }
}


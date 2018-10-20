#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const ll P = 29;
const int N = 1000010;
const int MOD = 1e9 + 7;
const ll INV = 758620695;

int t, cs, ss, pp;
char s[N], p[N];
ll spre[N], ppre[N];
ll pwr[N], inv[N];

inline ll get (int l, int r) {
  ll ret = spre[r] - spre[l - 1];
  if (ret < 0) ret += MOD;
  return ret * inv[l] % MOD;
}

int main() {
  pwr[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    pwr[i] = pwr[i - 1] * P % MOD;
    inv[i] = inv[i - 1] * INV % MOD;
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", s + 1, p + 1);
    ss = strlen(s + 1), pp = strlen(p + 1);
    for (int i = 1; i <= ss; ++i) {
      spre[i] = spre[i - 1] + pwr[i] * (s[i] - 'a' + 1);
      spre[i] %= MOD;
    }
    ll pHash = 0;
    for (int i = 1; i <= pp; ++i) {
      ppre[i] = ppre[i - 1] + pwr[i] * (p[i] - 'a' + 1);
      ppre[i] %= MOD;
      pHash += pwr[i - 1] * (p[i] - 'a' + 1);
      pHash %= MOD;
    }
    int len = pp, pref = pp / 2, suff = pp - pref, ans = 0;
    for (int i = 1; i <= ss; ++i) {
      if (get(i, i + len - 1) == pHash) {
        ++ans;
        if (len == 1) continue;
        if (len & 1) {
          --suff;
        } else {
          --pref;
        }
        --len;
        pHash = ppre[pref] * inv[1] + (ppre[pp] - ppre[pp - suff]) * inv[pp - suff + 1 - pref];
        pHash %= MOD;
        if (pHash < 0) pHash += MOD;
      }
    }
    printf("Case %d: %d\n", ++cs, ans);
  }
  return 0;
}

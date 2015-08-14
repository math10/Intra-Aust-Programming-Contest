#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

map <LL, LL> F;
LL f (LL n) {
	if (F.count (n)) return F [n];
	LL k = n / 2LL;
	if (n % 2LL == 0LL) {
		return F [n] = (f (k) * f (k) + f (k - 1) * f (k - 1)) % MOD;
	} else {
		return F [n] = ( f (k) * f (k + 1) + f (k - 1) * f(k)) % MOD;
	}
}

int main () {
    freopen ("sample.in", "r", stdin);
    freopen ("sample.out", "w", stdout);

	int T;
	F [0] = F [1] = 1;

	cin >> T;
	for (int cs = 1; cs <= T; ++cs) {
        LL n;
        cin >> n;
        cout << "Case " << cs << ": " << (n == 0 ? 0 : f (n - 1)) << endl;
	}

	return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int main () {

	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);


	int t;
	scanf ("%d", &t);

	for (int cs = 1; cs <= t; ++cs) {
		int p, q, a, b;
		scanf ("%d %d %d %d", &p, &q, &a, &b);

		p = abs (p); q = abs (q);
		int gcd = __gcd (p, q);

		p /= gcd; q /= gcd;

		long long ans = min ((a - 1) / p, (b - 1) / q);
		printf ("Case %d: %lld\n", cs, ans * 2);
	}

	return 0;
}


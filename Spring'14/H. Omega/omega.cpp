/* in the name of ALLAH, most gracious, most merciful */
#include <stdio.h>

const int MAX_N = int (1e4) + 7;
int o [MAX_N];

void gen () {
	for (int n = 1; n < MAX_N; ++n) {
		int _n = n;
		for (int i = 2; i <= _n; ++i) {
			if (_n % i == 0) {
				++o [n];
				while (_n % i == 0)
					_n /= i;
			}
		}
	}
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);

	gen ();
	for (int cs = 1; cs <= t; ++cs) {
		int a, b, k;
		scanf ("%d %d %d", &a, &b, &k);

		int ans = 0;
		for (int i = a; i <= b; ++i)
			if (o [i] == k)
				++ans;

		printf ("Case %d: %d\n", cs, ans);
	}

	return 0;
}


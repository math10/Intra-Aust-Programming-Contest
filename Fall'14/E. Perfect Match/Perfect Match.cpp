/* in the name of ALLAH, most gracious, most merciful */

#include <stdio.h>
#include <string.h>

const int MAX_N = int (1e3) + 7;
const int MOD   = int (1e9) + 7;

int n;
char s [MAX_N];

bool seen [MAX_N][MAX_N][3];
int cache [MAX_N][MAX_N][3];

// p    :: position
// b    :: for counting balancing
// type :: which type I'm currently for
//         type 0 -> anything
//         type 1 -> '('
//         type 2 -> ')'
int dp (int p, int b, int type) {
	if (b < 0) return 0;
	if (p == n) return b == 0 && type == 0;

	int &ret = cache [p][b][type];
	if (seen [p][b][type]) return ret;

	seen [p][b][type] = true;
	ret = 0;

	if (type == 0) {
		ret = dp (p + 1, b + (s [p] == '(' ? 1 : -1), 0) // take
			+ dp (p + 1, b, s [p] == '(' ? 2 : 1) // skip
			+ (b == 0); // already found a balanced sequence
	} else if ((type == 1 && s [p] == '(')
			|| (type == 2 && s [p] == ')')) {
		ret = dp (p + 1, b + (s [p] == '(' ? 1 : -1), 0); // take
	} else {
		ret = dp (p + 1, b, type); // skip
	}

	return ret %= MOD;
}

int main () {
#ifdef Local
	freopen ("sample.in", "r", stdin);
	freopen ("sample.out", "w", stdout);
#endif
	int t; scanf ("%d", &t);

	for (int cs = 1; cs <= t; ++cs) {
		scanf ("%d %s", &n, s);
		memset (seen, false, sizeof seen);
		printf ("Case %d: %d\n", cs, dp (0, 0, 0));
	}

	return 0;
}


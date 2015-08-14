/* in the name of ALLAH, most gracious, most merciful */

#include <cstdio>
#include <cstring>
#include <vector>

const int MAX_N = 107;
using namespace std;

int ans, c [MAX_N];
vector <int> e [MAX_N];

void dfs (int u, int has) {
	ans += has;

	int tot = 0;
	for (int i = 0; i < (int) e [u].size (); ++i) {
		int v = e [u][i];
		if (c [v]) ++tot;
	}

	for (int i = 0; i < (int) e [u].size (); ++i) {
		int v = e [u][i];
		if (c [v]) dfs (v, tot > 1);
		else dfs (v, tot > 0);
	}
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);

	for (int cs = 1; cs <= t; ++cs) {
		int n;
		scanf ("%d", &n);

		for (int i = 1; i <= n; ++i)
			e [i].clear ();

		for (int i = 1; i < n; ++i) {
			int u, p, col;
			scanf ("%d %d %d", &u, &p, &col);

			c [u] = col;
			e [p].push_back (u);
		}

		ans = 0;
		dfs (1, 0);
		printf ("Case %d: %d\n", cs, ans);
	}

	return 0;
}


//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, i64 >
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

#define mx 100

#define chkLMT(I,J,K) assert(I<=J && J<=K)

int g[mx+1][mx+1], w, u, v, n;
bool vis[mx+1][501];


void dfs(int u, int cs) {
    //cerr<<u<<' '<<cs<<'\n';
    vis[u][cs] = true;
    for(int i=1, c;i<=n;i++) if(g[u][i]) {
        c = cs + g[u][i];
        if(c<=w && !vis[i][c]) dfs(i, c);
    }
}




int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	//READ("sample.in");
	//READ("large.in");
	//READ("in2.txt");
	//READ("input.txt");
	//WRITE("out.txt");
	int i, j;
	cin>>n;
	chkLMT(1, n, 100);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) {
        cin>>g[i][j];
        chkLMT(0, g[i][j], 100);
        if(i==j) assert(!g[i][j]);
	}
    int q;
	cin>>q;
	chkLMT(1, q, 100);
    while(q--) {
        cin>>u>>v>>w;
        chkLMT(1, u, n);
        chkLMT(1, v, n);
        chkLMT(1, w, 500);
        CLR(vis);
        dfs(u, 0);
        while(w && !vis[v][w]) w--;
        cout<< ( w ? w : -1 ) <<'\n';
    }

	return 0;
}


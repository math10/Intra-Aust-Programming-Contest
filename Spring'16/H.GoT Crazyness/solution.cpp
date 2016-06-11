#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> adj[1000+5], rev[1000+5];
int cnt;

struct node {
    int pos, endtime;
    node( int _pos, int _endtime ) {
        pos = _pos;
        endtime = _endtime;
    }
};

bool cmp( node a, node b ) {
    return a.endtime > b.endtime;
}

vector < node > nodes;

int color[1000+5];
int endtimes[1000+5];

int en;

void dfs( int u ) {
    color[u] = 1;
    for( int i = 0; i < adj[u].size(); ++i ) {
        int v = adj[u][i];
        if( color[v] == 0 ) {
            dfs(v);
        }
    }
    endtimes[u] = en++;
}

void dfs2( int u ) {
    color[u] = 1;
    cnt++;
    for( int i = 0; i < rev[u].size(); ++i ) {
        int v = rev[u][i];
        if( color[v] == 0 ) {
            dfs2(v);
        }
    }
}

int main() {
    #ifdef Sanim
        freopen("in.txt", "r", stdin);
        freopen("output-aust.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int idx = 1;
        map <string, int> mp;
        cin >> n >> m;


        nodes.clear();

        for( int i = 0; i < m; ++i ) {
            string ustr, vstr;
            cin >> ustr >> vstr;
            int u, v;
            if( !mp[ustr] ) mp[ustr] = idx++;
            if( !mp[vstr] ) mp[vstr] = idx++;
            u = mp[ustr];
            v = mp[vstr];
            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        memset(color, 0, sizeof(color));
        en = 1;
        for( int i = 1; i <= n; ++i ) {
            if( color[i] == 0 ) {
                dfs(i);
            }
        }
        for( int i = 1; i <= n; ++i ) {
            nodes.push_back(node(i, endtimes[i]));
        }
        sort(nodes.begin(), nodes.end(), cmp);

        bool ans = false;
        cnt = 0;

        memset(color, 0, sizeof(color));
        for( int i = 0; i < n; ++i ) {
            if( color[nodes[i].pos] == 0 ) {
                dfs2(nodes[i].pos);
                //cout << nodes[i].pos << " " << cnt << endl;
            }
            if( cnt > (n/2) ) ans = true;
            cnt = 0;
        }

        if( ans ) cout << "Fight the white walkers." << endl;
        else cout << "Doomed." << endl;

        for( int i = 0; i <= n; ++i ) {
                adj[i].clear();
                rev[i].clear();
        }
    }
}

/*

1
8 9
1 2
2 3
3 4
4 1
5 4
3 5
3 6
6 7
7 8

*/

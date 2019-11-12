#include<bits/stdc++.h>
using namespace std;

#define MX 105
int dist[MX][MX], visited[MX][MX];
char grid[MX][MX];
int n, m, K, d;

#define piii pair<int, pair<int,int>>
#define pii pair<int, int>

int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1};

void FASTIO(int& n)
{
    char c = getchar();
    while(c == ' ' || c == '\n')c = getchar();
    n = 0;
    while('0' <= c && c <= '9')
    {
        n = 10*n + (c - '0');
        c = getchar();
    }
}

bool Check(int u, int v)
{
    return (u >= 0 && v >= 0 && u < n && v < m);
}

bool Possible(int x, int y, int p, int q)
{
    return ( ((x-p)*(x-p) + (y-q)*(y-q)) <= K );
}

vector<pair<int, int>>P[MX][MX];

/*void init()
{
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0; j < m; j++)
        {
            grid[i][j] = ' ';
            dist[i][j] = INT_MAX;
            visited[i][j] = 0;
            P[i][j].clear();
        }
    }
    while(!Q.empty())Q.pop();
}
*/

void Mark_Jump_Points()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = INT_MAX;
            visited[i][j] = 0;
            P[i][j].clear();

            if(grid[i][j] == 'R' || grid[i][j] =='#')continue;

            for(int k = i; k < n; k++)
            {
                if(!Possible(i, j, k, j))break;
                for(int l = j-1; l >= 0; l--)
                {
                    if(!Possible(i, j, k, l))break;
                    if(grid[k][l] != '.')continue;
                    P[i][j].push_back(make_pair(k,l));
                }
                for(int l = j; l < m; l++)
                {
                    if(!Possible(i, j, k, l))break;
                    if(grid[k][l] != '.')continue;
                    P[i][j].push_back(make_pair(k,l));
                }
            }

            for(int k = i-1; k >= 0; k--)
            {
                if(!Possible(i, j, k, j))break;
                for(int l = j-1; l >= 0; l--)
                {
                    if(!Possible(i, j, k, l))break;
                    if(grid[k][l] != '.')continue;
                    P[i][j].push_back(make_pair(k,l));
                }
                for(int l = j; l < m; l++)
                {
                    if(!Possible(i, j, k, l))break;
                    if(grid[k][l] != '.')continue;
                    P[i][j].push_back(make_pair(k,l));
                }
            }
        }
    }
}

/*void Relax(int newX, int newY, int prevCost)
{
    if( dist[newX][newY] > prevCost )
    {
        dist[newX][newY] = prevCost;
        Q.push(node(newX, newY, -dist[newX][newY]));
    }
}
*/

int Dijkstra(int sourceX, int sourceY)
{
    deque<piii>Q;
    Q.push_back(piii(0, pii(sourceX, sourceY)));
    dist[sourceX][sourceY] = 0;

    while(!Q.empty())
    {
        piii V = Q.back();
        Q.pop_back();

        int x = V.second.first;
        int y = V.second.second;
        int w = V.first;

        if( visited[x][y] )continue;
        visited[x][y] = 1;

        for(int i = 0; i < 8; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if(Check(u, v))
            {
                if(grid[u][v] == 'R')return dist[x][y];
                else if(grid[u][v] == '.')
                {
                    if( dist[u][v] > dist[x][y] )
                    {
                        dist[u][v] = dist[x][y];
                        Q.push_back(piii(-dist[u][v], pii(u, v)));
                    }
                }
            }
        }
        for(auto it: P[x][y])
        {
            if( dist[it.first][it.second] > dist[x][y] + 1  )
            {
                dist[it.first][it.second] = dist[x][y] + 1;
                Q.push_front(piii(-dist[it.first][it.second], pii(it.first, it.second)));
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    FASTIO(t);
    for(int kase = 1; kase <= t; kase++)
    {
        FASTIO(n); FASTIO(m); FASTIO(K); FASTIO(d);
        K = K*K;
        for(int i = 0; i < n; i++)scanf("%s", grid[i]);
        Mark_Jump_Points();
        int res = Dijkstra(0, 0);
        if(res == -1 || 2*res >= d)puts("NO");
        else                       puts("YES");
    }
}


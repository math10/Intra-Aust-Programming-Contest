#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define LD long double
const int MAXN = 105;

struct Point{
    ll x, y;
    Point (ll x = 0, ll y = 0): x(x), y(y) {}

    Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
    Point operator * (const ll u) { return Point(x * u, y * u); }
};
typedef Point Vector;
namespace Vectorial {
    ll getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
    ll getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
    LD getLength (Vector a) { return sqrt(getDot(a, a)); }
};
using namespace Vectorial;

vector<Point> vec;
vector<LD> Cache[MAXN][MAXN];
namespace Triangular{
    ll getArea (Point a, Point b, Point c) { return fabs(getCross(b - a, c - a));}
    bool onSegment (Point p, int i, int j, int k){
        if(i > j) swap(i, j);
        Point a = vec[i];
        Point b = vec[j];
        bool ret = getCross(a-p, b-p) == 0 && getDot(a-p, b-p) <= 0;
        if(ret) Cache[i][j].push_back(getLength(vec[i] - vec[k]) + getLength(vec[j] - vec[k]));
        return ret;
    }

    bool inside(Point p, Point a, Point b, Point c){
        ll a1 = getArea(p,a,b);
        ll a2 = getArea(p,b,c);
        ll a3 = getArea(p,c,a);
        return a1 + a2 + a3 == getArea(a, b, c);
    }
}
using namespace Triangular;

int main(){
    int t;
    scanf("%d",&t);

    for(int cs=1; cs<=t; cs++){
        Point p;
        scanf("%lld %lld",&p.x, &p.y);

        int n;
        scanf("%d",&n);
        vec.resize(n);
        for(int i=0; i<n; i++) scanf("%lld %lld",&vec[i].x, &vec[i].y);
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) Cache[i][j].clear();

        bool found = false;
        LD dist = 1e18;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(onSegment(p, i, j, k)) continue;
                    if(onSegment(p, j, k, i)) continue;
                    if(onSegment(p, k, i, j)) continue;

                    if(inside(p, vec[i], vec[j], vec[k])){
                        found = true;
                        dist = min(dist, getLength(vec[i]-vec[j]) + getLength(vec[j] - vec[k]) + getLength(vec[k] - vec[i]));
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sort(Cache[i][j].begin(), Cache[i][j].end());
                if(Cache[i][j].size() <= 1) continue;

                found = true;
                dist = min(dist, Cache[i][j][0] + Cache[i][j][1]);
            }
        }

        double ans = dist;
        if(!found) printf("Case %d: -1\n",cs);
        else printf("Case %d: %lf\n",cs,ans);
    }
}

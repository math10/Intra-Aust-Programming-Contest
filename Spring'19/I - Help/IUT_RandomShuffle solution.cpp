#include<bits/stdc++.h>
using namespace std;

#define MAX             105
#define LL              long long
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define ABS(x)          ((x)<0?-(x):(x))
#define eps             1e-8

int n;
struct point{
    LL x,y;
    int triarea(const point a,const point b)
    {
        LL d=x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y);
        if(d>0) return 1;
        else if(d<0) return -1;
        return d;
    }
    double dis(const point a)
    {
        LL d=(a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
        return (double)sqrt(d);
    }
}P[MAX];

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        point p;
        scanf("%lld %lld",&p.x,&p.y);
        scanf("%d",&n);
        REP(i,n) scanf("%lld %lld",&P[i].x,&P[i].y);
        double ans=1e18;
        REP(i,n)
        {
            if(P[i].x==p.x and P[i].y==p.y) continue;
            REP(j,n)
            {
                if(P[j].x==p.x and P[j].y==p.y) continue;
                if(i==j) continue;
                if(ABS(P[i].dis(P[j])-P[i].dis(p)-P[j].dis(p))<eps)
                {
                    double d1=1e18,d2=1e18;
                    REP(k,n)
                    {
                        if(P[k].x==p.x and P[k].y==p.y) continue;
                        if(i==k or j==k) continue;
                        if(P[i].triarea(P[j],P[k])==1) d1=min(d1,P[i].dis(P[k])+P[j].dis(P[k]));
                        else if(P[i].triarea(P[j],P[k])==-1) d2=min(d2,P[i].dis(P[k])+P[j].dis(P[k]));
                        //cout << "========== " << i << ' ' << j << ' ' << k << ' ' << P[i].triarea(P[j],P[k]) << ' ' << d1+d2 << '\n';
                        ans=min(ans,d1+d2);
                    }
                }
                else{
                    REP(k,n)
                    {
                        if(P[k].x==p.x and P[k].y==p.y) continue;
                        if(k==i or k==j) continue;
                        if(ABS(P[i].dis(P[k])-P[i].dis(p)-P[k].dis(p))<eps or ABS(P[k].dis(P[j])-P[k].dis(p)-P[j].dis(p))<eps) continue;
                        if(P[i].triarea(P[j],p)==P[j].triarea(P[k],p) and P[i].triarea(P[j],p)==P[k].triarea(P[i],p))
                        {
                            double tmp=P[i].dis(P[j])+P[i].dis(P[k])+P[j].dis(P[k]);
                            ans=min(ans,tmp);
                        }
                    }
                }
            }
        }
        if(ans>=1e16) printf("Case %d: -1\n",tc);
        else printf("Case %d: %.6f\n",tc,ans);
    }
}
/*
1
1 1
4
0 0
0 2
2 0
2 2
*/

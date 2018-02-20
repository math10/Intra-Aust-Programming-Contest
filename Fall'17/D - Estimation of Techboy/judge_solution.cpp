/*
Name: Mahir Asef Kabir
AUST CSE 28th Batch
Problem Name: Estimation
*/
#include <bits/stdc++.h>
using namespace std;

#define FORab(i,a,b) for( __typeof(a)         i = (a);          i <= (b);        ++i )
#define FORba(i,a,b) for( __typeof(a)         i = (a);          i >= (b);        --i )
#define forstl(i, s) for( __typeof((s).end()) i = (s).begin (); i != (s).end (); i++ )
#define rep(i,n)     FORab(i,0,n-1)
#define II           ({int    a;scanf("%d",   &a);a;})
#define IL           ({int64  a;scanf("%lld", &a);a;})
#define ID           ({double a;scanf("%lf",  &a);a;}
#define all(a)       (a).begin(), (a).end()
#define MP           make_pair
#define pb           push_back
#define INF          1<<30
#define int64        long long
#define nl           puts("")
#define vi           vector<int>
#define pii          pair<int,int>
#define PI           3.141592653589793
#define EPS          2.718281828459045
#define memo(a,b)    memset(a,b,sizeof(a))

template < class T, class U > inline T max (T &a, U &b) { return a > b ? a : b; }
template < class T, class U > inline T min (T &a, U &b) { return a < b ? a : b; }
template < class T, class U > inline T swap (T &a, U &b){ T tmp = a;a = b;b = tmp;}
template < class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template < class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template < class X, class Y, class Z > X BigMod( X B, Y P, Z M ) {
    if( P == 0 ) return 1;
    if( P % 2 == 1 ) {
        return ((B%M)*BigMod(B,P-1,M))%M;
    }
    X P2 = BigMod(B,P/2,M);
    return (P2*P2)%M;
}

class CLASS_NAME {
public:
    string methodname() {

    }
};

const int sz = 1e6 + 7;
int E[sz + 5];
int A[sz + 5];

int main() {
    #ifdef Mahir
        //freopen("input.txt", "r", stdin);
        freopen("in1.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = II;

    rep(cs, t) {
        int N = II;
        int K = II;
        int estMax = 0;
        int actMax = 0;

        for(int i = 0; i <= sz; ++i) {
            E[i] = 0;
            A[i] = 0;
        }

        int estTot = 0;
        rep(i, N) {
            int a = II;

            int tmp = a;
            a += estMax;
            estMax += tmp;

            E[a] = ++estTot;
        }

        int actTot = 0;
        rep(i, N) {
            int a = II;

            int tmp = a;
            a += actMax;
            actMax += tmp;

            A[a] = ++actTot;
        }


        int mx = max(estMax, actMax);

        int estCurr = 0;
        int accCurr = 0;
        FORab(i, 1, mx) {
            if(E[i] != 0) estCurr = E[i];
            else E[i] = estCurr;

            if(A[i] != 0) accCurr = A[i];
            else A[i] = accCurr;
        }

        bool ok = true;

        for(int i = 0; i <= mx ; i += K) {
            if(A[i] < E[i]) {
                ok = false;
                break;
            }
        }

        if(ok)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}

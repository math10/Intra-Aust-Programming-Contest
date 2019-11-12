#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int MX=100007;
typedef unsigned long long ULL;

LL phi[MX];

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

void phiSeive()
{
    for(int i = 1; i <= MX-7; i++)phi[i] = i;
    for(int i = 2; i <= MX-7; i++)
    {
        if(phi[i] == i)
        {
            phi[i] = i-1;
            for(int j = i<<1; j <= MX-7; j += i)phi[j] = (phi[j]/i)*(i-1);
        }
    }
}

struct Bitset
{
    int len, vlen;
    vector<ULL> bit;

    Bitset()
    {
    }

    Bitset(int bits)
    {
        len = bits;
        vlen = (bits + 63) >> 6;
        bit.resize(vlen);
        fill(bit.begin(), bit.end(), 0);
    }

    void set(int x, int y)
    {
        if (((bit[x >> 6] >> (x & 63)) & 1) != y)
        {
            bit[x >> 6] ^= 1ull << (x & 63);
        }
    }

    int get(int x)
    {
        return (bit[x >> 6] >> (x & 63)) & 1;
    }

    int locate(int k)
    {
        REP(i, vlen)
        {
            int cnt = __builtin_popcountll(bit[i]);
            if (k > cnt)
            {
                k -= cnt;
            }
            else
            {
                ULL x = bit[i];
                REP(j, 64)
                {
                    if (x >> j & 1)
                    {
                        --k;
                        if (k == 0)
                        {
                            return i << 6 | j;
                        }
                    }
                }
            }
        }
        return -1;
    }

    Bitset operator | (const Bitset &o)
    {
        Bitset ret(len);
        REP(i, vlen)
        {
            ret.bit[i] = bit[i] | o.bit[i];
        }
        return ret;
    }
};

const int MAXN = 1e5;
const int MAGIC = 320;
int N, M, Q;
int A[MAXN], B[MAXN];
int SZ, CNT;
Bitset f[MAGIC][MAGIC], val[MAGIC];

void Prepare()
{
    REP(i, N)
    {
        B[i] = A[i];
    }
    sort(B, B + N);
    M = unique(B, B + N) - B;
    REP(i, N)
    {
        A[i] = lower_bound(B, B + M, A[i]) - B;
    }
    SZ = sqrt(N);
    CNT = (N + SZ - 1) / SZ;
    REP(i, CNT)
    {
        int l = SZ * i, r = min(l + SZ, N);
        val[i] = Bitset(M);
        for (int j = l; j < r; ++j)
        {
            val[i].set(A[j], 1);
        }
    }
    REP(i, CNT)
    {
        f[i][i] = val[i];
        for (int j = i + 1; j < CNT; ++j)
        {
            f[i][j] = f[i][j - 1] | val[j];
        }
    }
}

int Solve(int l, int r, int k)
{
    int bl = l / SZ, br = r / SZ;
    Bitset res(M);
    if (bl == br)
    {
        for (int i = l; i <= r; ++i)
        {
            res.set(A[i], 1);
        }
    }
    else
    {
        if (bl + 1 < br)
        {
            res = f[bl + 1][br - 1];
        }
        for (int i = l; i < min(bl * SZ + SZ, N); ++i)
        {
            res.set(A[i], 1);
        }
        for (int i = br * SZ; i <= r; ++i)
        {
            res.set(A[i], 1);
        }
    }
    int ret = res.locate(k);
    if (ret != -1)ret = B[ret];
    return ret;
}

int main()
{
    phiSeive();
    int t;
    FASTIO(t);
    for(int kase = 1; kase <= t; kase++)
    {
        FASTIO(N); FASTIO(Q);
        REP(i, N)A[i] = phi[i+1];
        Prepare();
        int ans = 0;
        printf("Case %d:\n", kase);
        while (Q--)
        {
            int a, b, c, d, k;
            FASTIO(a); FASTIO(b); FASTIO(k);
            a--;
            b--;
            int l = a;
            int r = b;
            ans = Solve(l, r, k);
            if( ans != -1)printf("%d\n", ans);
            else puts("No Distinct Phi Number");
        }
    }
}

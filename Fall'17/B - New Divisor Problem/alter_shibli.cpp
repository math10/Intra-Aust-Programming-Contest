#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define N 1000005
#define BLOCK 555 // ~sqrt(N)

///bitwise sieve start
#define chekb(x) (flag[x>>6] & (1 << ((x >> 1) & 31)))
#define setb(x)  (flag[x>>6] = (flag[x>>6] |  (1 << ((x >> 1) & 31))))
#define isp(x)   ((x==2) || (x>1 && (x&1) && !chekb(x))) //checks is_prime
const int mx = 1000005;
const int S  = sqrt(mx)+1;
int flag[(mx>>6)+10];
int prime[78499+10];
int np;
void siv(void)
{
    int i,j,k;
    np=0; setb(0);
    prime[np++]=2;
    for(i=3;i<=S;i+=2)
        if(!chekb(i))
            for(prime[np++]=i ,j=i*i ,k=i<<1 ; j<=mx ; j+=k)
                setb(j);
    for(;i<=mx;i+=2) if(!chekb(i)) prime[np++]=i;
}
/// bitwise end

/// prime factorization start
int decomp(int a)
{
    int i ,j ,k,cnt,sum;
    int n = a;

    sum = 1;
    for(i=0;i < np && prime[i]*prime[i] <= n;i++)
    {
        cnt=0;
        while(!(n%prime[i]))n/=prime[i],cnt++;
        sum *= (cnt+1); ///NOD formula .
    }
    if( n != 1 )sum *= 2;

    return sum;
}
/// prime factorization end

int Div[N];
void div_generate()
{
    siv();
    for(int i = 1; i < N; i++ )Div[i]=decomp(i);
}


///MOs Algo - One Trick to Rule all Update-Query Problem
int cnt[N], a[N], ans[N], answer[N];

struct node {
	int L, R, i,val;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
        int x = Div[a[position]];
		ans[x]++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
        int x = Div[a[position]];
		ans[x]--;
	}
}

void clean()
{
    for(int i = 0; i < N; i++ )
    {
        cnt[i] = ans[i] = answer[i] = 0;
    }
}

int main() {

    div_generate();

    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)scanf("%d", &a[i]);

        printf("Case %d:\n",kase);

        int m;
        scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &q[i].L, &q[i].R, &q[i].val);
            q[i].L--;
            q[i].R--;
            q[i].i = i;
        }

        sort(q, q + m, cmp);

        int currentL = 0, currentR = 0;
        for(int i=0; i<m; i++)
        {
            int L = q[i].L, R = q[i].R;
            while(currentL < L) {
                remove(currentL);
                currentL++;
            }
            while(currentL > L) {
                add(currentL-1);
                currentL--;
            }
            while(currentR <= R) {
                add(currentR);
                currentR++;
            }
            while(currentR > R+1) {
                remove(currentR-1);
                currentR--;
            }
            answer[q[i].i] = ans[q[i].val];
        }

        for(int i=0; i<m; i++)printf("%d\n", answer[i]);
        clean();
    }
}


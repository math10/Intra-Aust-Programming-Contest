#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 100005;
bool stat[N];
int phi[N],answer[N];

void siv()
{
    for(int i = 4;i < N;i += 2)stat[i] = 1;
    int sq = sqrt(N);
    for(int i = 3;i <= sq;i++){
        if(stat[i])continue;
        for(int j = i * i;j < N;j += 2 * i)stat[j] = 1;
    }
    for(int i = 1;i < N;i++)phi[i] = i;
    for(int i = 2;i < N;i++){
        if(stat[i])continue;
        for(int j = i;j < N;j += i){
            phi[j]/=i;
            phi[j]*=(i-1);
        }
    }

}

struct data
{
    int l,r,k,id;
}Q[N];
int sq,SQ = 400;
bool cmp(data A,data B)
{
    if(A.l/sq!=B.l/sq)return A.l/sq < B.l/sq;
    return A.r<B.r;
}

int seg[N],mark[N];
void add(int pos)
{
    int v = phi[pos];
    if(mark[v] == 0){
        seg[v/SQ]++;
    }
    mark[v]++;
}
void remove(int pos)
{
    int v = phi[pos];
    mark[v]--;
    if(mark[v] == 0){
        seg[v/SQ]--;
    }
}
int main()
{
    siv();

    int t,cases = 0;
    scanf("%d",&t);

    while(t--){
        MEM(seg,0);
        MEM(mark,0);

        int n,q;
        scanf("%d %d",&n,&q);
        sq = sqrt(n);

        for(int i = 0;i<q;i++){
            int l,r,k;
            scanf("%d %d %d",&l,&r,&k);
            Q[i].l = l;
            Q[i].r = r;
            Q[i].k = k;
            Q[i].id= i;
        }
        sort(Q,Q+q,cmp);

        int mol = 1;
        int mor = 0;

        for(int I = 0;I<q;I++){
            int l = Q[I].l;
            int r = Q[I].r;
            int k = Q[I].k;

            while(mor < r){
                mor++;
                add(mor);
            }
            while(mor > r){
                remove(mor);
                mor--;
            }
            while(mol < l){
                remove(mol);
                mol++;
            }

            while(mol>l){
                mol--;
                add(mol);
            }
            int now = 0;

            for(int i = 0;i < 300;i++){
                if(now + seg[i] < k){
                    now = now + seg[i];
                }else{
                    for(int j = i * SQ; ;j++){
                        if(mark[j] > 0)now++;
                        if(now == k){
                            answer[Q[I].id ] = j;
                            break;
                        }
                    }
                    break;
                }
            }
            if(now != k)answer[Q[I].id ] = -1;
        }
        printf("Case %d:\n",++cases);
        for(int i = 0;i < q;i++){
            if(answer[i] == -1)printf("No Distinct Phi Number\n");
            else printf("%d\n",answer[i]);
        }

    }
}
//0.8 sec

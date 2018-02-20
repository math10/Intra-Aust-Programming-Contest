#include <stdio.h>
#include <algorithm>
using namespace std;

const int block = 555 ;
int arr[100000+10] , cnt[1000000+10] , res[1000000+10] , ans[1000000+10] , divisor[1000000+10] ;

struct Node
{
    int l , r , q , id ;
}V[100000+10];

void sieve()
{
    for(int i=1;i<=1000000;i=i+1)
    {
        for(int j=i;j<=1000000;j=j+i)
        {
            divisor[j]++;
        }
    }
}


bool cmp(Node A,Node B)
{
    if(A.l/block == B.l/block) return A.r < B.r ;
    return A.l/block < B.l/block ;
}

void add(int position)
{
    cnt[arr[position]]++;
    if(cnt[arr[position]]==1) ans[divisor[arr[position]]]++;
}

void remove(int position)
{
    cnt[arr[position]]--;
    if(cnt[arr[position]]==0) ans[divisor[arr[position]]]--;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    sieve();

    int T ;
    scanf("%d",&T);

    for(int cas=1;cas<=T;cas++)
    {
        printf("Case %d:\n",cas);
        int N , Q ; // N is the number of elements and Q is the number queries .
        scanf("%d",&N);

        for(int i=1;i<=N;i++) scanf("%d",&arr[i]);

        scanf("%d",&Q);

        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d%d",&V[i].l,&V[i].r,&V[i].q);
            V[i].id = i ;
        }

        sort(&V[1],&V[Q+1],cmp);

        int currentL = 0 , currentR = 0 ;
        for(int i=1;i<=Q;i++)
        {
            int L = V[i].l , R = V[i].r , X = V[i].q ;
            while(currentL<L)
            {
                if(currentL!=0)remove(currentL);
                currentL++;
            }
            while(currentL>L)
            {
                currentL--;
                add(currentL);
            }
            while(currentR<R)
            {
                currentR++;
                add(currentR);
            }
            while(currentR>R)
            {
                remove(currentR);
                currentR--;
            }
            res[V[i].id]=ans[X];
        }

        for(int i=1;i<=Q;i++) printf("%d\n",res[i]);

        for(int i=0;i<=1000000;i++) cnt[i] = 0 , res[i] = 0 , ans[i] = 0 ;
    }
    return 0;
}


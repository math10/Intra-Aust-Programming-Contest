#include <bits/stdc++.h>
using namespace std;

#define read() freopen("input.txt","r",stdin)
#define INF ((1<<29)-1)
#define EPS (1e-9)
#define PI (2*acos(0.0))
#define ll long long
#define ull unsigned ll
#define SIZE ((ll)1e6)+10
#define testcase ll T;cin>>T;for(int t=1;t<=T;t++)
#define printcase() cout<<"Case "<<t<<":\n"
#define pb push_back
#define PAR_SIZE 1000000+10
#define BFS_GRID 1010
#define NL() cout << endl
#define FOR(itt,n) for(int itt=0;itt<n;++itt)
#define FOR1(itt,n) for(int itt=1;itt<=n;++itt)
#define MAX_PRIME 1000010
#define MUTATION_RATE 100
#define MOD 1000000007


int main()
{
    #ifdef pinanzo
        //read();
        //freopen("output.txt","w",stdout);
    #endif // pinanzo
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //cout.tie(NULL);


    int T, n;
    scanf("%d", &T);

    FOR1(t,T){
        scanf("%d", &n);
        while(n%100!=0)++n;
        int y=n/100;
        printf("Case #%d: ", t);
        if(y==21)printf("21st");
        else if(y==22)printf("22nd");
        else if(y==23)printf("23rd");
        else {
            printf("%dth", y);
        }
        printf(" century!\n");
    }

    return 0;
}

//37046152


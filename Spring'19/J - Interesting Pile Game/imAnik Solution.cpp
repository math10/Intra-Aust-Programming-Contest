
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
vector<int> yMove;
bool dp[MAXN];

int main(){
    int t;
    scanf("%d",&t);

    for(int cs=1; cs<=t; cs++){
        int n,k;
        scanf("%d %d",&n, &k);

        yMove.clear();
        for(int i=1; i<=n; i++) {if(__gcd(i, k) == 1 && (i & k) > 0) yMove.push_back(i);}

        dp[0] = false;
        for(int i=1; i<=n; i++){
            dp[i] = false;
            for(int x : yMove){
                if(x <= i && dp[i - x] == false) dp[i] = true;
            }
        }

        if(dp[n]) printf("Turja\n");
        else printf("Akash\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 7;
double H[mx],freq[mx];
vector<double >v;
int main() {

    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    H[0] = 0;
    for(int i = 1;i<mx;i++){
        H[i] = H[i-1] + 1./i;
    }
    int cnt = 1;
    freq[0] =0;
    for(int i = 2;i<mx;i+=2){
        freq[cnt] = freq[cnt-1] + H[i];
        cnt++;
    }
    int t;
    scanf("%d",&t);
    for(int cs = 1;cs<=t;cs++){
        int n ;
        scanf("%d",&n);
        int tmp = (n+1)/2;
        double ans = tmp*H[n] - freq[tmp-1];
        printf("Case %d: %.4lf\n",cs,ans);
    }

}


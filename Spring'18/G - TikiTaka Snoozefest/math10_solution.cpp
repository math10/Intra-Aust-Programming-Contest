#include<bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 7;
const int MOD = 1e9 + 7;
long long nCr[MAX][MAX];
void make_nCr(){
    nCr[0][0] = 1;
    for(int i = 1; i < MAX; ++i) {
        nCr[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%MOD;
        }
    }
}


int main() {
    make_nCr();
    int t;
    char ch[100];
    scanf("%d", &t);
    for(int cs = 1; cs <= t; ++cs) {
        int l;
        scanf("%d", &l);
        scanf("%s", ch);
        int p,m,n,q;
        scanf("%d %d %d %d", &p, &m, &n, &q);
        int tot = l-1;
        for(int i = 0; i < l; ++i) {
            if(ch[i] == 'D') tot += m;
            else if(ch[i] == 'M') tot += n;
            else if(ch[i] == 'A') tot += q;
        }
        if(tot > p) {
            printf("0\n");
        } else {
            int rem = p - tot;
            --l;
            rem += l;
            long long ans = nCr[rem][l];
            printf("%lld\n",ans);
        }
    }
}


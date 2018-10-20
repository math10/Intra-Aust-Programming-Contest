#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[22];
vector<int >v[22];
int flag[1<<21], c;
stack<int>stk;
bool call(int mask, int pos){
    if(pos == n) return true;
    if(flag[mask] == c) return false;
    flag[mask] = c;
    int sz = v[pos].size();
    for(int i = 0; i < sz; ++i) {
        int a = v[pos][i];
        if(mask & (1<<a)) continue;
        if(call(mask|(1<<a), pos+1)) {
            stk.push(a);
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            for(int j = 1; j <= n; ++j) {
                if(arr[i]%j == 0) v[i].push_back(j);
            }
        }

        ++c;
        printf("Case %d:", cs);
        if(call(0,0)) {
            while(!stk.empty()) {
                printf(" %d", stk.top());
                stk.pop();
            }
        } else {
            printf(" Again Runners-up");
        }
        puts("");
        for(int i = 0; i <n ; ++i) v[i].clear();
    }
}



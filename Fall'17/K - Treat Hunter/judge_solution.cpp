#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const int MAX = 20;
int n, m;
unordered_map <ull, int> used;

ull hashValue(char s[]) {
    int base = 31;
    ull val = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        val = val * base + s [i];
    }
    return val;
}

int main () {
//    freopen("input_4.txt", "r", stdin);
//    freopen("output_4.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d", &n, &m);
        char str [MAX];
        int len = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", &str);
            len = strlen(str);
            sort(str, str + len);
            ull hashval = hashValue(str);
            used [hashval]++;
        }
        printf("Case %d:\n", kase);

        for (int i = 0; i < m; i++) {
            scanf("%s", &str);
            len = strlen(str);
            sort(str, str + len);
            ull hashval = hashValue(str);
            printf("%d\n", n - used[hashval]);
        }
        used.clear();
    }
    return 0;
}


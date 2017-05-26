#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact [20];

void factorial () {
    fact [0] = 1;
    for (ll i = 1; i <= 20; i++) {
        fact [i] = fact [i - 1] * i;
    }
}

int main () {
    factorial ();
    //freopen ("dataset.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll num;
        cin >> num;

        int level = 1;
        while (true) {
            if (num > fact [level]) {
                num -= fact [level];
            } else break;
            level++;
        }

        printf ("Case %d: %d %lld\n", kase, level, num);
    }
    return 0;
}


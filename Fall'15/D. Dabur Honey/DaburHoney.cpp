#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = (int) 1e6;

int phi [MAX + 7];
bool check [MAX + 7];

void sieve_phi () {
    check [1] = true;
    phi [1] = 0;

    for (int i = 2; i <= MAX; i++) {
        if (check [i]) continue;
        phi [i] = i - 1;
        for (int j = 2 * i; j <= MAX; j += i) {
            if (!check [j]) {check [j] = true; phi [j] = j;}
            phi [j] -= phi [j] / i;
        }
    }
}


int main () {
    #ifdef LOCAL
        freopen ("input_D.txt", "r", stdin);
        freopen ("output_D.txt", "w", stdout);
    #endif
    sieve_phi ();

    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int a, b;
        scanf ("%d %d", &a, &b);
        int cp1 = phi [a], cp2 = phi [b];

        printf ("Case %d: ", kase);
        if (cp2 >= cp1) puts ("Swapnil lost it");
        else puts ("Shibli took it");
    }

    return 0;
}



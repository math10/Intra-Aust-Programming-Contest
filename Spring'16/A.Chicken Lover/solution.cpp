#include <bits/stdc++.h>

using namespace std;

int main () {
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        if (n >= 120) cout << "Good Boy Sifat" << endl;
        else cout << "Naughty Boy Sifat" << endl;
    }
    return 0;
}

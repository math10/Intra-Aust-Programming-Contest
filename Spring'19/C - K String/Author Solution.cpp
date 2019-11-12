#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int freq[30];
vector <int> v;
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("large15output.txt","w",stdout);
    int n, k;
    string s;
    cin >> n >> k >> s;
    for ( int i = 0; i < n; ++i ) {
        freq[s[i]-'a']++;
    }
    for ( int i = 0; i < 26; ++i ) {
        if ( freq[i] > 0 ) {
            v.push_back(freq[i]);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int sz = (int)v.size();
    if ( sz <= k ) {
        cout << k - sz << endl;
        return 0;
    }
    int res = 0;
    for ( int i = k; i < sz; ++i ) {
        res += v[i];
    }
    cout << res << '\n';
    return 0;
}

/*

4 3
abcd

Output:
1

5 3
abcdd

Output: 1

*/

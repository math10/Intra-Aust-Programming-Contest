#include "bits/stdc++.h"

using namespace std;

static const int maxn = 100000 + 6;

bool isprime[maxn];
vector <int> prime;

void seive()
{
    memset(isprime, true, sizeof isprime);
    isprime[1] = 0;
    for (int i = 4; i < maxn; i += 2)
        isprime[i] = false;
    for (int i = 3; i*i <= maxn; i+=2)
    {
        if (isprime[i])
        {
            for (int j = i*i; j < maxn; j += i+i)
                isprime[j] = false;
        }
    }
    prime.push_back(2);
    for (int i = 3; i < maxn; i += 2)
    {
        if (isprime[i])
            prime.push_back(i);
    }
}

bool ok(int num)
{
    if (isprime[num] == true)
        return true;
    int len = prime.size();
    int s = num;
    for (int i = 0; i < len; i++)
    {
        s -= prime[i];
        if (isprime[s] && s > prime[i]) return true;
        if (s < 0) break;
    }
    s = num;
    for (int i = 1; i < len; i++)
    {
        s -= prime[i];
        if (isprime[s] && s > prime[i]) return true;
        if (s < 0) break;
    }


    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    seive();
    int tc;
    cin >> tc;
    for (int tcase = 1; tcase <= tc; tcase++)
    {
        int num;
        cin >> num;

        if (ok(num)) cout << "YES\n";
        else cout << "NO\n";
    }
}


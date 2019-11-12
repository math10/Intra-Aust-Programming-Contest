#include<bits/stdc++.h>
using namespace std;

#define MX 1000002
int n, k, freq[27], cnt;
char arr[MX];

int solve()
{
    int sz = cnt - k;
    int res = 0;
    int counter = 0;
    for(int i = 0; i < 26; i++)
    {
        if( freq[i] == 0 )continue;
        else
        {
            res = res + freq[i];
            counter++;
            if(counter >= sz)break;
        }
    }
    //cout<<"res"<<res<<endl;
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", arr);
    cnt = 0;
    for(int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if(freq[ch - 'a'] == 0)cnt++;
        freq[ch - 'a']++;
    }
    if( cnt <= k )printf("%d\n", k-cnt);
    else
    {
        sort(freq, freq+26);
        printf("%d\n", solve());
    }
}


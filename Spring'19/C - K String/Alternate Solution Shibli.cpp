#include<bits/stdc++.h>
using namespace std;

#define MX 1000002
int n, k, freq[27], cnt;
char arr[MX];

bool solve(int ans)
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
    if(res <= ans)return true;
    return false;
}

int bst_the_answer()
{
    int low = 1, high = 10000000, mid, ans = 0, iteration = 30;
    while(iteration--)
    {
        mid = (low+high)>>1;
        //cout<<mid<<endl;
        if(solve(mid))
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
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
        printf("%d\n", bst_the_answer());
    }
}

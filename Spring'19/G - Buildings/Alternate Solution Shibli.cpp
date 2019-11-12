#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 100002
lli arr[MX], k, n;

bool solve(lli res)
{
    lli taka = k;
    for(int i = 0; i < n; i++)
    {
        if( arr[i] < res )taka = taka - (res - arr[i]);
        if( taka < 0 )return false;
    }
    return true;
}

lli bst_the_answer()
{
    lli low = 0, high = 2000000000, mid, ans = 0, iteration = 35;
    while(iteration--)
    {
        mid = (low+high)>>1;
        if(solve(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main()
{
    scanf("%lld %lld",&n, &k);
    for(int i = 0; i < n; i++)scanf("%lld", arr+i);
    sort(arr, arr+n);
    printf("%lld\n", bst_the_answer());
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define Max(a,b) ((a>=b)? a : b)
#define Min(a,b) ((a<=b)? a : b)
#define pb push_back
#define MOD 1000000007
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define MAX 3000010
//typedef __int128 bigll;

struct node{
    long long year;
    long long goal;
}a[100000 + 5];

bool cmp(node x, node y){
    return x.year < y.year;
}


int bin_search(int low, int high,long long year){
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid].year == year){
            return mid;
        }
        else if(a[mid].year > year){
            high = mid - 1;
        }
        else low = mid + 1;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    int t, n, q;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d",&n, &q);
        for(int i = 0; i < n; i++){
            scanf("%lld %lld",&a[i].year, &a[i].goal);
        }
        sort(a, a + n, cmp);
        while(q--){
            long long y;
            scanf("%lld", &y);
            if(n == 1){
                printf("-1 %lld -1\n", a[0].goal);
                continue;
            }
            int index = bin_search(0, n-1, y);

            if(index == 0){
                printf("-1 %lld %lld\n",a[index].goal, a[index + 1].goal);
            }
            else if(index == n-1){
                printf("%lld %lld -1\n",a[index - 1].goal, a[index].goal);
            }
            else{
                printf("%lld %lld %lld\n",a[index -1].goal, a[index].goal, a[index + 1].goal);
            }
        }
    //    if(tc != t){
            printf("\n");
  //      }
    }

    //fclose(f);
    //fclose(o);

    return 0;
}


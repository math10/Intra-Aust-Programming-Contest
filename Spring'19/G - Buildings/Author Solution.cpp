// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , k;
vector<ll>v;

bool possible(ll mid)
{
    ll temp = k;
    for(int i=0;i<v.size();i++){
        if(v[i]<mid){
            temp-=(mid-v[i]);
        }
        if(temp<0)return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    ll hi = 1e10 , low = 0 , mid  , t = 70 , ans = -1;
    while(t--){
        mid = (hi+low)/2;
        cout<<mid<<endl;
        if(possible(mid)==true){
            low = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << endl;

    return 0;
}


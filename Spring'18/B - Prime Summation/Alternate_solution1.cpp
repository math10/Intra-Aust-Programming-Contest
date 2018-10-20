# include <bits/stdc++.h>
using namespace std;

# define MOD 1000000007
# define test(pqpq) rep(te, pqpq)
# define rep(i, n) For(i, 0, n)
# define For(i, a, b) FOR(i, a, b, 1)
# define FOR(i, a, b , c) for(int i = (a); i < (b); i += (c))
# define FOREACH(i, x) for(__typeof__((x).begin())i=(x).begin();i!=(x).end();i++)
# define tbit(a) __builtin_popcount(a)
# define bchk(a, x) ((a)>>(x))&(1)
# define bset(a, x) ((a)|(1<<(x)))
# define bclr(a, x) ((a)&(~(1<<(x))))
# define mem(a) memset(a, 0, sizeof(a))
# define read(x) freopen(#x, "r", stdin)
# define write(x) freopen(#x, "w", stdout)
# define all(x) x.begin(), x.end()
# define faster() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);}

# define dbg(args...)    {string sss(#args);sss+=',';cerr<<"-->";debugger::call(all(sss), args);cerr<<"\n";}
# define dbgA(A, n)      {cerr<<"-->"<<#A<<"=(";rep(i, n)cerr<<A[i]<<" ";cerr<<")\n";}
# define dbgA2(A, n, m)  {cerr<<"-->"<<#A<<"=\n";rep(i, n){rep(j, m){cerr<<setw(4)<<A[i][j]<<" ";}cerr<<"\n";}cerr<<"\n";}

struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it) if(*it!=' ')b+=*it;
        cerr << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};


typedef long long int ll;
typedef unsigned long long int ull;

const double PI = 2.0*acos(0.0);
const double GOLD = (1.0 + sqrt(5.0))/2.0;
const double eps = 1e-9;

const int Max = 100010;
int ar[Max];
vector<int>prime;
map<pair<int, int>, bool>mp;

void seive(){
    FOR(i, 4, Max, 2){
        ar[i] = 1;
    }
    prime.push_back(2);
    ar[0] = ar[1] = 1;
    FOR(i, 3, Max, 2){
        if(ar[i] == 0){
            prime.push_back(i);
            for(ll j = (ll) i * i; j < Max; j+=(2 * i)){
                ar[j] = 1;
            }

        }
    }
}

bool go(int n, int in){
    if(in >= prime.size())
        return false;
    if(mp.count(make_pair(n, in)) != 0)
        return mp[make_pair(n, in)];
    for(int i = in; i < prime.size() && prime[in] <= n; i++){
        if(n == prime[i]){
            return mp[make_pair(n, in)] = true;
        }
        bool x = go(n - prime[i], i + 1);
        if(x == true)
            return mp[make_pair(n, in)] = x;
    }
    return false;
}

int main(){
    seive();
   // dbg(prime.size());
    int te; cin>>te;
    rep(t, te){
        int n; cin>>n;
        if(ar[n] == 0){
            puts("YES");
        }
        else if(go(n, 0)){
            puts("YES");
        }
        else
        puts("NO");
    }
}

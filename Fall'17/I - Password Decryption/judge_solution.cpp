 #include<bits/stdc++.h>
 #define pb push_back
 #define mpp make_pair
 #define PI acos(-1)
 /*************NOTES*********************\
 ***************************************/
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair < int , int > pii;
 const ll inf = 1e9;
 const ll mod = 1e9 + 7;
 const double eps = 1e-8;
 const ll MAX = 1e7 + 20;

 template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
 template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

 /*----------------------Graph Moves----------------*/
 //const int fx[]={+1,-1,+0,+0};
 //const int fy[]={+0,+0,+1,-1};
 //const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
 //const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
 //const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
 //const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
 /*------------------------------------------------*/
 /*-----------------------Bitmask------------------*/
 //int Set(int N,int pos){return N=N  (1<<pos);}
 //int reset(int N,int pos){return N= N & ~(1<<pos);}
 //bool check(int N,int pos){return (bool)(N & (1<<pos));}
 /*------------------------------------------------*/
 ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
 ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

int P[5000005];
pii saveP[5000005];
int csum[5000005];
int k;

bool isVowel(char c ){
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return true;
    return false;
}

string preprocess(string s ){
    string tmp = "^";
    for( int i = 0; i < s.size(); i++ ){
            tmp += "#";
            tmp += s[i];
    }
    tmp += "#$";
    for( int i = 0; i < tmp.size(); i++ ){
        csum[i] = 0;
    }

    int now = 0;
     for( int i = 0; i < tmp.size(); i++ ){
        if( isVowel( tmp[i] ) ){
            now++;
        }
        csum[i] = now;
     }

    return tmp;
}

string longestPalindrome( string s ){
    memset( P, 0, sizeof( 0 ) );
    string T = preprocess(s);
    int sz = T.size();
    int C = 0, R = 0;
    for( int i = 1; i < sz - 1; i++ ){
        int mirror = 2*C - i;
        P[i] = ( R > i ) ? min( R-i, P[mirror] ) : 0;

        while( T[i + 1 + P[i]] == T[i - 1 - P[i]] ){
            int st = i - 1 - P[i];
            int ed = i + 1 + P[i];
            int tot;
            if( st == 0 ) tot = csum[ed];
            else tot = csum[ed] - csum[st-1];
            if( tot <= k )P[i]++;
            else break;
        }
        if( i + P[i] > R ){
            C = i; R = i + P[i];
        }
    }
    for( int i = 0; i < sz - 1; i++ ){
        saveP[i] = mpp( P[i], i );
    }
    sort( saveP, saveP + sz - 1 );
    reverse( saveP, saveP + sz - 1 );
    int mx = saveP[0].first, next = 1;
    string res = "";
    int id = saveP[0].second;
    int val = saveP[0].first;
    string chk = s.substr((id - 1- val ) / 2 , val );
    res = chk;
    while( next < sz - 1 && saveP[next].first == mx ){
        id = saveP[next].second;
        val = saveP[next].first;
        chk = s.substr((id - 1- val ) / 2 , val );
        if( chk < res )res = chk;
        next++;
    }
    return res;
}

 int main ( ){

      #ifdef S0cI0pAtH
     freopen("in.txt","r",stdin );
     freopen("out1.txt","w",stdout );
     #endif // swapnil

     ios_base:: sync_with_stdio( false );
     cin.tie( 0 );
     cout.tie( 0 );



        int ts;
        cin >> ts;
        for( int ks = 1; ks <= ts; ks++ ){
            int n;
            cin >> n >> k;
            string s;
            cin >> s;
            string ans = longestPalindrome(s);
            cout << "Case " << ks << ": ";
            if( ans == "" ){
                cout << "not found\n";
            }else cout << ans << "\n";
        }

     return 0;

 }


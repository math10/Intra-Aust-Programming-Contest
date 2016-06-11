/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

map<char, int>m;
vector<string>vv;
//splits String in space
vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

bool isnumber(string st){
    int len = st.size();
    rep(i,len)if(isdigit(st[i])) return true;
    return false;
}

vector<string >infixToPostfix(){
    stack<string >s;
    vector<string >ans;
    forstl(it,vv){
        string st = *it;
        if(isnumber(st) || st[0] == 'x'){
            ans.push_back(st);
        }else if(st[0] == '('){
            s.push(st);
        }else if(st[0] == ')'){
            while(true){
                st = s.top();
                s.pop();
                if(st[0] == '(') break;
                ans.push_back(st);
            }
        }else{
            while(!s.empty()){
                string tmp = s.top();
                if(tmp[0] != '(' && m[tmp[0]] >= m[st[0]]){
                    ans.push_back(tmp);
                    s.pop();
                }else break;
			}
			s.push(st);
        }
    }

    while(!s.empty()){
        ans.pb(s.top());
        s.pop();
    }

    return ans;
}

//convert String to Integer
int64 toInt(string s){
    int64 r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

db result(db x){
    stack<double >s;
    forstl(it,vv){
        string st = *it;
        if(isnumber(st)){
            s.push(toInt(st));
        }else if(st[0] == 'x')s.push(x);
        else{
            db x2 = s.top();
            s.pop();
            db x1 = s.top();
            s.pop();
            if(st[0] == '+'){
                x1 += x2;
            }
            else if(st[0] == '-'){
                x1 -= x2;
            }
            else if(st[0] == '*'){
                x1 *= x2;
            }
            else if(st[0] == '/'){
                x1 /= x2;
            }
            s.push(x1);
        }
    }

    return s.top();
}

db call1(){
    db low = -100000, high = 100000;
    int it = 100;
    while(it--){
        db mid = (low+high)/2.;
        db a1 = result(mid);
        if(a1 < 0){
            low = mid;
        }else if(a1 > 0){
            high = mid;
        }else if(a1 == 0) return mid;
    }
    return (low+high)/2.;
}

db call2(){
    db low = -100000, high = 100000;
    int it = 100;
    while(it--){
        db mid = (low+high)/2.;
        db a1 = result(mid);
        if(a1 < 0){
            high = mid;
        }else if(a1 > 0){
            low = mid;
        }else if(a1 == 0) return mid;
    }
    return (low+high)/2.;
}

int main() {
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
// if you want + - same priority then m['+'] = 0
// if you want * / same priority then m['/'] = 2
// in that case for same priority ans will be left associative
    m['-'] = 0;
    m['+'] = 1;
    m['*'] = 2;
    m['/'] = 3;
    int t = II;
    For(cs,t){
        string st;
        getline(cin, st);
        vector<string >v = Split(st);

        //simplify
        vv.clear();
        vv.pb("(");
        forstl(it,v){
            string s = *it;
            if(s[0] == '='){
                vv.pb(")");
                vv.pb("-");
                vv.pb("(");
            }else vv.pb(s);
        }
        vv.pb(")");
        vv = infixToPostfix();

        db ans;
        if(result(2) > result(1)){
            ans = call1();
        }else {
            ans = call2();
        }
        OC;
        printf(" %.2lf\n",ans);
    }
}

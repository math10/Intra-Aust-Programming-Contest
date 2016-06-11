//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("inpute.txt", "r", stdin)
#define FO freopen ("outpute.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
bool Operator( char c )
{
    if( c == '(' || c == ')' || c == '^' || c == '/' || c == '+' || c == '-' || c == '*') return 1;
    else return 0;
}


int Value_of_Operator( char ch)
{
    if( ch == '(' || ch == ')' ) return 1;
    else if( ch == '+' || ch == '-' ) return 2;
    else if( ch == '*' ) return 3 ;
    else if( ch == '/' ) return 4 ;
    else return 5 ; // '^' highest priority
}

struct VAR{
	float i;
	VAR() {}
};

struct LINE{//k*x+a
	float a, k;
	VAR* x;

	LINE(){}
	LINE(float a) : a(a), k(0), x(0) {}
	LINE(float xx, VAR& v) : a(0), k(xx), x(&v) {}
};

LINE ADD (LINE A, LINE B){//assumes that A.x == 0 or B.x == 0 or A.x == B.x
	LINE R;
	R.a = A.a + B.a;
	R.k = A.k + B.k;
	if(A.x) R.x = A.x;
	else R.x = B.x;
	return R;
}

LINE MINUS (LINE A, LINE B){//same as +
	LINE R;
	R.a = A.a - B.a;
	R.k = A.k - B.k;
	if(A.x) R.x = A.x;
	else R.x = B.x;
	return R;
}

LINE MULTIPLICATION (LINE A, LINE B){//assumes that A.x == 0 or B.x == 0
	LINE R;
	R.a = A.a * B.a;
	R.k = A.k * B.a + B.k * A.a;
	if(A.x) R.x = A.x;
	else R.x = B.x;
	return R;
}

LINE DIVIDE (LINE A, LINE B){//assumes that B.x == 0
	LINE R;
	R.a = A.a / B.a;
	R.k = A.k / B.a;
	R.x = A.x;
	return R;
}

float EQUAL (LINE A, LINE B){
	LINE C = MINUS( A , B ) ;
	//cout << setprecision(10) << "A.a : " << A.a << " A.k : " << A.k << " B.a : " << B.a << " B.k :" << B.k << endl ;
	//cout << setprecision(10) << " C.a : " << C.a << " C.k : " << C.k << endl ;

	return C.x->i = -C.a/C.k;
}




string ExpressionToPostfixExpression( string inp )
{
    string res = "";
    int sz = inp.size();
    stack < char > op;
    stringstream ss ;
    ss << inp ;
    string now ;
    while( ss >> now )
    {

        if( Operator(now[0]) && now.size() == 1 )
        {
            if( now[0] == ')')
            {
                while( op.top() != '(' )
                {
                    res += ( op.top());
                    res += ' ';
                    op.pop();
                }
                op.pop();
            }
        else {
            while( !op.empty() && now[0] != '(' && Value_of_Operator(op.top()) > Value_of_Operator(now[0]))
            {
                res += ( op.top() );
                res += ' ';
                op.pop();
            }

            op.push(now[0]);
            }
        }
        else res += ( now + ' ' );
    }
    while( !op.empty() )
    {

        res += ( op.top());
        res += ' ';
        op.pop();
    }

    return res ;

}

bool Isnumber( string one)
{
    if( one[0] >= '0' && one[0] <= '9' ) return 1 ;
    else if( one.size() > 1 && one[1] >= '0' && one[1] <= '9' ) return 1 ;
    else return 0 ;
}

float toFloat ( string s )
{
    float r = 0 ;
    istringstream sin(s);
    sin >> r ;
    return r;
}

LINE solve ( string exp )
{
    VAR x ;
	stack < LINE > st ;
    stringstream ss ;
    ss << exp ;
    string now ;
    while( ss >> now )
    {
         if( Operator(now[0]) && now.size() == 1 )
         {

             LINE two = st.top();
             st.pop();
             LINE one = st.top();
             st.pop();
             if( now[0] == '+' ) st.push( ADD(one,two) );
             else if( now[0] == '-') st.push( MINUS(one,two));
             else if( now[0] == '*') st.push( MULTIPLICATION(one,two));
             else st.push( DIVIDE(one,two));
         }
         else
         {
            if( Isnumber(now) )
            {
                st.push( LINE(toFloat(now)) );
            }
            else
            {
                if( now[0] == 'x' ) // only small case letter
                {
                    st.push( LINE( 1 , x));
                }
                else st.push(LINE(-1 , x));


            }


        }
    }
    return st.top();

}

string now[5] , inp;



int main(){
    FI;
    //FO;
	int t = II ;
	for( int cs = 1 ; cs <= t ; cs++ )
    {


    getline( cin , inp );

    int sz = inp.size();
    int idx = 0 ;
    now[0] = now[1] = "" ;
    for( int i = 0 ; i < sz ; i++ )
    {
    	if( inp[i] == '=' )
    	{
    		idx++;
    	}
    	else now[idx] += inp[i];
    }

    string ExpressionOne = ExpressionToPostfixExpression( now[0] );
    string ExpressionTwo = ExpressionToPostfixExpression( now[1] );
    printf("Case %d: x = %.2f\n",cs , EQUAL(solve(ExpressionTwo) , solve(ExpressionOne) ) );
    }

	return 0;
}

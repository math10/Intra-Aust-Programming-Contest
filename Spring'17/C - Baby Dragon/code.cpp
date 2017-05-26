#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
#define Min(a,b) ((a<=b) ? a : b)
#define Max(a,b) ((a>=b) ? a : b)
#define pb push_back
#define MP make_pair
typedef pair < int , int >  pii;
#define vi vector<int>
#define pii pair< int,int >
#define vll vector<ll>
#define MAX 10010999// sqrt of MAX
#define MOD 1000000007
#define LMT 10000 // sqrt of MAX
#define LEN 5761465 // MAX primes that can be within range
#define RNG 100032 //
#define sq( x ) ( x * x )
#define chkC(x,n) ( x[n>>6] &  ( 1<<(( n>>1 ) &31)))
#define setC(x,n) ( x[n>>6] |= ( 1<<(( n>>1 ) &31)))
#define ff first
#define ss second
#define MAXNODE 10100
#define MAXLEN 100
#define vc vector<char>



int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   // FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    long double u ;//= 999999999999999999;
    long double a ;//= 999999999999999999;
    long double s ;//= 999999999999999999;
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>u>>a>>s;
        long double v = u*u + 2*a*s;
        v = sqrt(v);
        v -= u;
        v /= a;
        cout<< "Case "<<tc++<< ": ";
            cout << setprecision(6) << fixed;
        cout << v << endl;
    }

    //fclose(f);
    //fclose(o);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int cs = 1;cs<=t;cs++){
        double a;
        cin >> a;
        double b = a/2.;
        double c = a*a - b*b;
        c = sqrt(c);
        c /= 3.;
        printf("Case %d: %.4lf\n",cs,c);
    }
}

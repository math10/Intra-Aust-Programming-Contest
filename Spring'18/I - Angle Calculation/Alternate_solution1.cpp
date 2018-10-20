
C++
#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const long double PI = acos(-1);

int t, cs; double x;

int main() {
  cin >> t;
  while (t--) {
    cin >> x; x = x * PI / 720.0;
    long double cot = tan(5 * x) + 1 / (2 * sin(x) * cos(5 * x));
    long double ang = atan(1 / cot) * 180.0 / PI;
    printf("Case %d: %0.2f\n", ++cs, (double) ang);
  }
  return 0;
}


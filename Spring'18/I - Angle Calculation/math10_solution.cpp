#include<bits/stdc++.h>
using namespace std;

#define PI (2*acos(0.0))

int main()
{
    int t;
    cin>>t;
    for(int kase = 1; kase <= t; kase++ )
    {
        int ABCd;
        cin>>ABCd;

        double ABC = ABCd*1.00;
        ABC = ABC / 2.00;
        double take = ABC;

        ABC = ABC*PI*1.00;
        ABC = ABC/180.00;

        //cout<<sin(2.0*ABC)<<endl;
        //cout<<2.0*(cos(ABC))<<endl;
        //cout<<cos(2.0*ABC)<<endl;

        double theta = sin(2.0*ABC)/(2.0*(cos(ABC)) - cos(2.0*ABC));
        //cout<<theta<<endl;
        double angle = atan(theta);
        angle = angle*180.00;
        angle = (angle*1.00)/PI;

        printf("Case %d: %0.2lf\n",kase, angle  - take );
    }

}


#include<bits/stdc++.h>
using namespace std;

#define PI (2*acos(0.0))

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;

    for(int kase = 1; kase <= t; kase++ )
    {
        double ABC;
        cin>>ABC;

        double ABE,CBE,BAE;
        ABE = CBE = BAE = 0.0;

        ABE = CBE = BAE = (ABC*1.00)/2.00;
        //printf("%0.5lf\n",ABE);
        //cout<<ABE<<endl;

        double AEB = 180.00 - (BAE + ABE);
        //cout<<AEB<<endl;
        double BEC = ((180.00 - CBE)*1.00)/2.00;
        double BCE = BEC;
        //cout<<BCE<<endl;
        double AEC = 360.00 - (BEC + AEB);
        //cout<<AEC<<endl;

        //double C = 45.00*PI;
        //C = C/180.00;
        //cout<<sin(C)<<endl;

        CBE = CBE*PI*1.00;
        CBE = CBE/180.00;

        BEC = BEC*PI*1.00;
        BEC = BEC/180.00;

        double CE = sin(CBE)/sin(BEC);
        //cout<<CE<<endl;

        AEC = AEC*PI*1.00;
        AEC = AEC/180.00;
        double AC_square = 1*1 + CE*CE - 2*CE*cos(AEC);
        double AC = sqrt(AC_square);

        //cout<<AC<<endl;

        double CAE = CE*sin(AEC);
        CAE = (CAE*1.00)/AC;
        //cout<<CAE<<endl;

        CAE = asin(CAE);
        CAE = CAE*180.00;
        CAE = (CAE*1.00)/PI;
        //cout<<CAE<<endl;

        printf("Case %d: %0.2lf\n",kase,CAE);
        //cout<<fixed<<setprecision(2)<<CAE<<endl;
    }
}


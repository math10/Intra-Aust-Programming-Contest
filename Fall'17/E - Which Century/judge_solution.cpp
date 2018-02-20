#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define Max(a,b) ((a>=b)? a : b)
#define Min(a,b) ((a<=b)? a : b)
#define pb push_back
#define MOD 1000000000
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define MAX 32001
//typedef __int128 bigll;


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
   // FILE*o=freopen("output.txt","w",stdout);
    int t,y;
    cin>>t;
    int tc=1;
    while(t--)
    {
        cin>>y;
        int x;
        if(y<=500)cout<< "Case #"<<tc++<< ": 5th century!"<<endl;
        else if(y<=600)cout<< "Case #"<<tc++<< ": 6th century!"<<endl;
        else if(y<=700)cout<< "Case #"<<tc++<< ": 7th century!"<<endl;
        else if(y<=800)cout<< "Case #"<<tc++<< ": 8th century!"<<endl;
        else if(y<=900)cout<< "Case #"<<tc++<< ": 9th century!"<<endl;
        else if(y<=1000)cout<< "Case #"<<tc++<< ": 10th century!"<<endl;
        else if(y<=1100)cout<< "Case #"<<tc++<< ": 11th century!"<<endl;
        else if(y<=1200)cout<< "Case #"<<tc++<< ": 12th century!"<<endl;
        else if(y<=1300)cout<< "Case #"<<tc++<< ": 13th century!"<<endl;
        else if(y<=1400)cout<< "Case #"<<tc++<< ": 14th century!"<<endl;
        else if(y<=1500)cout<< "Case #"<<tc++<< ": 15th century!"<<endl;
        else if(y<=1600)cout<< "Case #"<<tc++<< ": 16th century!"<<endl;
        else if(y<=1700)cout<< "Case #"<<tc++<< ": 17th century!"<<endl;
        else if(y<=1800)cout<< "Case #"<<tc++<< ": 18th century!"<<endl;
        else if(y<=1900)cout<< "Case #"<<tc++<< ": 19th century!"<<endl;
        else if(y<=2000)cout<< "Case #"<<tc++<< ": 20th century!"<<endl;
        else if(y<=2100)cout<< "Case #"<<tc++<< ": 21st century!"<<endl;
        else if(y<=2200)cout<< "Case #"<<tc++<< ": 22nd century!"<<endl;
        else if(y<=2300)cout<< "Case #"<<tc++<< ": 23rd century!"<<endl;
        else if(y<=2400)cout<< "Case #"<<tc++<< ": 24th century!"<<endl;
        else if(y<=2500)cout<< "Case #"<<tc++<< ": 25th century!"<<endl;

    }
    //fclose(f);
    //fclose(o);

    return 0;
}


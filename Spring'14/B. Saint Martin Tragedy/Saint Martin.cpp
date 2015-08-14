#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s ;
    int t ;
    cin >> t ;
    getchar();
    while(t--){
        getline(cin,s) ;
        if( s == "bappi" )       cout <<  "a great athlete" << endl ;
        else if( s == "sabbir" ) cout <<  "a great photographer" << endl;
        else if( s == "noman"  ) cout <<  "the style icon" << endl;
        else if( s == "uday"   ) cout <<  "an extra ordinary person" << endl;
        else if( s == "evan"   ) cout <<  "a kind and helpful person" << endl;
        else if( s == "ankur"  ) cout <<  "the best player" << endl;
    }
    puts("we will never forget you");
}


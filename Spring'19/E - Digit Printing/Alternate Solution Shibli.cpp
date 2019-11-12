#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

struct node
{
    vector<string>V;

}arr[10];

void zero()
{
    arr[0].V.push_back("***");
    arr[0].V.push_back("* *");
    arr[0].V.push_back("* *");
    arr[0].V.push_back("* *");
    arr[0].V.push_back("***");
}

void one()
{
    arr[1].V.push_back(" * ");
    arr[1].V.push_back(" * ");
    arr[1].V.push_back(" * ");
    arr[1].V.push_back(" * ");
    arr[1].V.push_back(" * ");
}

void two()
{
    arr[2].V.push_back("***");
    arr[2].V.push_back("  *");
    arr[2].V.push_back("***");
    arr[2].V.push_back("*  ");
    arr[2].V.push_back("***");
}

void three()
{
    arr[3].V.push_back("***");
    arr[3].V.push_back("  *");
    arr[3].V.push_back("***");
    arr[3].V.push_back("  *");
    arr[3].V.push_back("***");
}

void four()
{
    arr[4].V.push_back("* *");
    arr[4].V.push_back("* *");
    arr[4].V.push_back("***");
    arr[4].V.push_back("  *");
    arr[4].V.push_back("  *");
}

void five()
{
    arr[5].V.push_back("***");
    arr[5].V.push_back("*  ");
    arr[5].V.push_back("***");
    arr[5].V.push_back("  *");
    arr[5].V.push_back("***");
}

void six()
{
    arr[6].V.push_back("***");
    arr[6].V.push_back("*  ");
    arr[6].V.push_back("***");
    arr[6].V.push_back("* *");
    arr[6].V.push_back("***");
}

void seven()
{
    arr[7].V.push_back("***");
    arr[7].V.push_back("  *");
    arr[7].V.push_back("  *");
    arr[7].V.push_back("  *");
    arr[7].V.push_back("  *");
}

void eight()
{
    arr[8].V.push_back("***");
    arr[8].V.push_back("* *");
    arr[8].V.push_back("***");
    arr[8].V.push_back("* *");
    arr[8].V.push_back("***");
}

void nine()
{
    arr[9].V.push_back("***");
    arr[9].V.push_back("* *");
    arr[9].V.push_back("***");
    arr[9].V.push_back("  *");
    arr[9].V.push_back("  *");
}

void pre_process()
{
    zero();
    one();
    two();
    three();
    four();
    five();
    six();
    seven();
    eight();
    nine();
}

int main()
{
    pre_process();
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++)
    {
        lli a, b, ans;
        char ch;
        scanf("%lld %c %lld", &a,&ch,&b);

        if( ch == '+')ans = a+b;
        else if(ch == '-')ans = a-b;
        else if(ch == '*')ans = a*b;

        if( ans < 0 )ans = ans*(-1);
        string res = to_string(ans);

        int len = res.size();
        vector<string>output;
        printf("Case #%d:\n",kase);
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < arr[res[i] - '0'].V.size(); j++)
            {
                if( i > 0 )output[j] = output[j] + " " + arr[res[i] - '0'].V[j];
                else output.push_back(arr[res[i] - '0'].V[j]);
            }
        }
        for(int i = 0; i < output.size(); i++ )cout<<output[i]<<endl;
        if(kase != t)puts("");
    }
}


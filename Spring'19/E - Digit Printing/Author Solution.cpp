#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

vector <vector <string> > digits;

void initDigits()
{
    // create 3 * 5 matrix for each digit
    vector <string> tempDigit;
    // zero

    tempDigit.push_back("***");
    tempDigit.push_back("* *");
    tempDigit.push_back("* *");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();

    // one
    tempDigit.push_back(" * ");
    tempDigit.push_back(" * ");
    tempDigit.push_back(" * ");
    tempDigit.push_back(" * ");
    tempDigit.push_back(" * ");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // two
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("***");
    tempDigit.push_back("*  ");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // three
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // four
    tempDigit.push_back("* *");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("  *");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // five
    tempDigit.push_back("***");
    tempDigit.push_back("*  ");
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // six
    tempDigit.push_back("***");
    tempDigit.push_back("*  ");
    tempDigit.push_back("***");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // seven
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("  *");
    tempDigit.push_back("  *");
    tempDigit.push_back("  *");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // eight
    tempDigit.push_back("***");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");

    digits.push_back(tempDigit);
    tempDigit.clear();
    // nine
    tempDigit.push_back("***");
    tempDigit.push_back("* *");
    tempDigit.push_back("***");
    tempDigit.push_back("  *");
    tempDigit.push_back("  *");

    digits.push_back(tempDigit);
    tempDigit.clear();

}

int main()
{
    //FILE*o=freopen("input.txt","r",stdin);
    //FILE*f=freopen("output.txt", "w", stdout);

    initDigits();
    int t, a, b;
    char x;
    int cases = 0;
    cin >> t;
    while(t--)
    {
        cin >> a >> x >> b;
        if(x == '+') a = abs(a + b);
        else if(x == '-') a = abs(a - b);
        else if(x == '*') a = abs(a * b);
        vector<int> dig;
        if(a == 0)
            dig.push_back(0);
        while(a)
        {
            dig.push_back(a % 10);
            a /= 10;
        }
        reverse(dig.begin(), dig.end());

        cout << "Case #" << ++cases << ":" << endl;

        vector <string> output;

        for(int i = 0; i < dig.size(); i++)
        {
            vector <string> d = digits[dig[i]];
            for(int j = 0; j < d.size(); j++)
            {
                if(i > 0)
                {
                    output[j] += ' ' + d[j];
                }
                else
                    output.push_back(d[j]);
            }
        }

        for(int i = 0; i < output.size(); i++)
            cout << output[i] << endl;
    }
    //fclose(o);
    //fclose(f);
    if(t >= 0 )printf("\n");
}



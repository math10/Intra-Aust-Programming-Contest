#include<bits/stdc++.h>
using namespace std;

void print1(int kase,int ans)
{
    printf("Case #%d: %dth century!\n",kase,ans);
}

void print2(int kase,int ans)
{
    printf("Case #%d: %dst century!\n",kase,ans);
}

void print3(int kase,int ans)
{
    printf("Case #%d: %dnd century!\n",kase,ans);
}

void print4(int kase,int ans)
{
    printf("Case #%d: %drd century!\n",kase,ans);
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        int y;
        scanf("%d",&y);

        if( y == 500 )print1(kase,5);
        else if( y >= 501 && y <= 600 )print1(kase,6);
        else if( y >= 601 && y <= 700 )print1(kase,7);
        else if( y >= 701 && y <= 800 )print1(kase,8);
        else if( y >= 801 && y <= 900 )print1(kase,9);
        else if( y >= 901 && y <= 1000 )print1(kase,10);
        else if( y >= 1001 && y <= 1100 )print1(kase,11);
        else if( y >= 1101 && y <= 1200 )print1(kase,12);
        else if( y >= 1201 && y <= 1300 )print1(kase,13);
        else if( y >= 1301 && y <= 1400 )print1(kase,14);
        else if( y >= 1401 && y <= 1500 )print1(kase,15);
        else if( y >= 1501 && y <= 1600 )print1(kase,16);
        else if( y >= 1601 && y <= 1700 )print1(kase,17);
        else if( y >= 1701 && y <= 1800 )print1(kase,18);
        else if( y >= 1801 && y <= 1900 )print1(kase,19);
        else if( y >= 1901 && y <= 2000 )print1(kase,20);
        else if( y >= 2001 && y <= 2100 )print2(kase,21);
        else if( y >= 2101 && y <= 2200 )print3(kase,22);
        else if( y >= 2201 && y <= 2300 )print4(kase,23);
        else if( y >= 2301 && y <= 2400 )print1(kase,24);
        else if( y >= 2401 && y <= 2500 )print1(kase,25);
    }

}


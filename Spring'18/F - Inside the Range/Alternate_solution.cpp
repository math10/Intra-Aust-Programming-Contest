#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,k,t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d %d %d",&x, &k, &y);

        int maxx = max(x,y);
        int minn = min(x,y);

        if( k == maxx || k == minn )printf("case #%d: Nah!!\n",kase);
        else
        {
            if( k > minn && k < maxx )printf("case #%d: Yeah!\n",kase);
            else printf("case #%d: Nah!!\n",kase);
        }
    }

}


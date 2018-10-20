#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    int t,x,y,k;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d %d",&x,&k,&y);
        if(x > y)swap(x,y);
        if(x < k && k < y) printf("case #%d: Yeah!\n",tc);
        else printf("case #%d: Nah!!\n",tc);
    }
   // fclose(f);
    // fclose(o);

    return 0;
}


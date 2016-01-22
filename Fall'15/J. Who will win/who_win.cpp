#include <stdio.h>
#include <stdlib.h>


int main (){

    int t,i,a,b,c,x,y,z,s1,s2;
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&t);

    for( i = 0 ; i < t ; i ++ ){

        scanf("%d%d%d",&a,&b,&c);
        scanf("%d%d%d",&x,&y,&z);

        s1 = a + b + c;
        s2 = x + y + z;

        if(s1 > s2) printf("Akash\n");
        else if (s1 < s2)printf("Imran\n");
        else printf("Draw\n");

    }


    return 0;
}

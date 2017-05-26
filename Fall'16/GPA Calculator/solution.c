#include<stdio.h>
int main(){
    float sum,p;
    int testcase,i,t,n;
    //freopen("my.txt","r",stdin);
    scanf("%d",&testcase);
    for( t = 1; t <= testcase; t++ ){
        scanf("%d",&n);
        sum = 0;
        for( i = 1; i <= n; i++ ){
            scanf("%f",&p);
            sum += p;
        }
        printf("Case %d: %0.3f\n",t,sum/n);
    }

return 0;
}

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef struct
{
    int base;
    int height;
} shape;

shape triangle[40];

double calculate_radius(int ind)
{
    int b = triangle[ind].base;
    int h = triangle[ind].height;
    double x = (double)sqrt(h*h*4 + b*b)/2;
    double r = (double)(b * h)/(2 * x + b);
    return r;

}

int main ()
{

    int i,j,t,n;
    //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);

    for( i = 1 ; i <= t ; i ++ )
    {

        scanf("%d",&n);
        for(j = 1 ; j <= n ; j ++ )
        {
            scanf("%d %d",&triangle[j].base, &triangle[j].height);
        }
        double mini = 1 << 30;

        for(j = 1 ; j <= n ; j ++ )
        {
            double v = calculate_radius(j);
            if(mini > v)
            {
                mini = v;
            }
        }

        printf("Case %d: %.3lf\n",i,mini);


    }

    return 0;
}

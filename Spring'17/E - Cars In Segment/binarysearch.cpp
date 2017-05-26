#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>pos;
int right_index(int x, int y, int t ){

    int res = -1,low,high,mid;
    low = 0;
    high = pos.size()-1;
    while( low <= high ){
        mid = (low+high)/2;
        if(pos[mid]+t >= x && pos[mid]+t <= y){
            res = mid;
            low = mid + 1;
        }
        else if( pos[mid] + t < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}
int left_index(int x, int y,int t ){

    int low,high,mid,res = -1;
    low = 0;
    high = pos.size()-1;
    while( low <= high ){
        mid = (low+high)/2;
        if(pos[mid]+t >= x && pos[mid]+t <= y){
            res = mid;
            high = mid - 1;
        }
        else if( pos[mid] + t < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}
int main(){

    int n,q,l,r,testcase,x,y,z,i;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //clock_t begin = clock();
    scanf("%d",&testcase);
    for( int t = 1; t <= testcase; t++ ){
        scanf("%d%d",&n,&q);
        pos.clear();
        for( i = 1; i <= n; i++ ){
            scanf("%d",&x);
            pos.push_back(x);
        }
        sort(pos.begin(),pos.end());
        printf("Case %d:\n",t);
        while(q--){
            scanf("%d%d%d",&x,&y,&z);
            l = left_index(x,y,z);
            r = right_index(x,y,z);
            if( l != -1 ){
                printf("%d\n",r-l+1);
            }
            else{
                printf("0\n");
            }
        }
    }
    //clock_t end = clock();
    //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cout<<time_spent<<endl;
return 0;
}

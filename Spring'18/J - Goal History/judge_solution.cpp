
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
    long long year;
    long long goal;
    node(long long a, long long b){
        year = a;
        goal = b;
    }
    bool operator <(const node& p)const{
        return year < p.year;
    }
};
vector<node>data;
long long binarySearch(long long num){
    long long l = 0;
    long long r = data.size()-1;
    long long mid;
    while( l <= r ){
        mid = (l+r)/2;
        if(data[mid].year == num) return mid;
        if(data[mid].year > num) r = mid-1;
        else l = mid+1;
    }
}
int main(){

    long long n,q,i,testcases,a,b,num;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    scanf("%lld",&testcases);
    for(int t = 1; t <= testcases; t++){
        data.clear();
        scanf("%lld%lld",&n,&q);
        for( i = 1; i <= n; i++){
            scanf("%lld%lld",&a,&b);
            data.push_back(node(a,b));
        }
        sort(data.begin(),data.end());
        while(q--){
            scanf("%lld",&num);
            int ind = binarySearch(num);
            if(ind == 0) a = -1;
            else a = data[ind-1].goal;
            if(ind == n-1) b = -1;
            else b = data[ind+1].goal;
            printf("%lld %lld %lld\n",a,data[ind].goal,b);
        }
        printf("\n");
    }
return 0;
}

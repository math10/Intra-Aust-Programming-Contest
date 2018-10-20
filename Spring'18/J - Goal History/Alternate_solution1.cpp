
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
struct node{
    long long year;
    int goal;
    node(long long a, int b){
        year = a;
        goal = b;
    }
    bool operator <(const node& p)const{
        return year < p.year;
    }
};
vector<node>data;
map<long long,int>mymap;
int main(){

    int n,q,i,testcases,b,c;
    long long a,num;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    scanf("%d",&testcases);
    for(int t = 1; t <= testcases; t++){
        mymap.clear();
        data.clear();
        scanf("%d%d",&n,&q);
        for( i = 1; i <= n; i++){
            scanf("%lld%d",&a,&b);
            data.push_back(node(a,b));
        }
        sort(data.begin(),data.end());
        for(int i = 0; i < n; i++){
            mymap[data[i].year] = i;
        }
        while(q--){
            scanf("%lld",&num);
            int ind = mymap[num];
            if(ind == 0) b = -1;
            else b = data[ind-1].goal;
            if(ind == n-1) c = -1;
            else c = data[ind+1].goal;
            printf("%d %d %d\n",b,data[ind].goal,c);
        }
        printf("\n");
    }
return 0;
}

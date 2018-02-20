#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct node{
    bool right;
    int child;
    node( bool a,int b){
        right = a;
        child = b;
    }
};
queue<node>q;
map<int,int>mymap;
int main(){
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int num,n,testcase,i,cnt,counter,val=1;
    counter = 1,num = 1;
    while( counter <= 10000 ){
        mymap[counter] = val++;
        num = num*2;
        counter = counter + num;
    }
    bool flag;
    while(scanf("%d",&n) == 1){
        q.push(node(false,n));
        counter = 0;
        while(!q.empty()){
            node temp = q.front();
            q.pop();
            num = temp.child;
            num--;
            cnt = num/2;
            for( i = 1; i <= cnt; i++ ){
                printf("-");
            }
            if( temp.right ){
                printf("-");
            }
            printf("O");
            if(cnt){
                flag = temp.right;
                q.push(node(flag,cnt));
                q.push(node(true,cnt));
            }
            counter++;
            if(mymap.find(counter) != mymap.end()){
                printf("\n");
            }
            else{
                for( i = 1; i <= cnt; i++){
                    printf("-");
                }
            }
        }
        printf("\n");
    }
return 0;
}


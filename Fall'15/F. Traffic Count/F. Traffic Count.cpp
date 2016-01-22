#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int L , R , t1 , t2 , id ;
}Q[100000+10];
const int block = 555 , range = 10000001 ;
int input[100000+10] , res[100000+10] , bit[10000000+10] , N ;
bool cmp(Node A , Node B)
{
    if(A.L/block==B.L/block) return A.R < B.R ;
    else return A.L/block < B.L/block ;
}
void update(int idx,int val)
{
    for(idx;idx<=range;idx=idx+(idx&-idx)) bit[idx]+=val;
}
int query(int idx)
{
    int sum = 0 ;
    for(idx;idx>0;idx=idx-(idx&-idx)) sum+=bit[idx];
    return sum ;
}
void add(int index)
{
    update(input[index],1);
}
void remove(int index)
{
    update(input[index],-1);
}
int main()
{
    //freopen("input_F.txt","r",stdin);
    //freopen("output_F.txt","w",stdout);
    int test ;
    scanf("%d",&test);
    for(int cas=1;cas<=test;cas++)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&input[i]);
            input[i]++;
        }
        int q ;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d%d%d",&Q[i].L,&Q[i].R,&Q[i].t1,&Q[i].t2);
            Q[i].L++;Q[i].R++;Q[i].t1++;Q[i].t2++;
            Q[i].id = i ;
        }
        sort(&Q[1],&Q[q+1],cmp);
        int currentL = 0 , currentR = 0 ;
        for(int i=1;i<=q;i++)
        {
            int l = Q[i].L , r = Q[i].R ;
            while(currentL<l)
            {
                if(currentL!=0)remove(currentL);
                currentL++;
            }
            while(currentL>l)
            {
                currentL--;
                add(currentL);
            }
            while(currentR<r)
            {
                currentR++;
                add(currentR);
            }
            while(currentR>r)
            {
                remove(currentR);
                currentR--;
            }
            res[Q[i].id]=query(Q[i].t2)-query(Q[i].t1-1) ;
        }
        printf("Case %d:\n",cas);
        for(int i=1;i<=q;i++) printf("%d\n",res[i]);
        fill(bit,bit+10000005,0);
    }
    return 0;
}

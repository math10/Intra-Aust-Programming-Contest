#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update>ordered_set;
ordered_set st;
const int N=1e6;
const int sq=320;
int phi[N+2],fr[N+2],ans[12][N+2],qq[N+2];
void PHI(int n)
{
  for(int i=1;i<=n;i++)
  {
    phi[i]+=i;
    for(int j=i+i;j<=n;j+=i)
      phi[j]-=phi[i];
  }
}
struct query
{
  int ts,lt,rt,k,id;
};
bool cmp(query a,query b)
{
  if(a.lt/sq!=b.lt/sq)return a.lt<b.lt;
  return a.rt<b.rt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("inp.txt","r",stdin);
  //freopen("alg.txt","w",stdout);
  PHI(N);vector<query>v;
  /*for(int i=1;i<=10;i++)
    cout<<phi[i]<<" ";
  cout<<endl;*/
  int t;cin>>t;
  for(int tc=1;tc<=t;tc++)
  {
    int n,q;cin>>n>>q;qq[tc]=q;
    for(int i=1;i<=q;i++)
    {
      query qr;cin>>qr.lt>>qr.rt>>qr.k;
      qr.ts=tc,qr.id=i;
      v.push_back(qr);
    }
  }
  sort(v.begin(),v.end(),cmp);

  int pl=1,pr=0;
  for(auto x:v)
  {
    int nl=x.lt,nr=x.rt;
    for(int i=nl;i<pl;i++)
    {
      fr[phi[i]]++;
      if(fr[phi[i]]==1)st.insert(phi[i]);
    }
    for(int i=pr+1;i<=nr;i++)
    {
      fr[phi[i]]++;
      if(fr[phi[i]]==1)st.insert(phi[i]);
    }
    for(int i=pl;i<nl;i++)
    {
      fr[phi[i]]--;
      if(fr[phi[i]]==0)st.erase(phi[i]);
    }
    for(int i=nr+1;i<=pr;i++)
    {
      fr[phi[i]]--;
      if(fr[phi[i]]==0)st.erase(phi[i]);
    }
    if(st.size()<x.k)ans[x.ts][x.id]=-1;
    else ans[x.ts][x.id]=*st.find_by_order(x.k-1);
    pl=nl,pr=nr;
  }
  for(int i=1;i<=t;i++)
  {
    cout<<"Case "<<i<<":\n";
    for(int j=1;j<=qq[i];j++)
    {
      if(ans[i][j]==-1)cout<<"No Distinct Phi Number\n";
      else cout<<ans[i][j]<<"\n";
    }
  }
  return 0;
}
//2.3 sec

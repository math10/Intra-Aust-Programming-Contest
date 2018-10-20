#include<bits/stdc++.h>

#define MAX 1010

using namespace std;

int mod = 1000000007;
int dp[MAX][MAX];
int A, B, C, P, M, N, Q, L;
char inits[] = {'D', 'M', 'A'};
char movestring[100];
int T;

void build_dp()
{

dp[0][0]= dp[1][0] = dp[1][1] = 1;

for(int i=2;i<MAX;i++)
  {
  dp[i][0] = dp[i][i] = 1;

  for(int j=1;j<i;j++)
     dp[i][j]= (dp[i-1][j]+dp[i-1][j-1])%mod;


  }

}

int find_ans()
{
int result;
A = B = C = 0;

for(int i=0;i<L;i++)
  {
  char c = movestring[i];
  if(c=='D')A++;
  else if(c=='M')B++;
  else if(c=='A')C++;


  }
int X = P- A*M - B*N - C*Q;
int Y = L-1;
if(X<Y) result = 0;
else result = dp[X][Y];
//printf("%d %d %d %d %d %s\n",P,L,A,B,C,movestring);
//printf("%d %d %d\n",M,N,Q);

return result;

}

int main()
{
build_dp();

scanf("%d",&T);
for(int i=0;i<T;i++)
{

scanf("%d\n",&L);
gets(movestring);
scanf("%d %d %d %d",&P,&M,&N,&Q);

printf("%d\n",find_ans());

}

return 0;

}




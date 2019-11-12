#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
int freq[maxn];
long long sum = 0;
long long arr[200100];
long long cnt[maxn], n, Q, block;
int bit[maxn];
int  prime[1000006] , phi[maxn];

void seive(int n = 100010) {
    int i,j;
    for(i=1; i<=n; i++) phi[i]=i;
    phi[1]=1;
    prime[1]=1;
    for(i=2; i<=n; i++){
        if(!prime[i]){
            for(j=i;j<=n; j+=i){
                prime[j+i]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(int i = 0; i<n; i++){
        arr[i] = phi[i+1];
    }
}


void update(int ind , int val){
    while(ind < maxn){bit[ind] += val ; ind += (ind & (-ind));}
}
int query(int ind , int sum = 0){
    while(ind > 0){sum += bit[ind] ; ind -= (ind & (-ind));}
    return sum;
}

struct query{
	int l, r, id , k;
	bool operator < ( const query& p) const {
		int a = l/block, b = p.l / block;
		return a==b? r < p.r : a < b;
	}
} q[200100];
void add(long long x) {
	freq[x]++;
	if(freq[x] == 1){
        update(x , 1);
	}
}
void remove(long long x) {
	freq[x]--;
	if(freq[x] == 0){
        update(x,-1);
	}
}
void solve() {
    memset(bit,0,sizeof bit);
    memset(freq,0,sizeof freq);
	scanf("%d %d", &n, &Q);
	block = sqrt(n)+1;
	for(int i=0; i<Q; i++) {
		scanf("%d %d %d", &q[i].l, &q[i].r,&q[i].k);
		q[i].l--, q[i].r--;
		q[i].id = i;
	} sort(q, q+Q);
	vector<long long> ans(Q, 0);
	int l = 0, r = -1;
	for(int i=0; i<Q; i++) {
		while(l > q[i].l) add(arr[--l]);
		while(r < q[i].r) add(arr[++r]);
		while(r > q[i].r) remove(arr[r--]);
		while(l < q[i].l) remove(arr[l++]);
		int lo = 1 , hi = n;
		int an = -1;
		while(lo <= hi){
            int mid = (lo + hi)/2;
            if(query(mid)>=q[i].k){
                an = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
		}
		ans[q[i].id] = an;
	}
	for(int i = 0; i<Q; i++){
        if(ans[i] == -1)printf("No Distinct Phi Number\n");
		else printf("%lld\n", ans[i]);
	}
}

int main(){
    int test , cs = 1;
    scanf("%d",&test);
    seive();
    while(test--){
        printf("Case %d:\n",cs++);
        solve();
    }
}
//1.2 sec

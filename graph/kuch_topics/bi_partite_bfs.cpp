#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int  mod  = 998244353;

ll power(ll a, ll n){
	ll  res = 1LL;
	while(n){
		if(n%2){
			res = (res*a)%mod;
		}
		n >>= 1;
		a = (a*a)%mod;
	}
	return res;
}

bool bi_partiate(int src, vector<vector<int>>&adj,vector<int>&color){
	int n = adj.size();
	queue<int>q;
	q.push(src);
	color[src] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto child:adj[node]){
			if(color[child]==-1){
				color[child] = !color[node];
				q.push(child);
			}
			else if(color[child]==color[node]){
				return false;
			}
		}
	}
	return true;

}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n,vector<int>());
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll sum = 0;
	vector<int>color(n,-1);
	int ans = 1;
	for(int i=0; i<n; i++){
		if(color[i]==-1){
			sum++;
			ans = ans && bi_partiate(i,adj,color);
		}
	}
	ll one = 0;
	ll zero = 0;
	for(auto &i:color){
		if(i==0){
			zero++;
		}
		if(i==1){
			one++;
		}
	}
	// for(auto &i:color)cout<<i<<" ";
	if(!ans){cout<<0<<endl; return;}


	ll  p1 = power(2,zero)%mod;
	ll  p2 = power(2,one)%mod;

	sum  = (sum*(p1+p2))%mod;

	cout<<sum<<endl;


}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
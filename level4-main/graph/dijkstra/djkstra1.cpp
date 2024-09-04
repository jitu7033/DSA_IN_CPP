#include<bits/stdc++.h>
using namespace std;
#define ll long long

void __djkstra(ll node,vector<vector<pair<ll,ll>>>&adj,vector<ll>&dist){
	dist[node] = 0LL;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	pq.push({0LL,node});
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		ll currDist = temp.first;
		ll currNode = temp.second;
		if(dist[currNode]<currDist)continue;
		for(auto temp:adj[currNode]){
			ll adjNode = temp.first;
			ll adjDist = temp.second;
			if(dist[adjNode]>currDist+adjDist){
				dist[adjNode] = currDist+adjDist;
				pq.push({dist[adjNode],adjNode});
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>>adj(n,vector<pair<ll,ll>>());
	for(int i=0; i<m; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		u--;v--;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	vector<ll>dist(n,1e18);
	__djkstra(0,adj,dist);
	for(auto &i:dist){
		cout<<i<<" ";
	}
}

int main(){
	solve();
}
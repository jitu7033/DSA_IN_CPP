#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int,int>>>&edges, int n){
	const int INF = 1e9;
	vector<int>cost(n,INF);
	vector<int>vis(n,0);
	vector<vector<int>>mst;
	vector<int>parent(n,-1);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	cost[0] = 0;
	parent[0] = 0;
	pq.push({0,0});
	int total_cost = 0;
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		int currDist = temp.first;
		int currNode = temp.second;
		if(vis[currNode])continue;
		vis[currNode] = 1;
		total_cost+=cost[currNode];
		mst.push_back({parent[currNode],currNode,cost[currNode]});
		for(auto temp:edges[currNode]){
			int adjDist = temp.second;
			int adjNode = temp.first;
			if(!vis[adjNode] && cost[adjNode]>adjDist){
				cost[adjNode] = adjDist;
				parent[adjNode] = currNode;
				pq.push({cost[adjNode],adjNode});
			}
		}
	}
	// cout<<total_cost<<endl;
	return total_cost;
	
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
	int totalsum = 0;
	for(int i=0; i<m; i++){
		int u,v,wt;
		
		cin>>u>>v>>wt;
		totalsum+=wt;
		// u--;v--;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	int l,r;
	cin>>l>>r;
	int total_cost = prims(adj,n);
	cout<<totalsum-total_cost<<endl;

}
int main(){
	solve();
}
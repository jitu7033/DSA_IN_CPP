#include<bits/stdc++.h>
using namespace std;
#define ll long long


void dijkstra(int src,vector<vector<pair<int,ll>>>&adj, vector<ll>&dist, vector<int>&parent){
	fill(dist.begin(),dist.end(),1e9);
	int n = dist.size();
	dist[src] = 0;
	set<pair<ll,int>>unvisited;
	for(int i=0; i<n; i++){
		unvisited.insert({dist[i],i});
	}
	while(unvisited.size()>0){
		pair<ll,int>minDist = *unvisited.begin();  // min distance 
		unvisited.erase(minDist); // marking node as visited 
		int minDistNode = minDist.second;
		ll shortestDistToNodes = minDist.first;
		for(pair<int,ll>neighbour:adj[minDistNode]){
			ll oldDIst = dist[neighbour.first];
			ll newDist = shortestDistToNodes+neighbour.second;
			if(newDist<oldDIst){
				unvisited.erase({oldDIst,neighbour.first});
				dist[neighbour.first] = newDist;
				parent[neighbour.first] = minDistNode;
				unvisited.insert({newDist,neighbour.first});
			}
		}
	}
}

vector<int> actualPath(int node, vector<int>parent){
	vector<int>ans;
	while(node!=-1){
		ans.push_back(node);
		node = parent[node];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,ll>>>adj(n,vector<pair<int,ll>>());
	for(int i=0; i<m; i++){
		int u,v,weight;
		cin>>u>>v>>weight;
		u--;v--;
		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});
	}
	vector<ll>dis(n);
	vector<int>parent(n,-1);
	dijkstra(0,adj,dis,parent);
	for(auto x:dis){
		cout<<x<<" ";
	}
	cout<<endl;
	vector<int>actual = actualPath(n-1,parent);
	if(actual.size()==1){cout<<"IMPOSSIBLE"<<endl;return;} // no path found src to destination 
	cout<<actual.size()<<endl;
	for(auto &i:actual){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	solve();
}
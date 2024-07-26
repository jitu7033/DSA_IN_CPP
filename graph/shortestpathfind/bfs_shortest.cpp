#include<bits/stdc++.h>
using namespace std;


// find the shortest path using bfs in undirected graph 
void bfs(int src, vector<vector<int>>&adj){ 
	int n = adj.size();
	vector<int>p(n,-1);
	vector<int>dist(n,0);
	vector<int>vis(n,0);
	queue<int>q;
	dist[src] = 0;
	vis[src] = 1;
	q.push(src);
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		for(auto child:adj[parent]){
			if(!vis[child]){
				dist[child] = dist[parent]+1;
				p[child] = parent+1;
				q.push(child);
				vis[child] = 1;
			}
		}
	}
	for(auto &i:dist){
		cout<<i<<" ";
	}
	cout<<endl;
	for(auto i:p){
		cout<<i<<" ";
	}
}

solve(){
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
	bfs(0,adj);
}

int main(){
	solve();
	return 0;
}
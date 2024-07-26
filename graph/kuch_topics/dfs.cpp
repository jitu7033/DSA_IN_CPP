#include<bits/stdc++.h>
using namespace std;



void dfs(int root,vector<vector<int>>&adj,vector<int>&vis){
	vis[root] = 1;
	cout<<root<<" ";
	for(int child:adj[root]){
		if(!vis[child]){
			dfs(child,adj,vis);
		}
	}
}


void _dfs(int root,vector<vector<int>>&adj, vector<int>&vis){
	vis[root] = 1;

	cout<<root<<" ";
	for(int child:adj[root]){
		if(!vis[child])
			_dfs(child,adj,vis);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	dfs(1,adj,vis);
}
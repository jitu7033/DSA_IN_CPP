#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&path, int dest){
	vis[node] = 1;
	path.push_back(node);
	if(node==dest){
		ans = path;
	}
	for(int child:adj[node]){
		if(!vis[child]){
			dfs(child,adj,vis,path,dest);
		}
	}
	path.pop_back();
}

int main(){
	int n,v;
	cin>>n>>v;
	vector<vector<int>>adj(n+1);
	for(int i=1; i<=v; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>vis(n+1,0);
	vector<int>path;

	dfs(1,adj,vis,path,4);
	for(auto &i:ans){
		cout<<i<<" ";
	}
	cout<<endl;

}
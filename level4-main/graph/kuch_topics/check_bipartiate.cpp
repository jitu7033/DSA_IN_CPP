#include<bits/stdc++.h>
using namespace std;


bool is_bipartiate(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&color){
	vis[node] = 1;
	for(int child:adj[node]){
		if(!vis[child]){
			color[child] = 3-color[node];
			bool result = is_bipartiate(child,adj,vis,color);
			if(!result)return false;
		}
		else{
			if(color[child]==color[node]){
				return false;
			}
		}
	}
	return true;
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
	vector<int>color(n+1,0);
	bool ans = true;
	for(int node = 1; node<=n; node++){
		if(!vis[node]){
			color[node] = 1;
			ans = ans && is_bipartiate(node,adj,vis,color);
		}
	}
	// cout<<(ans ? "is_bipartiate": "no bipartiate")<<endl;
	if(ans){
		for(int i=1; i<color.size(); i++){
			cout<<color[i]<<" ";
		}
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}
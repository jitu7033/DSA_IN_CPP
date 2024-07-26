#include<bits/stdc++.h>
using namespace std;


bool cycle_detection(int node, int parent, vector<vector<int>>&adj,vector<int>&vis){
	vis[node] = 1;

	bool cycle = false;

	for(int child:adj[node]){
		if(!vis[child]){
			cycle = cycle || cycle_detection(child,node,adj,vis);
		}
		else{
			if(child!=parent){
				cycle = true;
			}
		}
	}
	return cycle;
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
	cout<<cycle_detection(1,-1,adj,vis)<<endl;
}
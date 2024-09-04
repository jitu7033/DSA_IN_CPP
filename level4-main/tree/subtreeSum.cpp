#include<bits/stdc++.h>
using namespace std;


int subtreeSums(int node,int parent,vector<vector<int>>&adj,vector<int>&subtree_sum){
	int sum = node;
	for(int neighbour:adj[node]){
		if(neighbour!=parent){
			sum+=subtreeSums(neighbour,node,adj,subtree_sum);
		}
	}
	subtree_sum[node] = sum;
	return sum;
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
	vector<int>subtree_sum(n+1,0);
	subtreeSums(1,-1,adj,subtree_sum);
	for(auto &i:subtree_sum){
		cout<<i<<" ";
	}
}
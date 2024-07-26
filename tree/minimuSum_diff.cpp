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


void mini_sum_diff(int node,int parent,vector<vector<int>>&adj,vector<int>&subtree
,int totalsum,int &min_diff){


	for(int neighbour:adj[node]){
		if(neighbour!=parent){
			mini_sum_diff(neighbour,node,adj,subtree,totalsum,min_diff);
			int curr = abs(totalsum-2*subtree[neighbour]);
			min_diff = min(curr,min_diff);
		}
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
	vector<int>subtree_sum(n+1,0);
	int totalsum = subtreeSums(1,-1,adj,subtree_sum);
	for(auto &i:subtree_sum){
		cout<<i<<" ";
	}
	cout<<endl;
	int min_diff = INT_MAX;
	mini_sum_diff(1,-1,adj,subtree_sum,totalsum,min_diff);
	cout<<min_diff<<endl;
}



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parents, vector<vector<int>>&adj, vector<int>&sz,vector<int>&ans){
	ans[node] = 0;
	sz[node] = 1;

	for(int child:adj[node]){
		if(child!=parents){
			dfs(child,node,adj,sz,ans);
			ans[node] += ans[child]+sz[child];
			sz[node] +=sz[child];
		}
	}
}
void dfs_max(int node, int parent,vector<vector<int>>&adj,vector<int>ans){
	ans[node] = 0;
	for(auto child:adj[node]){
		if(child!=parent){
			dfs_max(child,node,adj,ans);
			ans[node] = max(ans[node],ans[child]+1);
		}
	}
}

void dfs_subtree(int node,int parent,vector<vector<int>>&adj,vector<int>&ans){
	ans[node] = 1;
	for(auto child:adj[node]){
		if(child!=parent){
			dfs_subtree(child,node,adj,ans);
			ans[node] += ans[child];
		}
	}
}

void dfs_gcd(int node,int parent,vector<vector<int>>&adj,vector<int>&ans,vector<int>&a){
	ans[node] = a[node];
	for(auto child:adj[node]){
		if(child!=parent){
			dfs_gcd(child,node,adj,ans,a);
			ans[node] = __gcd(ans[node],ans[child]);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>>adj(n,vector<int>());
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>ans(n);
	vector<int>sz(n);
	dfs_subtree(0,-1,adj,ans);
	for(auto &i:ans){
		cout<<i<<" ";
	}
	cout<<endl;
	for(auto &i:sz){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	solve();
}
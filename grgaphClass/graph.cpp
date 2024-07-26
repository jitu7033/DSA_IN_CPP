#include<bits/stdc++.h>
using namespace std;


void __dfs(int root, vector<vector<int>>&adj,vector<int>&vis){
	vis[root] = 1;
	cout<<root<<" ";
	for(int child:adj[root]){
		if(!vis[child]){
			__dfs(child,adj,vis);
		}
	}
}

void __bfs(vector<vector<int>>&adj, int n){
	queue<int>q;
	vector<int>vis(n,0);
	q.push(0);
	vis[0] = 1;
	while(!q.empty()){
		int temp = q.front();
		cout<<temp<<" ";
		q.pop();
		for(int child:adj[temp]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
			}
		}
	}

}

bool check_cyclic(int root, int parent ,vector<vector<int>>&adj,vector<int>&vis){
	vis[root] = 1;
	bool check = false;
	for(int child:adj[root]){
		if(!vis[child]){
			check = check ||  check_cyclic(child,root,adj,vis);
		}
		else{
			if(child!=parent){
				check = true;
			}
		}
	}
	return check;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n);
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(n,0);
	__dfs(0,adj,vis);
	cout<<endl;
	vis.assign(n,0);
	__bfs(adj,n);
	cout<<endl;
	vis.assign(n,0);
	cout<<check_cyclic(0,-1,adj,vis);
}
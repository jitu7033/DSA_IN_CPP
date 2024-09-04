#include<bits/stdc++.h>
using namespace std;


void bfs(int src,vector<vector<int>>&adj){
	int n = adj.size();
	vector<int>vis(n+1,0);
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	while(!q.empty()){
		int node = q.front();
		cout<<node<<" ";
		q.pop();
		for(int child:adj[node]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
				// cout<<child<<" ";
			}
		}
	}
}

// find the shotest path of sources node to destination node in single sources 
void shortestpath(int src, vector<vector<int>>&adj){
	int n = adj.size();
	vector<int>vis(n+1,0);
	vector<int>dist(n+1,0);
	queue<int>q;
	q.push(src);
	dist[src] = 0;
	vis[src] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child:adj[node]){
			if(!vis[child]){
				q.push(child);
				dist[child] = dist[node]+1;
				vis[child] = 1;
			}
		}
	}
	for(auto i:dist){
		cout<<i<<" ";
	}
	cout<<endl;
}



// if  you have given multisorces then find the shortest path of source node to destination node 


void multisources_shotestpath(vector<int>&src, vector<vector<int>>&adj){
	int n = adj.size()-1; 
	vector<int>dist(n+1,0);
	vector<int>vis(n+1,0);
	queue<int>q;
	for(auto i:src){
		vis[i] = 1;
		dist[i] = 0;
		q.push(i);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child:adj[node]){
			if(!vis[child]){
				q.push(child);
				dist[child] = dist[node]+1;
				vis[child] = 1;
			}
		}
	}
	for(auto &i:dist){
		cout<<i<<" ";
	}
	cout<<endl;
}


// count connectd component in in graph 

void dfs(int src, vector<vector<int>>&adj,vector<int>&vis){

	vis[src] = 1;

	for(int child:adj[src]){
		if(!vis[child])
			dfs(child,adj,vis);
	}
}

void count_component(vector<vector<int>>&adj){
	int n = adj.size()-1;
	int count = 0 ;
	vector<int>vis(n+1,0);
	for(int node=1; node<=n; node++){
		if(!vis[node]){
			dfs(node,adj,vis);
			count++;
		}
	}
	cout<<count<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// for(int i=0; i<adj.size(); i++){
	// 	for(int j=0; j<adj[i].size(); j++){
	// 		cout<<adj[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	bfs(1,adj);
	cout<<endl;
	cout<<"shortest path from src to dest "<<endl;
	shortestpath(1,adj);
	cout<<endl;
	vector<int>src = {1,4};
	multisources_shotestpath(src,adj);
	cout<<endl;
	cout<<"count component"<<endl;
	count_component(adj);
}
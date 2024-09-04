#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&instack){
	vis[node] = 1;
	bool cycle = 0;
	instack[node] = 1;
	for(int child:adj[node]){
		if(!vis[child]){
			cycle = cycle || checkCycle(child,adj,vis,instack);
		}
		else{
			if(instack[child]){
				cycle = true;
			}
		}
	}
	instack[node] = 0;
	return cycle;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(n,vector<int>());
	vector<int>vis(n,0),instack(n);
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].push_back(v);
	}
	bool cycle = 0;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			cycle  = cycle || checkCycle(i,edges,vis,instack);
		}
	}
	cout<<cycle<<endl;
}

int main(){
	solve();
}
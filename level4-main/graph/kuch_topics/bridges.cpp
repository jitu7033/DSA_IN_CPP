#include<bits/stdc++.h>
using namespace std;


void IS_BRIDGE(int v, int to);
vector<vector<int>>adj;
vector<int>vis,tin,low;
int timer;

void dfs(int v, int p = -1){
	vis[v] = 1;
	tin[v] = low[v] = timer++;
	bool parent_skipped = false;
	for(int to : adj[v]){
		if(to == p && !parent_skipped){
			parent_skipped = true;
			continue;
		}
		if(vis[to]){
			low[v] = min(low[v], tin[to]);
		}
		else{
			dfs(to,v);
			low[v] = min(low[v],low[to]);
			if(low[to] > low[v]){
				IS_BRIDGE(v,to);
			}
		}
	}
}

void IS_BRIDGE(int u,int v){
	cout<<u<<" "<<v<<" "<<"bridge found between u to v"<<endl;
}

void solve(){
	int n,m;
	cin>>n>>m;
	adj.resize(n);
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	timer = 0;
	vis.assign(n,0);
	tin.assign(n,-1);
	low.assign(n,-1);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
}

int main(){

}
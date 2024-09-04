#include<bits/stdc++.h>
using namespace std;

void topological__dfs(int node,vector<vector<int>>&edges,vector<int>&vis,vector<int>&ts){
	vis[node] = 1;
	for(int child:edges[node]){
		if(!vis[child]){
			topological__dfs(child,edges,vis,ts);
		}
	}
	ts.push_back(node);
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(n,vector<int>());
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		// u--;v--;
		edges[u].push_back(v);
	}
	vector<int>ans;
	vector<int>vis(n,0);
	for(int i=0; i<n; i++){
		if(!vis[i]){
			topological__dfs(i,edges,vis,ans);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto &i:ans){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	solve();
}
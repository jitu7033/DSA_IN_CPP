#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll>bellmomd_ford(int src,int n,vector<vector<int>>&edges,vector<int>&parent){
	ll INF = 1e9;
	vector<ll>dist(n,INF);
	dist[src] = 0;
	for(int i=0;i<n; i++){
		int x = -1;
		for(auto child:edges){
			int u = child[0],v = child[1],wt = child[2];
			// cout<<u<<" "<<v<<" "<<wt<<endl;
			if(dist[u]!=INF && dist[v]>dist[u]+wt){
				dist[v] = dist[u]+wt;
				parent[v] = u;
				x = 1;
			}
		}
		if(i==n-1 && x!=-1){
			return {-1};
		}
	}
	return dist;
}

// find the path from to from 
vector<ll>path(int src, int dest,vector<int>&parent){
	vector<ll>ans;
	while(dest!=-1){
		ans.push_back(dest);
		dest = parent[dest];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(m,vector<int>(3));
	for(int i=0; i<m; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[i] = {u,v,wt};
	}
	vector<int>parent(n,-1);
	vector<ll>ans = bellmomd_ford(0,n,adj,parent);
	for(auto &i:ans){
		cout<<i<<" ";
	}
	cout<<endl;
	vector<ll>actual_path = path(0,1,parent);
	for(auto &i:actual_path){
		cout<<i<<" ";
	}
}

int main(){
	solve();
}
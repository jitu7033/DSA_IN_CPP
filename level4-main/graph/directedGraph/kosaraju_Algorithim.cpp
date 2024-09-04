#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n,vector<int>());
	vector<int>vis(n,0);
	vector<vector<int>>radj(n,vector<int>());
	vector<int>ord;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	function<void(int)>dfs = [&](int node){ // using dfs store the element int toplogical sorting
		vis[node] = 1;
		for(auto &v:adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
		ord.push_back(node);
	};
	for(int i=0; i<n; i++){  // pass the node of dfs to store the topological sorting 
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(ord.begin(),ord.end());
	vis.assign(n,0);// reassign the vis vector in not visited

	int col = 0; 

	function<void(int)>kosaraju_dfs = [&](int node){
		vis[node] = col;
		for(auto &child:radj[node]){
			if(!vis[child]){
				kosaraju_dfs(child);
			}
		}
	};
	int x,y;
	x = ord[0]+1;
	for(auto &i:ord){
		if(!vis[i]){
			col++;
			if(col>=2){
				y = (i+1);
			}
			kosaraju_dfs(i);
		}
	}
	// for(auto &i:vis){
	// 	cout<<i<<" ";
	// }
	// cout<<endl;
	if(col>1){
		cout<<"NO"<<endl;
		cout<<y<<" "<<x<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
}
int main(){
	solve();
}
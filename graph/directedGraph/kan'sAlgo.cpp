#include<bits/stdc++.h>
using namespace std;

// this algo is using for find the topological sorted 

vector<int>__kans(vector<vector<int>>&edges){
	int n = edges.size();
	vector<int>indegree(n);
	for(int i=0; i<n; i++){
		for(auto it:edges[i]){
			indegree[it]++;
		}
	}
	queue<int>q;
	for(int i=0; i<n; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<int>result;

	while(!q.empty()){
		int top = q.front();
		q.pop();
		result.push_back(top);
		for(auto adj:edges[top]){
			indegree[adj]--;
			if(indegree[adj]==0){
				q.push(adj);
			}
		}
	}
	for(auto &i:result){
		cout<<i<<" ";
	}
	cout<<endl;
	return result;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(n,vector<int>());
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].push_back(v);
	}
	vector<int>ts = __kans(edges);


}

int main(){
	solve();
}	
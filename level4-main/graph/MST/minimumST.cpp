#include<bits/stdc++.h>
using namespace std;

struct DSU{
	int n;
	vector<int>leader,sizes;

	DSU(int _n){
		n = _n+1;
		leader.resize(n);
		sizes.resize(n);
		for(int i=0; i<n; i++){
			leader[i] = {i};
			sizes[i] = 1;
		}
	}
	int find(int node){
		if(leader[node]==node)return node;
		return  find(leader[node]);
	}
	void join(int x, int y){
		int a = find(x);
		int b = find(y);

		if(a==b){
			return;
		}
		if(sizes[a]==sizes[b]){
			sizes[a]++;
		}
		if(sizes[a]>sizes[b]){
			leader[b] = a;
		}
		else{
			leader[a] = b;
		}
	}
};
// time O(nlog(m)+O(n)+O(m));

vector<vector<int>>kruskal(vector<vector<int>>&edges, int n){
	sort(edges.begin(),edges.end());
	DSU dsu(n);
	vector<vector<int>>mst;
	for(auto edge:edges){
		int u = edge[0],v = edge[1],wt = edge[2];
		if(dsu.find(u)!=dsu.find(v)){
			dsu.join(u,v);
			mst.push_back(edge);
		}
	}
	return mst;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(m,vector<int>(3));
	for(int i=0; i<m; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges[i] = {u,v,wt};
	}
	vector<vector<int>>ans = kruskal(edges,n);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	solve();
}
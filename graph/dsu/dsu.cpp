#include<bits/stdc++.h>
using namespace std;

void connect(int x, int y, vector<int>&leader,vector<int>&size, vector<vector<int>>&comp){
	int leader_x = leader[x];
	int leader_y = leader[y];
	if(leader_x==leader_y) return;
	if(size[leader_x]>size[leader_y])swap(leader_x,leader_y);
	for(int node:comp[leader_x]){
		comp[leader_y].push_back(node);
		size[leader_y]++;
		leader[node] = leader_y;
	}
}
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int>leader(n,0);
	vector<int>size(n);
	vector<vector<int>>comp(n);
	for(int i=0; i<n; i++){
		leader[i] = i;
		size[i] = 1;
		comp[i] = {i};
	}
	for(int i=0; i<q; i++){
		string s;
		int u,v;
		cin>>s>>u>>v;
		u--;v--;
		if(s=="union")connect(u,v,leader,size,comp);
		else{
			if(leader[u]==leader[v]){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}	
	// for( auto i:leader){
	// 	cout<<i<<" ";
	// }
}

int main(){
	solve();
}
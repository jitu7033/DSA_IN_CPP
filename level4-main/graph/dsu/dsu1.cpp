#include<bits/stdc++.h>
using namespace std;

struct Dsu{
	int n;
	vector<int>sizes,leader;
	Dsu(int _n){
		n = _n;
		leader.resize(n+1);
		sizes.resize(n+1);
		for(int i=0; i<=n; i++){
			sizes[i] = 1;
			leader[i] = i;
		}
	}
	int getLeader(int node){
		if(node==leader[node])return node;
		return leader[node] = getLeader(leader[node]);
	}
	void connect(int x,int y){
		int leader_x = getLeader(x);
		int leader_y = getLeader(y);
		if(leader_x==leader_y)return;
		if(sizes[leader_x]<sizes[leader_y]){
			swap(leader_x,leader_y);
			swap(x,y);
		}
		leader[leader_y] = leader_x;
		sizes[leader_x]+=sizes[leader_y];
	}
};
void solve(){
	int n,q;
	cin>>n>>q;
	Dsu dsu(n);
	for(int i=0; i<q; i++){
		string s;
		int u,v;
		cin>>s>>u>>v;
		if(s=="union"){
			dsu.connect(u,v);
		}
		else{
			int x= dsu.getLeader(u);
			int y = dsu.getLeader(v);
			if(x==y)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}

}
int main(){
	solve();
}
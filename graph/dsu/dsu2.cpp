#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
	int n;
	vector<int>rank,exp,leader;

	UnionFind(int _n){
		n = _n;
		rank.resize(n);
		exp.resize(n);
		leader.resize(n);
		for(int i=0; i<n; i++){
			exp[i] = 0;
			rank[i] = 1;
			leader[i] = i;
		}
	}

	int getLeader(int node){
		return leader[node]==node ? node:getLeader(leader[node]);
	}

	int getExp(int node){
		int ans = 0;
		while(leader[node]!=node){
			ans+=exp[node];
			node = leader[node];
		}
		ans+=exp[node];
		return ans;
	}

	void merge(int x,int y){
		int a = getLeader(x);
		int b = getLeader(y);
		if(a==b)return;

		if(rank[a]==rank[b]){
			rank[a]++;
		}
		if(rank[a]>rank[b]){
			leader[b] = a;
			exp[b]-=exp[a];
		}
		else{
			leader[a] = b;
			exp[a]-=exp[b];
		}
	}

};

void solve(){
	int n,m;
	cin>>n>>m;
	UnionFind dsu(n);
	for(int i=0; i<m; i++){
		string s;int u,v;
		cin>>s;
		if(s[0]=='a'){
			cin>>u>>v;
			u--;
			int temp = dsu.getLeader(dsu.leader[u]);
			dsu.exp[temp]+=v;
		}
		if(s[0]=='j'){
			cin>>u>>v;
			u--;
			v--;
			dsu.merge(u,v);
		}
		if(s[0]=='g'){
			cin>>u;
			u--;
			cout<<dsu.getExp(u)<<endl;
		}
	}
}

int main(){
	solve();
}
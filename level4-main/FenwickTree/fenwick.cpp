#include<bits/stdc++.h>
using namespace std;

struct fenwick{
	vector<int>bit;
	int n;
	fenwick(int a_len, vector<int>&a){
		n = a_len;
		bit = a;
	}
	int query(int id){
		int ans = 0;
		while(id >= 0){
			ans += bit[id];
			id -= (id & -id);
		}
		return ans;
	}
	void update_query(int id, int val){
		while(id <= n){
			bit[id] +=  val;
			id += (id & -id);
		}
	}
};

void solve(){
	int n;
	cin>>n;
	vector<int>bit(n+1);
	for(int i = 1; i <= n; i++){
		cin>>bit[i];
	}
	fenwick fen = fenwick(n,bit);

	cout<<fen.query(3);
}
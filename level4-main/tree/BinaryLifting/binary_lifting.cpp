#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define INF 1e5
#define maxLogn = 32

vector<vector<int>>table;

void populated_parent(int curr,int imidiateParent,vector<vector<int>>&adj){
	table[curr][0] = imidiateParent;
	for(auto &child: adj[curr]){
		if(child != imidiateParent){
			populated_parent(child,curr,adj);
		}
	}
}
void build_binary_table(int n){
	for(int j = 1; j < maxLogn; j++){
		for(int i = 0; i < n; i++){
			int intermidiateParent = table[i][j-1];
			if(intermidiateParent != -1){
				table[i][j] = table[intermidiateParent][j-1];
			}
		}
	}
}

int kth_parent(int x, int k){
	for(int i = 0; i < maxLogn; i++){
		if(k & (1 << i)){
			x = table[x][i];
		}
	}
	return x;
}


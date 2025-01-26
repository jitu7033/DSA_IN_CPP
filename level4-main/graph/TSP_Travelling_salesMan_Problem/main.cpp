#include<bits/stdc++.h>
using namespace std;

vector<int>ans1;
vector<vector<int>>final;

int totCost(int mask, int curr, int n,vector<vector<int>>&matrix,
	vector<vector<int>>&memo,vector<vector<int>>&parent){
	// if all citites are visited return the return to cost the starting to starting city 
	if(mask == (1<<n) - 1){
		final.push_back(ans1);
		return matrix[curr][0];
	}
	if(memo[curr][mask] != -1){
		return memo[curr][mask];
	}
	
	int ans = INT_MAX;

	// try visiting every city that has not been visited yet

	for(int i = 0; i < n; i++){
		if((mask & (1 << i)) == 0){
			int cost = min(ans,matrix[curr][i] + 
				totCost((mask | (1 << i)),i,n,matrix,memo,parent));

			if(cost < ans){
				ans = cost;
				parent[curr][mask] = i;
			}
		}
	}
	return memo[curr][mask] = ans;
}


int tsp(vector<vector<int>>&matrix,vector<vector<int>>&parent){
	int n = matrix.size();
	vector<vector<int>>memo(n,vector<int>(1<<n,-1));

	return totCost(1,0,n,matrix,memo,parent);

}

signed main(){
	int n,m;
	cin>>n;
	vector<vector<int>>matrix(n,vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>matrix[i][j];
		}
	}
	vector<vector<int>>parent(n,vector<int>(1<<n,-1));
	cout<<tsp(matrix,parent)<<endl;
	vector<int>path;
	int mask = 1;
	int curr = 0;
	path.push_back(0);
	while(parent[curr][mask] != -1){
		curr = parent[curr][mask];
		mask |= (1 << curr);
		path.push_back(curr);
	}
	// path.push_back(0);
	for(auto &x: path){
		cout<<x<<" ";
	}
}
#include<bits/stdc++.h>

void solve(){
	int n,m,weight;
	std::cin>>n>>m;
	std::vector<int>v(n);
	std::vector<int>val(n);
	for(auto &i:v){
		std::cin>>i;
	}
	for(auto &i:val){
		std::cin>>i;
	}
	std::vector<std::vector<int>>dp(n+1,std::vector<int>(m+1,0));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(v[i-1]>j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = std::max(val[i-1]+dp[i-1][j-v[i-1]],dp[i-1][j]);
				// dp[i][j] = val[i-1]+dp[i-1][j-val[i-1]];
			}
		}

	}
	std::cout<<dp[n][m]<<std::endl;
}

void zero_and_ones(){
	int n,m,length;
	std::cin>>length>>n>>m;
	std::vector<std::pair<int,int>>pi;
	for(int i = 0; i<length; i++){
		int a,b;
		std::cin>>a>>b;
		pi.push_back(std::make_pair(a,b));
	}
	for(auto &i:pi){
		std::cout<<i.first<<" "<<i.second<<std::endl;
	}
	int dp[length+1][n+1][m+1];
	for(int i = 0; i<length+1; i++){
		for(int j = 0; j<n+1; j++){
			for(int k = 0; k<m+1; k++){
				dp[i][j][k] = 0;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=length; i++){
		for(int j = 0; j<=n; j++){
			for(int k = 0; k<=m; k++){
				if(pi[i-1].first<=j && pi[i-1].second<=k){
					dp[i][j][k] = std::max(1+dp[i-1][j-pi[i-1].first][k-pi[i-1].second],dp[i-1][j][k]);
				}
				else{
					dp[i][j][k] = std::max(dp[i][j][k],dp[i-1][j][k]);
				}
				ans = std::max(ans, dp[i][j][k]);
			}
		}
	}
	std::cout<<ans;
}
int main(){
	zero_and_ones();
}
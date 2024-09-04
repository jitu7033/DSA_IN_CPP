#include<bits/stdc++.h>
#define int long long


const int  N = 5005;
int dp[N][N];int sum[N][N];

void fibonacci(){
	int n;
	std::cin>>n;
	// 0 1 1 2 3 5 8

	std::vector<int>dp(n);
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	std::cout<<dp[n-1]<<std::endl;

}

// given 2D grid n*m find minimum sum path go to the top to the buttom 00 to n-1,m-1

void minimum_sum_path(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<int>>grid(n,
		std::vector<int>(m));
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			std::cin>>grid[i][j];
		}
	}

	// using dp solve this problem 
	 // transition 
	// dp[i][j] = dp[i][j]+min(dp[i][j+1],dp[i+1][j]);
	std::vector<std::vector<int>>dp(n+1,std::vector<int>(m+1));

	dp[0][0] = grid[0][0];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(i==0 && j==0){
				dp[i][j] = grid[i][j];
			}
			else if(i==0){
				dp[i][j] = grid[i][j]+dp[i][j-1];
			}
			else if(j==0){
				dp[i][j] = grid[i][j]+dp[i-1][j];
			}
			else dp[i][j] = grid[i][j]+std::min(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			std::cout<<dp[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<dp[n-1][m-1]<<std::endl;
}
// house rubber problem 
//Q.) given an array of both positive and negative integer pick a subsequenc of element from it such that no two adjacent element are picked and sum of picked element is maximized

// the state is the problem is 
// dp[i][0] = maximum sum in (0 to i) if we dont pickup ith eleement 
// dp[i][1] = maximum sum in (0 to i) if we pickedup ith element 

// transition of the problem is 
// dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
// dp[i][1] = arr[i]+dp[i-1][0];

// final answer is 
// max(dp[n-1][0],dp[n-1][1]);


// another state and transation 
// state -> dp[i] = max sum in(0, n-1) not carrying we picked up ith element or not 

// transition -:
	// dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
	// final answer is dp[n-1];


void problem2(){
	int n;
	std::cin>>n;
	std::vector<int>v(n);
	for(auto &i:v){
		std::cin>>i;
	}
	std::vector<std::vector<int>>dp(n,std::vector<int>(2,0));
	dp[0][0] = 0;
	dp[0][1] = v[0];

	for(int i = 1; i<n; i++){
		dp[i][0] = std::max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = v[i]+dp[i-1][0];
	}
	std::cout<<std::max(dp[n-1][0],dp[n-1][1])<<std::endl;
}

void problem3(){
	int n;std::cin>>n;
	std::vector<int>v(n);
	for(auto &i:v){
		std::cin>>i;
	}
	std::vector<int>dp(n);
	dp[0] = std::max(0ll,v[0]);
	for(int i = 1; i<n; i++){
		dp[i] = std::max(v[i]+dp[i-1],dp[i-1]);
	}
	std::cout<<dp[n-1]<<std::endl;
}

int removal_game_recursive(int i,int j,std::vector<int>&arr){
	if(i==j){
		return arr[i];
	}
	if(dp[i][j]!=1e15){
		return dp[i][j];
	}

	return dp[i][j] = std::max(arr[i]+sum[i+1][j]-removal_game_recursive(i+1,j,arr),
						arr[j]+sum[i][j-1]-removal_game_recursive(i,j-1,arr));

	
}

void removal_game(){
	int n;
	std::cin>>n;
	std::vector<int>v(n);
	for(auto &i:v){
		std::cin>>i;
	}
	// state 
	// dp[i][j] = max score that current player can get when array from i to j is remaining

	// transation 
	// dp[i][j] = max(a[i]+sum[i-1][j]-dp[i-1][j],a[j]+sum[i][j+1]-dp[i][j-1];


	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<n; j++){
	// 		dp[i][j] = 1e15;
	// 	}
	// }

	for(int i = 0; i < n; i ++){
		int curr = 0; 
		for(int j = i; j < n; j++){
			curr += v[j];
			sum[i][j] = curr;
		}
	}

	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<n; j++){
			if(i>j)continue;
			if(i==j)dp[i][j] = v[i];
			else dp[i][j] = std::max(v[i]+sum[i+1][j]-dp[i+1][j],
				                     v[j]+sum[i][j-1]-dp[i][j-1]);
		}
	}

	std::cout<<dp[0][n-1]<<std::endl;
	
}

// rectangle cutting cses proble

void rectangle_cutting(){
	// state 
	// dp[n][m] = min cut of require to convert the rectangle in to the square

	// transition 
	// dp[i][j] = min(dp[k][m]+dp[n-k][m]); horizontal cut for 1 to n-1
	// dp[n][x] = min(dp[n][x]+dp[n][m-x]); verticall cut 

	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<int>>dp(n+1,std::vector<int>(m+1));
	for(int  i = 0; i<=n; i++){
		for(int j = 0; j<=m; j++){
			if(i==j){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = 1e9;
				for(int k = 1; k<i; k++){
					dp[i][j] = std::min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
				for(int k = 1; k<j; k++){
					dp[i][j] = std::min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}

			}

		}
	}
	std::cout<<dp[n][m]<<std::endl;
}

signed main(){
	// rectangle_cutting();
	minimum_sum_path();
}
#include<bits/stdc++.h>
using namespace std;


bool is_safe(vector<vector<char>>&board,int row, int col){
	int n = board.size();
	int m = board[0].size();

	// check same row 
	for(int j=0; j<m; j++){
		if(board[row][j]=='Q')return false;
	}
	// check same column 
	for(int i=0; i<n; i++){
		if(board[i][col]=='Q')return false;
	}
	// down right
	int i = row;
	int j = col;
	while(i<n && j<m){
		if(board[i][j]=='Q')return false;
		i++;
		j++;
	}
	// down and left 
	i = row;
	j = col;
	while(i<n && j>=0){
		if(board[i][j]=='Q')return false;
		i++;
		j--;
	}
	// up left
	i = row;
	j = col;
	while(i>=0 && j>=0){
		if(board[i][j]=='Q')return false;
		i--;
		j--;
	}
	// up right
	i = row;
	j = col;
	while(i>=0 && j<m){
		if(board[i][j]=='Q')return false;
		i--;
		j++;
	}
	return true;
}
void solve(vector<vector<char>>&board,int row,vector<vector<string>>&ans){
	int n = board.size();
	if(row==n){
		vector<string>l;
		for(int i=0; i<n; i++){
			string s = "";
			for(int j = 0; j<n; j++){
				s+=board[i][j];
			}
			l.push_back(s);
		}
		ans.push_back(l);
		return;
	}

	// traverse all the col 
	for(int j=0; j<n; j++){
		if(is_safe(board,row,j)){
			board[row][j] = 'Q';
			solve(board,row+1,ans);
			board[row][j] = '.';
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<char>>v(n,vector<char>(n,'.'));
	vector<vector<string>>ans;
	solve(v,0,ans);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

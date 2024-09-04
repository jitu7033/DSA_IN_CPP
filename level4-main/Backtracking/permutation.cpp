#include<bits/stdc++.h>


void solve(std::string &s, int l, int r){
	if(l == r){
		std::cout<<s<<std::endl;
		return ;
	}
	for(int i = l; i <=r; i++){
		// swap
		std::swap(s[l],s[r]);

		// function call
		solve(s,l+1,r);
		// backtrack
		std::swap(s[l],s[i]);
	}
}

int main(){
	std::string s = "112";
	solve(s,0,s.length()-1);
}
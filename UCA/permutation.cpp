#include<bits/stdc++.h>
using namespace std;


void solve(string s, string t){
	if(s==""){
		cout<<t<<endl;
		return;
	}
	for(int i=0; i<s.length(); i++){
		char ch = s[i];
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		string rem = left+right;
		solve(rem,t+ch);
	}
}

int main(){
	string s;cin>>s;
	solve(s,"");
}
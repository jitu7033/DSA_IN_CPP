#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(auto &i:v){
		cin>>i;
	}
	map<int,int>mp;
	
	// 1 1 1 2 2 3 4 5 

	for(int i=0; i<n; i++){
		if(mp.find(v[i])!=mp.end()){
			int key = v[i];
			int val = mp[key];
			mp[key] = val+1;
		}
		else{
			int key = v[i];
			mp[key] = 1;
		}
	}
	for(auto &x:mp){
		cout<<x.first<<" "<<x.second<<endl;
	}
}
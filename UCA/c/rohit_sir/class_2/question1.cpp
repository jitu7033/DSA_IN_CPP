#include<bits/stdc++.h>
using namespace std;



void combinatio_sum(vector<int>&v, int index, int target,vector<int>ans,vector<vector<int>>&sol)
{
	if(target==0){
		sol.push_back(ans);
		return;
	}
	for(int i=index; i<v.size(); i++){
		if(i>index && v[i]==v[i-1])continue;
		if(v[i]>target)break;
		ans.push_back(v[i]);
		combinatio_sum(v,i+1,(target-v[i]),ans,sol);
		ans.pop_back();
	}
}
// multiply two string leetcode 43 

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k = 2;
	map<char,int>mp;
	int ptr1 = 0;
	int maxi = 0;
	for(int ptr2 = 0; ptr2 < n; ptr2++)
	{	
		while(mp.size()>k && ptr1<n){
			mp[s[ptr1]]--;
			ptr1++;
			if(mp[ptr1]==0){
				mp.erase(s[ptr1]);
			}
		}
		mp[s[ptr2]]++;
		maxi = max(maxi,(ptr2-ptr1)+1);
	}
	cout<<maxi<<endl;
}
		
int main(){
	int t;
	cin>>t;
	while(t--){

	}
}
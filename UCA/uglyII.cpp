#include<bits/stdc++.h>
using namespace std;
#define ll int

int n = 10000;
vector<int>is_prime(n+1,1);
vector<int>primes;
void prime(){
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(int i=2; i*i<=n; i++){
		if(is_prime[i]){
			for(int j=i*i; j<=n; j+=i){
				is_prime[j] = 0;
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
}

void solve(){
	string s,t;
	cin>>s>>t;
	int n = s.length();
	int size =  t.size();
	map<char,int>mp;
	int count = t.length();
	int i = 0;
	int j = 0;
	int ist = 0;
	for(auto &i:t){
		mp[i]++;
	}
	int mini = INT_MAX;

	while(j<n){
		if(mp[s[j]] > 0){
			mp[s[j]]--;
			count--;
		}
		while(count==0){
			if((j-i)<mini){
				mini = (j-i);
				ist = i;
			}
			if(mp[s[i]]==0){
				mp[s[i]]++;
			}
			i++;
		}
		j++;
		cout<<"jkdshf";
	}
	cout<<ist<<endl;
}
int main(){
	solve();
	
}
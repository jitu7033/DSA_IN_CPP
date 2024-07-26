
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef vector<long long>vl;
#define fl(i,a,b) for(int i=a; i<b; i++)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~seive~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
vector<int>seive(){
	vector<int>primes(1e6+1,1);
	primes[0] = 0;
	primes[1] = 0;
	cout<<primes.size()<<endl;
	for(int i=2; i*i<=1e6; i++){
		if(primes[i]==1){
			for(int j=i*i; j<=1e6; j+=i){
				primes[j] = 0;
			}
		}
	}
	return primes;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int left(int index){
	return 2*index;
}
int right(int index){
	return 2*index+1;
}

int  merge(int left, int right){
	return left+right;
}

int default_val(){
	return 0;
}
 
void build(int start, int end, int index, vector<int> &SGT, vl &arr){
	if(start==end){
		SGT[index] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	 build(start,mid,left(index),SGT,arr);
	 build(mid+1,end,right(index),SGT,arr);

	 SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}
void update(int start, int end, int index, vector<int> &SGT, int pos, int val){
	if(start==end){
		SGT[index] = val;
		return;
	}
	int mid = (start+end)/2;
	if(pos<=mid){
		update(start,mid,left(index),SGT,pos,val);
	}
	else{
		update(mid+1,end,right(index),SGT,pos,val);
	}
	SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}
int query(int start,int end, int index, vector<int>&SGT,int l, int r){
	// if complete 
	// [l.....start....end....r...];
	if(l<=start && r>=end){
		return SGT[index];
	}
	// disjoint 
	// [start.....end...l...r] or [l......r....start....end..]
	else if(end<l || r<start){
		return default_val();
	}
	int mid = (start+end)/2;
	int leftAns = query(start,mid,left(index),SGT,l,r);
	int rightAns = query(mid+1,end,right(index),SGT,l,r);

	return merge(leftAns,rightAns);
}

void solve(){
	int n;
	cin>>n;
	cout<<"chal rha HAi"<<endl;
	vector<int>ans = seive();
	vl arr(n);
	fl(i,0,n)
	{
		int x;
		cin>>x;
		if(ans[x]==1){
			arr[i] = 1;
		}
		else{
			arr[i] = 0;
		}
	}
	for(auto &i:arr){
		cout<<i<<' ';
	}
	cout<<endl;
	vector<int>SGT(4*n+1);

	build(0,n-1,1,SGT,arr);
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,0,1)<<endl;;
	// update(0,n-1,1,SGT,1,10);
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,3,5)<<endl;;
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,2,6)<<endl;;
}
int main(){
	solve();

	
}


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef vector<long long>vl;
#define fl(i,a,b) for(int i=a; i<b; i++)


int left(int index){
	return 2*index;
}
int right(int index){
	return 2*index+1;
}

pair<int,int> merge(pair<int,int>left, pair<int,int>right){
	int first_min = min(left.first,right.first);
	int second_min = 1e9;
	if(first_min==left.first){
		second_min = min(left.second,right.first);
	}
	else{
		second_min = min(right.second,left.first);
	}
	return make_pair(first_min,second_min);
}

int default_val(){
	return 0;
}
 
void build(int start, int end, int index, vector<pair<int, int>> &SGT, vl &arr){
	if(start==end){
		SGT[index] = {arr[start],1e9};
		return;
	}
	int mid = (start+end)/2;
	 build(start,mid,left(index),SGT,arr);
	 build(mid+1,end,right(index),SGT,arr);

	 SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}

void update(int start, int end, int index, vector<pair<int, int>> &SGT, int pos, int val){
	if(start==end){
		SGT[index] = {val,1e9};
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

pair<int ,int>query(int start,int end, int index, vector<pair<int,int>>&SGT,int l, int r){
	// if complete 
	// [l.....start....end....r...];
	if(l<=start && r>=end){
		return SGT[index];
	}
	// disjoint 
	// [start.....end...l...r] or [l......r....start....end..]
	else if(end<l || r<start){
		return {1e9,1e9};
	}
	int mid = (start+end)/2;
	pair<int,int>leftAns = query(start,mid,left(index),SGT,l,r);
	pair<int,int>rightAns = query(mid+1,end,right(index),SGT,l,r);

	return merge(leftAns,rightAns);
}

void solve(){
	int n = 5;
	cin>>n;
	cout<<"chal rha HAi"<<endl;
	vl arr(n,0);
	fl(i,0,n)cin>>arr[i];
	vector<pair<int, int>>SGT(4*n+1);
	build(0,n-1,1,SGT,arr);
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,1,3).second<<endl;;
	update(0,n-1,1,SGT,1,10);
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,1,2).second<<endl;;

}
int main(){
	solve();
}
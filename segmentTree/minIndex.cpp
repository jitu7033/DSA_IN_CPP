
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
	int minIndex = 0;
	int minEle = 0;
	if(left.first==right.first){
		int mine = min(left.second,right.second);
		return make_pair(left.first,mine);
	}
	else if(left.first<right.first){
		minEle = left.first;
		minIndex = left.second;
	}
	else{
		minEle = right.first;
		minIndex = right.second;
	}
	return make_pair(minEle,minIndex);
}

int default_val(){
	return 0;
}
 
void build(int start, int end, int index, vector<pair<int, int>> &SGT, vl &arr){
	if(start==end){
		SGT[index] = {arr[start],start};
		return;
	}
	int mid = (start+end)/2;
	 build(start,mid,left(index),SGT,arr);
	 build(mid+1,end,right(index),SGT,arr);

	 SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}

void update(int start, int end, int index, vector<pair<int, int>> &SGT, int pos, int val){
	if(start==end){
		SGT[index] = {val,start};
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
		return {1e9,-1};
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
	cout<<query(0,n-1,1,SGT,0,1).second<<endl;;
	// update(0,n-1,1,SGT,1,10);
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,3,5).second<<endl;;
	cout<<"ans :"<<"  ";
	cout<<query(0,n-1,1,SGT,2,6).second<<endl;;

}
int main(){
	solve();
}

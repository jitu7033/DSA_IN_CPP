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

int merge(int left, int right){
	return max(left,right);
}

int default_val(){
	return -1e9;
}
 
void build(int start, int end, int index, vl &SGT, vl &arr){
	if(start==end){
		SGT[index] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	 build(start,mid,left(index),SGT,arr);
	 build(mid+1,end,right(index),SGT,arr);

	 SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}

void update(int start, int end, int index, vl &SGT, int pos, int val){
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
int query(int start,int end, int index, vl&SGT,int l, int r){
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
	int n,m;
	cin>>n>>m;
	vl arr(n);
	vl group(m);
	vl SGT(4*n+1);
	fl(i,0,n)cin>>arr[i];
	fl(i,0,m)cin>>group[i];
	build(0,n-1,1,SGT,arr);
	vl result;

	for(auto &i:group){
		int ans = 1e9;
		int l = 0;
		int r  =n-1;
		while(l<=r){
			int mid = (l+r)/2;
			ll maxRange = query(0,n-1,1,SGT,l,mid);
			// cout<<maxRange<<" max form l to mid "<<" mid is equal to "<<mid<<endl;

			if(maxRange>=i){
				ans = min(mid,ans);
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		// cout<<"updated result"<<ans<<endl;
		// cout<<"what is query: "<<i<<endl;
		if(ans<n){
			// cout<<ans<<" ans"<<endl;
			result.push_back(ans+1);
			// cout<<arr[ans]<<" val"<<endl;
			int val = query(0,n-1,1,SGT,ans,ans);
			val-=i;
			// cout<<val<<endl;
			update(0,n-1,1,SGT,ans,val);
			// cout<<query(0,n-1,1,SGT,ans,ans)<<" query"<<endl;
		}
		else{
			result.push_back(0);
		}
	}
	for(auto &i:result){
		cout<<i<<" ";
	}
	cout<<'\n';
}
int main(){
	solve();
}
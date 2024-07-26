#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long>vl;
typedef vector<int>vi;

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
	return INT_MIN;
}


void build(int start, int end, int index, vi &SGT, vi &arr){
	if(start==end){
		SGT[index] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	build(start,mid, left(index),SGT,arr);
	build(mid+1,end,right(index),SGT,arr);

	SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}
void apply(int start, int end, int index, vi &SGT,vi &lazy, int x){
	SGT[index] += x*(end-start+1); // apply the part of the segement tree of the node
	lazy[index] += x; // combination of the 2 update 
}
void pushdown(int start, int end, int  index,vi &SGT, vi &lazy){
	if(start!=end){
		int mid = (start+end)/2;
		apply(start,mid,left(index),SGT,lazy,lazy[index]);
		apply(mid+1,end,right(index),SGT,lazy,lazy[index]);
	}
	lazy[index] = 0;   // change to default value;
}

void update(int start, int end, int index, vi &SGT,vi &lazy, int l, int r, int x){
	if(lazy[index]!=0){  // if any changing panding then push them down 
		pushdown(start,end,index,SGT,lazy);
		return;
	}
	if(start>r || end<l){
		return;
	}
	// complete ovwerlap 
	if(l<=start && r>=end){
		apply(start,end,index, SGT,lazy,x);
		return;
	}

	int mid = (start+end)/2;
	update(start,mid,left(index),SGT,lazy,l,r,x);
	update(mid+1,end,right(index),SGT,lazy,l,r,x);

	SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
}

int  query(int start, int end, int index, vi &SGT,vi &lazy, int l, int r){
	if(lazy[index]!=0){
		pushdown(start,end,index,SGT,lazy);
	}
	if(start>r || end<l){
		return default_val();
	}
	// complete ovwerlap 
	if(l<=start && r>=end){
		return SGT[index];
	}
	int mid = (start+end)/2;
	int leftAns = query(start,mid,left(index),SGT,lazy,l,r);
	int rightAns = query(mid+1,end,right(index),SGT,lazy,l,r);
	return merge(leftAns,rightAns);
}

// void solve(){
// 	int n;
// 	cin>>n;
// 	vi arr(n);
// 	for(int &i: arr){
// 		cin>>i;
// 	}
// 	vi SGT(4*n);
// 	vi lazy(4*n,0);
// 	build(0,n-1,1,SGT,arr);

// 	cout<<" code is run "<<endl;

// 	update(0,n-1,1,SGT,lazy,3,4,9);

// 	cout<<"check this code is runnIn"<<endl;
// 	cout<<query(0,n-1,1,SGT,lazy,4,5)<<endl;
// }


solve(){
	ll n,m;
    cin>>n>>m;
    vector<int>arr(n,0);
    vi SGT(4*n);
	vi lazy(4*n,0);
	build(0,n-1,1,SGT,arr);
    while(m--){
        ll q;
        cin>>q;
        if(q==1){
            ll l,r,v;
            cin>>l>>r>>v;
            r--;
            update(0,n-1,1,SGT,lazy,l,r,v);
        }
        else{
            int x,l;
            cin>>x>>l;
            ll ans = n+1;
            int start = l;
            int end = n-1;

            while(start<=end){
                ll mid = (start+end)/2;
                ll maxRange = query(0,n-1,1,SGT,lazy,l,mid);
                if(maxRange>=x){
                    ans = min(ans,mid);
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            if(ans>n){
                cout<<-1<<endl;
            }
            else{
                cout<<ans<<endl;
            }
        }
    }
}

int main(){
	solve();
}
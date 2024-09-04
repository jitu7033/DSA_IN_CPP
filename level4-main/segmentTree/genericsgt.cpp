#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int>vi;
typedef vector<long long>vl;
#define fl(i,a,b) for(int i=a; i<b; i++)


// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node2 {
	ll val; // may change
	Node2() { // Identity element
		val = INT_MIN;	// may change
	}
	Node2(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node2 &l, Node2 &r) { // Merge two child nodes
		val = max(l.val,r.val);  // may change
	}
};

struct Update2 {
	ll val; // may change
	Update2(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node2 &a) { // apply update to given node
		a.val = val; // may change
	}
};

struct Node1 {
	ll val; // may change
	Node1() { // Identity element
		val = 0;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = max(l.val,r.val);  // may change
	}
};

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};
int greaterCount(vector<ll>&arr,int target){
	int n = arr.size();
   SegTree<Node1,Update1>sgt = SegTree<Node1,Update1>(n,arr);
   int l = 0;
   int r = arr.size();
   int ans = arr.size();
   while(l<=r){
	   	int mid = (l+r)/2;
	   	int mini = sgt.make_query(0,mid).val;
	   	if(mini>target){
	   		r = mid-1;
	   		ans = min(ans,mid);
	   	}
	   	else{
	   		
	   		l = mid+1;
	   	}
    }
    cout<<ans<<"  go on goa "<<nline;
    cout<<arr.size()-ans<<"  size - ans"<<nline;
   	return arr.size()-ans;
}

void solve(vector<int>&nums){
	vector<ll>num1;
	vector<ll>num2;
	num1.push_back(nums[0]);
	num2.push_back(nums[1]);
	vector<int>ans;
	for(int i=2; i<nums.size(); i++){
		int count1 = greaterCount(num1,nums[i]);
		int count2 = greaterCount(num2,nums[i]);
            if(count1>count2){
                num1.push_back(nums[i]);
                cout<<"yes"<<endl;
            }
            else if(count1<count2){
                num2.push_back(nums[i]);
                cout<<"yes2"<<endl;
            }
            else{
                if(num1.size()<num2.size()){
                   
                    num1.push_back(nums[i]);
                    cout<<"yes3"<<endl;
                }
                else if(num1.size()>num2.size()){
                    num2.push_back(nums[i]);
                    cout<<"Yes4"<<nline;
                }
                else{
                    num1.push_back(nums[i]);
                    cout<<"Yes"<<endl;
                }
            }
        }
        for(auto &i:num1){
            ans.push_back(i);
        }
        for(auto &i:num2){
            ans.push_back(i);
        }
        for(auto &i:ans){
        	cout<<i<<" ";
        }
        cout<<nline;
        // return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>nums(n);
		fl(i,0,n)cin>>nums[i];
		solve(nums);
	}
}
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

struct Node1 {
	ll val; // may change
	Node1() { // Identity element
		val = 1e9;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = min(l.val ,r.val);  // may change
	}
};

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = max(a.val,val); // may change
	}
};



// second minimum 


struct NodesecondMin {
	pair<ll,ll>val; // may change
	NodesecondMin() { // Identity element
		val = {INF,INF};	// may change
	}
	NodesecondMin(ll p1) {  // Actual Node
		val = {p1,INF}; // may change
	}
	void merge(NodesecondMin &l, NodesecondMin &r) { // Merge two child nodes
		 if(l.val.first<r.val.first){
		 	val.first = l.val.first;					// may change
		 	val.second = min(l.val.second,r.val.first);

		 } 
		 else{
		 	val.first = r.val.first;
		 	val.second = min(r.val.second,l.val.first);
		 }
	}
};

struct UpdatesecondMin {
	ll val; // may change
	UpdatesecondMin(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(NodesecondMin &a) { // apply update to given node
		a.val = {val,INF}; // may change
	}
};

void solve(){
	int n;
	cin>>n;
	vector<ll>arr(n);
	fl(i,0,n)cin>>arr[i];
	SegTree<NodesecondMin,UpdatesecondMin>sgt = SegTree<NodesecondMin,UpdatesecondMin>(n,arr);
	cout<<sgt.make_query(0,3).val.second<<endl;
	sgt.make_update(2,6);
	cout<<sgt.make_query(2,5).val.second<<endl;
}

int main(){
	solve();
}

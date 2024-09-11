// jitendra17dec4 
// codeforces  round 959 div 1+ div 2 Solution 
// jay maa sarswati

    #include<bits/stdc++.h>
    using namespace std;
    using namespace chrono;
    #define MOD 1000000007
    #define MOD1 998244353
    #define INF 1e9
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
    #define int long long
    typedef vector<int>vi;
    typedef vector<long long>vl;
    #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define fl(i,a,b) for(int i=a; i<b; i++)

    void debug(vector<int>arr){
        for(auto &i:arr){
            cout<<i<<" ";
        }
        cout<<nline;
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    mod ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool findCycle = false;


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
		val = l.val+r.val;  // may change
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

void dfs(int n,int m, int x, int y, int fromX, int fromY, vector<string>&board,
 char needColor, vector<vector<int>>&vis){
 	if(x<0 || y<0 || x>=n || y>=m){
 		return;
 	}
 	if(board[x][y]!=needColor){
 		return;
 	}
 	if(vis[x][y]){
 		findCycle = true;
 		return;
 	}
 	vis[x][y] = 1;
 	for(int i=0; i<4; i++){
 		int nr = x+dx[i];
 		int nc = y+dy[i];
 		if(nr==fromX && nc==fromY){
 			continue;
 		}
 		dfs(n,m,nr,nc,x,y,board,needColor,vis);
 	}

}

bool checkCycle(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<int>&instack){
	vis[node] = 1;
	bool cycle = 0;
	instack[node] = 1;
	for(int child:adj[node]){
		if(!vis[child]){
			cycle = cycle || checkCycle(child,node,adj,vis,instack);
		}
		else{
			if(instack[child]){
				cycle = true;
			}
		}
	}
	instack[node] = 0;
	return cycle;
}

void __dfs(ll node,ll parent,vector<vector<ll>>&edges,vector<ll>&cnt){
	if(edges[node].size()==1 && edges[node][0]==parent){
		cnt[node] = 1;
	}
	else{
		for(int child:edges[node]){
			if(child!=parent){
				__dfs(child,node,edges,cnt);
				cnt[node]+=cnt[child];
			}
		}
	}
}

struct DSU{
	int n;
	vector<int>leader,sizes;

	DSU(int _n){
		n = _n+1;
		leader.resize(n);
		sizes.resize(n);
		for(int i=0; i<n; i++){
			leader[i] = {i};
			sizes[i] = 1;
		}
	}
	int find(int node){
		if(leader[node]==node)return node;
		return  find(leader[node]);
	}
	void join(int x, int y){
		int a = find(x);
		int b = find(y);

		if(a==b){
			return;
		}
		if(sizes[a]==sizes[b]){
			sizes[a]++;
		}
		if(sizes[a]>sizes[b]){
			leader[b] = a;
		}
		else{
			leader[a] = b;
		}
	}
};


ll kruskal(vector<vector<int>>&edges, int n){
	sort(edges.begin(),edges.end());
	DSU dsu(n);
	ll mst = 0;
	for(auto edge:edges){
		int u = edge[1],v = edge[2],wt = edge[0];
		if(dsu.find(u)!=dsu.find(v)){
			dsu.join(u,v);
			mst+=wt;
		}
	}
	return mst;
}

struct fenwick{
	int n;
	vector<int>bit;
	int query(int id){
		int ans = 0;
		while(id >= 0){
			ans += bit[id];
			id -= (id & -id);
		}
		return ans;
	}
	void update_query(int id, int val){
		while(id <= n){
			bit[id] +=  val;
			id += (id & -id);
		}
	}
};

void solve(){
	int n;
	cin>>n;
	vector<int>bit(n+1);
	for(int i = 1; i <= n; i++){
		cin>>bit[i];
	}
	fenwick fen;
	fen.bit = vector<int>(n+1,0);
	for(int i = 1; i <= n; i++){
		fen.update_query(i,bit[i]);
	}

	cout<<fen.query(3);
}


signed main(){
	// fastio();
	int testCases = 1;
	// cin>>testCases;
	while(testCases--){
		solve();
	}
}




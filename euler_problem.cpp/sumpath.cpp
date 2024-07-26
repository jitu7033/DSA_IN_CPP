    // jitendra17dec2 
    // codeforces round 929 div 3 solution 

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
    void debug(vector<int>&v){
        for(auto &i:v){
            cout<<i<<" ";
        }
        cout<<nline;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    mod ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
    ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))


int maxLogN = 30;

template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
        if(start > right || end < left)
            return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val; // may change
    Node1() { // Identity element
        val = 0;    // may change
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = (l.val+r.val);  // may change
    }
};

struct Update1 {
    ll val; // may change
    Update1(){ // Identity update
        val = 0;
    }
    Update1(ll val1) { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end) { // apply update to given node
        a.val += val * (end - start + 1); // may change
    }
    void combine(Update1& new_update, int start, int end){
        val += new_update.val;
    }
};


void populatedFirstParent(int curr,vector<vector<int>>&adj,int imidiateParent,vector<vector<int>>&parents){
    parents[curr][0] = imidiateParent;
    for(int child:adj[curr]){
        if(child!=imidiateParent)
            populatedFirstParent(child,adj,curr,parents);
    }
}
void buildBinaryTable(vector<vector<int>>&parents,int n, int limit){
    for(int j=1; j<limit;j++){
        for(int i=0; i<n; i++){
            int intermidiate = parents[i][j-1];
            if(intermidiate!=-1){
                parents[i][j] = parents[intermidiate][j-1];
            }
        }
    }
}

int  kthParent(int x, int k, vector<vector<int>>&parents){
    for(int i=0; i<maxLogN; i++){
        if(k&(1<<i)){
            x = parents[x][i];
        }
    }
    return x;

}

void populatedlevel(int curr,vector<vector<int>>&adj,int parents, vector<int>&level){
    if(parents==-1){
        level[curr] = 0;
    }
    else{
        level[curr] = level[parents]+1;
    }
    for(int child:adj[curr]){
        if(child!=parents){
            populatedlevel(child,adj,curr,level);
        }
    }
}

int  LCA(int x, int y, vector<vector<int>>&parents, vector<int>&level,int n){
    if(level[x]>level[y]){
        x = kthParent(x,level[x]-level[y],parents);
    }
    if(level[y]>level[x]){
        y = kthParent(y,level[y]-level[x],parents);
    }
    if(x==y){
        return x;
    }
    int start = 1; int end = n; int ans = n;
    while(start<=end){
        int mid = (start+end)/2;
        if(kthParent(x,mid,parents)==kthParent(y,mid,parents)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return kthParent(x,ans,parents);
}

int x = 1;
void dfs(int curr, vector<vector<int>>&adj, int parent, vector<int>&euler,
 vector<ll>&euler_val,vector<int>&value,vector<ll>&in_time,vector<ll>&out_time){
    euler.push_back(curr);
    euler_val.push_back(value[curr]);
    in_time[curr] = x++;

    for(int child:adj[curr]){
        if(child!=parent){
            dfs(child,adj,curr,euler,euler_val,value,in_time,out_time);
        }
    }
    euler.push_back(curr);
    euler_val.push_back(-(value[curr]));
    out_time[curr] = x++;
}
void solve(){
    int n;
    cin>>n;
    vector<int>value(n);
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>euler;
    vector<ll>euler_val;
    vector<ll>in_time(n,0);
    vector<ll>out_time(n,0);
    dfs(0,adj,-1,euler,euler_val,value,in_time,out_time);

    for(auto i:euler){
        cout<<i<<" ";
    }
    cout<<nline;
    for(auto i:euler_val){
        cout<<i<<" ";
    }
    cout<<nline;
    for(auto &i:in_time){
        cout<<i<<" ";
    }
    cout<<nline;
    for(auto i:out_time){
        cout<<i<<" ";
    }
    cout<<nline;
    // lca find here dd
    vector<int>level(n);
    vector<vector<int>>parents(n,vector<int>(maxLogN,-1));
    populatedFirstParent(0,adj,-1,parents);
    buildBinaryTable(parents,n, maxLogN);
    int lca = LCA(3,4,parents,level,n);
    cout<<lca<<"  --<  LCA"<<nline;
    n = euler_val.size();
    LazySGT<Node1,Update1>sgt = LazySGT<Node1,Update1>(n,euler_val);
    int l = in_time[lca];
    int r1 = in_time[3];
    int r2 = in_time[4];

    cout<<l<<" "<<r1<<" "<<r2<<nline;
    l--;
    r1--;
    r2--;
    cout<<euler_val[l]<<" "<<euler_val[r1]<<" "<<euler_val[r2]<<nline;
    sgt.make_update(r2,r2,10);
    sgt.make_update(out_time[6],out_time[6],-10);

    cout<<sgt.make_query(l,r1).val<<nline;
    cout<<sgt.make_query(l,r2).val<<nline;
}
int main(){
    solve();
}
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
int LCA1(int x, int y,vector<vector<int>>&parents,vector<int>&level,int n){
    if(level[x]>level[y]){
        x = kthParent(x,level[x]-level[y],parents);
    }
    if(level[y]>level[x]){
        y  =kthParent(y,level[y]-level[x],parents);
    }
    if(x==y){
        return x;
    }
    for(int i =  maxLogN-1; i>=0; i--){
        if(parents[x][i]!=parents[y][i]){
            x = parents[x][i];
            y = parents[y][i];
        }
    }
    return parents[x][0];
}
int  LCA(int x, int y, vector<vector<int>>&parents, vector<int>&level,int n){
    if(level[x]>level[y]){
        x = kthParent(x,level[x]-level[y],parents);
    }
    if(level[y]>level[x]){
        y = kthParent(y,level[y]-level[x],parents);
    }
    if(level[x]==level[y]){
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
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>());
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // cout<<"chal bhai"<<nline;
    vector<int>level(n);
    vector<vector<int>>parents(n,vector<int>(maxLogN,-1));
    populatedFirstParent(0,adj,-1,parents);
    buildBinaryTable(parents,n, maxLogN);
    cout<<kthParent(3,2,parents)<<nline;
    populatedlevel(0,adj,-1,level);
    // cout<<"kha "<<nline;
    for(auto i:level){
        cout<<i<<" ";
    }
    cout<<nline;
    cout<<LCA1(3,4,parents,level,n)<<"  Lca"<<nline;
}
int main(){
    fastio();
    solve();
}
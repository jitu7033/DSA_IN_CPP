// jitendra17dec1 
// codeforces educational round 162 div 2 Solution 

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
void debug(vector<int>arr,int n){for(int i=0; i<n; i++){cout<<arr[i]<<" ";}cout<<nline;}



int n = 1e8;
vector<int>timein(n);
vector<int>timeout(n);
int counter = 0;
void dfs(int currNode, vector<vector<int>>&adj,int parent, vector<int>&ans){
    ans.push_back(currNode);
    timein[currNode] = ++counter;
    for(int neighbour:adj[currNode]){
        if(neighbour!=parent){
            dfs(neighbour,adj,currNode,ans);
        }
    }
    timeout[currNode] = ++counter;
}

void is_ancestor(){
    int x,y;
    cin>>x>>y;
    if(timein[x-1]<timein[y-1] && timeout[x-1]>timeout[y-1]){
        cout<<"Yes"<<nline;
    }
    else{
        cout<<"No"<<nline;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1; i++){
        // cout<<i<<"i"<<endl;
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cout<<u<<" "<<v<<endl;
    }
    int root = 0;
    vector<int>dfs_traversal;
    dfs(root,adj,-1,dfs_traversal);
    for(auto &i:dfs_traversal){
        cout<<i<<" ";
    }
    cout<<nline;
    debug(timein,n);
    debug(timeout,n);
    is_ancestor();
}



int main(){
    solve();

}

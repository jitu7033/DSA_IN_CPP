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


void dfs(int curr, vector<vector<int>>&adj,int parent, vector<int>&ans,vector<int>&max_depth){// o(n)
    pair<int,int>bestchildren= {-1,-1};
    for(int neighbour:adj[curr]){
        if(neighbour!=parent){
            dfs(neighbour,adj,curr,ans,max_depth);
            int currdepths = max_depth[neighbour];
            if(currdepths>bestchildren.first){
                bestchildren.second = bestchildren.first;
                bestchildren.first = currdepths;
            }
            else if(currdepths>bestchildren.second){
                bestchildren.second = currdepths;
            }
        }
    }
    if(bestchildren.first==-1){
        max_depth[curr] = 0;ans[curr] = 0;
    }
    else if(bestchildren.second==-1){
        max_depth[curr] = bestchildren.first+1;
        ans[curr] = bestchildren.first+1;
    }
    else{
        max_depth[curr] = bestchildren.first+1;
        ans[curr] = bestchildren.first+bestchildren.second+2;
    }
}

void solve(){
    int n;
    cin>>n;
    // cout<<"chal rha hai";
    vector<vector<int>>adj(n);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    // cout<<"chal raha hai"<<endl;
    vector<int>ans(n);
    vector<int>max_depth(n);
    dfs(0,adj,-1,ans,max_depth);
    // cout<<ans.size()<<nline;
    for(auto &i:ans){
        cout<<i<<" ";
    }
}

int main(){
    solve();
}
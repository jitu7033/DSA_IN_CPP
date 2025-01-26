#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define epb emplace_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
#define int long long
typedef vector<int>vi;
typedef vector<long long>vl;
// Define the ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fl(i,a,b) for(int i=a; i<b; i++)
void debug(vector<int>arr){for(auto &i:arr){cout<<i<<" ";}cout<<nline;}
// ~~~~~~~~

ll gcd(ll a, ll b) {
	if (b > a) {
		return gcd(b, a);
	}
	if (b == 0) {
	 	return a;
	} 
	return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {
	if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;}
 extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr);
 return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
// ~~    mod ~~~~
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; 
return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; 
while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0)
 {while (n % i == 0)n /= i; number = (number / i * (i - 1));}}
  if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))




vector<pair<int,int>>direction = {{1,0},{-1,0},{0,1},{0,-1}};
vector<int>dix = {1,-1,0,0};
vector<int>diy = {0,0,-1,1};
// ~~~~~~~~~~~~
// use binary search in pair vector 
int lower_bound(vector<pair<int,int>>&v, int &target){int start = 0;int end = v.size()-1;int ans = v.size();while(start <= end){int mid = (start + end )/2;if(v[mid].first < target){start = mid + 1;}else{ans = mid;end = mid - 1;}}return ans;} // O(log n)



void __FloydWarshall(int n,vector<vector<pair<int,int>>>&adj,vector<vector<int>>&dist){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(auto j:adj[i]){
			dist[i][j.ff] = min(dist[i][j.ff],j.ss);
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][k] < INF and dist[k][j] < INF)
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}
}

vector<vector<int>>ans;

void dfs(int src, int dest, vector<vector<int>>&adj, vector<int>&vis,vector<int>&path){
	path.push_back(src);
	if(src == dest){
		ans.push_back(path);
	}
	vis[src] = 1;
	for(auto &child: adj[src]){
		if(!vis[child]){
			dfs(child,dest,adj,vis,path);
		}
	}
	path.pop_back();
}

// 1 2 3 0

void rec(int idx , vector<int>&v, vector<vector<int>>&ans){
	if(idx >= v.size() - 1){
		ans.push_back(v);
		return;
	}
	for(int i = idx; i < v.size(); i++){
		swap(v[idx],v[i]);
		rec(idx+1, v,ans);
		swap(v[idx],v[i]);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i = 1; i <= n; i++){
		v.push_back(i);
	}
	for(int i = 0; i < (m - n); i++){
		v.push_back(0);
	}
	vector<vector<int>>ans;
	vector<int>temp;
	rec(0,v,ans);
	for(auto &x: ans){
		for(auto &y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}



signed main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}

}

// precuation 
// check code properly min  two time 
// build good testcase then submit
// jitendra17dec4 
// codeforces  round 959 div 1+ div 2 Solution 
// jay maa sarswati

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

void solve5(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n,vector<int>());
	vector<vector<int>>edges(m,vector<int>(3));
	for(int i=0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i] = {w,u,v};
	}
	vector<int>vis(n,0);
	function<void(int)>dfs = [&](int node){
		vis[node] = 1;
		for(auto &i:adj[node]){
			if(!vis[i]){
				dfs(i);
			}
		}
	};
	int count = 0;
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			count++;
			dfs(i);
		}
	}
	if(count>1){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<kruskal(edges,n)<<endl;
}


void dijkstra(int src,vector<vector<pair<int,ll>>>&adj, vector<ll>&dist, vector<int>&parent){
	fill(dist.begin(),dist.end(),1e9);
	int n = dist.size();
	dist[src] = 0;
	set<pair<ll,int>>unvisited;
	for(int i=0; i<n; i++){
		unvisited.insert({dist[i],i});
	}
	while(unvisited.size()>0){
		pair<ll,int>minDist = *unvisited.begin();  // min distance 
		unvisited.erase(minDist); // marking node as visited 
		int minDistNode = minDist.second;
		ll shortestDistToNodes = minDist.first;
		for(pair<int,ll>neighbour:adj[minDistNode]){
			ll oldDIst = dist[neighbour.first];
			ll newDist = shortestDistToNodes+neighbour.second;
			if(newDist<oldDIst){
				unvisited.erase({oldDIst,neighbour.first});
				dist[neighbour.first] = newDist;
				parent[neighbour.first] = minDistNode;
				unvisited.insert({newDist,neighbour.first});
			}
		}
	}
} 



void solve(){

	int n;
	cin>>n;
	vector<int>v(n);
	vector<int>cap(n);
	for(auto &i:v){
		cin>>i;
	}
	vector<ll>pref;
	ll sum = 0;
	for(auto &i:cap){
		cin>>i;
		sum+=i;
		pref.push_back(sum);
	}
	vector<ll>ans(n,0);
	for(auto &ele:v){
		auto lower = lower_bound(pref.begin(),pref.end(),ele);
		int index = distance(pref.begin(),lower);
		cout<<index<<endl;
	}
}

int main(){
	int testCases;
	cin>>testCases;
	while(testCases--){
		solve();
	}
}
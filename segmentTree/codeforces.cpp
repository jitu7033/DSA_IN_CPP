        // jitendra17dec2 
        // codeforces round 935 div 3 solution 

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

        void debug(vector<int>arr){for(auto &i:arr){cout<<i<<" ";}cout<<nline;}
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
        ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
        void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
        ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
        ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
        ll lcm(ll a, ll b){
                return (a*b)/gcd(a,b);}
        void debug(vector<int>&v){
                for(auto &i:v){
                    cout<<i<<" ";
                }
                cout<<nline;}
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    mod ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
        ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
        ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
        ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
        ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

        vector<int>store_prime;
        vector<int>seive(){
            vector<int>primes(1e6+1,1);
            primes[0] = 0;
            primes[1] = 0;
            cout<<primes.size()<<endl;
            for(int i=2; i*i<=1e6; i++){
                if(primes[i]==1){
                    store_prime.push_back(i);
                    for(int j=i*i; j<=1e6; j+=i){
                        primes[j] = 0;
                    }
                }
            }
            return primes;
        }



        ll joshepus(ll n, ll k,vector<ll>&ans){
            int res = 0; 
            for(int i=1; i<=n; i++){
                res = (res+k)%i;
            }
             return res+1;;
        }

        int dfs(int currNode, vector<vector<int>>&edges,int parents,vector<int>&ans){
            if(edges[currNode].size()==0){
                return 1;
            }
            int cnt = 0;
            for(auto child:edges[currNode]){
                if(child!=parents){
                    int temp = dfs(child,edges,currNode,ans);
                    cnt+=(temp);
                }
            }
            ans[currNode] = cnt;
            return cnt+1;
        }


        class solution{
        public:int count = 0;
        public:
            void permutaion(string s,int idx, set<string> &ans){
                if(idx==s.length()-1){
                    string temp = "";
                    for(int i=0; i<s.length(); i++){
                        temp.push_back(s[i]);
                    }
                    ans.insert(temp);
                    return;
                }
                
                for(int i=idx; i<s.length(); i++){
                    swap(s[i],s[idx]);
                    permutaion(s,idx+1,ans);
                    swap(s[i],s[idx]);
                }
            }
        };

        void joshep(int n,vector<int>&arr, int index, vector<int>&ans){
            if(arr.size()==1){
                ans.push_back(arr[0]+1);
                return;
            }
            index = (index+1)%arr.size();    
            ans.push_back(arr[index]+1); 
            arr.erase(arr.begin()+index);
            joshep(n,arr,index,ans);
        }
        void dfs(int node, int parents, vector<vector<int>>&adj, vector<int>&sz,vector<int>&ans){
            ans[node] = 0;
            sz[node] = 1;

            for(int child:adj[node]){
                if(child!=parents){
                    dfs(child,node,adj,sz,ans);
                    ans[node] += ans[child]+sz[child];
                    sz[node] +=sz[child];
                }
            }
        }
        void dfs_max(int node, int parent,vector<vector<int>>&adj,vector<int>ans){
            ans[node] = 0;
            for(auto child:adj[node]){
                if(child!=parent){
                    dfs_max(child,node,adj,ans);
                    ans[node] = max(ans[node],ans[child]+1);
                }
            }
        }

        void dfs_subtree(int node,int parent,vector<vector<int>>&adj,vector<int>&ans){
            ans[node] = 1;
            for(auto child:adj[node]){
                if(child!=parent){
                    dfs_subtree(child,node,adj,ans);
                    ans[node] += ans[child];
                }
            }
        }

        void dfs_gcd(int node,int parent,vector<vector<int>>&adj,vector<int>&ans,vector<int>&a){
            ans[node] = a[node];
            for(auto child:adj[node]){
                if(child!=parent){
                    dfs_gcd(child,node,adj,ans,a);
                    ans[node] = __gcd(ans[node],ans[child]);
                }
            }
        }
        // 2 4 1 2 7
        // 2 6 7 9 16
        // 

        bool custom_comparator(const pair<ll,ll>&a,const pair<ll,ll>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            else{
                return a.second<b.second;
            }
        }

int diff(string s, string s1){
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=s1[i]){
            count++;
        }
    }
    return count;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            v.push_back(n/i);
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    for(auto &x:v){
        string p = s.substr(0,x);string temp = "";
        for(int i=0; i<n/x; i++)temp+=p;
        // cout<<temp<<endl;
        if(diff(temp,s)<=1){
            cout<<x<<endl;
            break;
        }
        string p1 = s.substr(x,x);string temp1 = "";
        for(int i=0; i<n/x; i++)temp1+=p1;
        if(diff(temp1,s)<=1){
            cout<<x<<endl;
            break;
        }
    }
}
int main(){
    fastio();
    int t;
    t = 1;
    cin>>t;
    while(t--){
        solve();
         // cout<<"next"<<endl;
    }
}




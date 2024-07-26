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


    void dfs(int curr, vector<vector<int>>&adj,int parent,vector<int>&dist){
        if(parent==0)dist[curr]= 0;
        else dist[curr] = dist[parent]+1;

        for(int child:adj[curr]){
            if(child!=parent){
                dfs(child,adj,curr,dist);
            }
        }
    }

    void solve(){
        int n;
        cin>>n;
        vector<vector<int>>adj(n+1,vector<int>());
        for(int i=0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // cout<<"chal rha hai kya"<<nline;
        vector<int>dist1(n+1),dist2(n+1),dist3(n+1);
        dfs(1,adj,0,dist1);

        int end_point = max_element(dist1.begin()+1,dist1.end())-dist1.begin();
        dfs(end_point,adj,0,dist2);

        int end_point2 = max_element(dist2.begin()+1,dist2.end())-dist2.begin();
        dfs(end_point2,adj,0,dist3);

        for(int i=1; i<=n; i++){
            cout<<max(dist2[i],dist3[i])<<" ";
        }
        cout<<nline;
        // cout<<"Nihi chal rha hai"<<nline;
    }



    int main(){
        int t;
        t = 1;
        // cin>>t;
        while(t--){
            solve();
        }
    }
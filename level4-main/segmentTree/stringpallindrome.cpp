    // jitendra17dec2 
    // codeforces round 933 div 3 solution 

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


bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void buildSegmentTree(const string& s, vector<bool>& segTree, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = true; // Single character is palindrome
        return;
    }

    int mid = (low + high) / 2;
    buildSegmentTree(s, segTree, low, mid, 2 * pos + 1);
    buildSegmentTree(s, segTree, mid + 1, high, 2 * pos + 2);

    segTree[pos] = segTree[2 * pos + 1] && segTree[2 * pos + 2] && isPalindrome(s, low, high);
}

bool querySegmentTree(const vector<bool>& segTree, int low, int high, int pos, int start, int end) {
    // If the current segment lies completely outside the query range
    if (start > high || end < low)
        return true;

    // If the current segment lies completely inside the query range
    if (start <= low && end >= high)
        return segTree[pos];

    // If the current segment overlaps with the query range
    int mid = (low + high) / 2;
    return querySegmentTree(segTree, low, mid, 2 * pos + 1, start, end) &&
           querySegmentTree(segTree, mid + 1, high, 2 * pos + 2, start, end);
}

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin >> s;
    vector<bool>SGT(4 * n, false);
    buildSegmentTree(s, SGT, 0, n - 1, 0);

    while(q--){
        int x,y;
        cin>>x>>y;
        if(!querySegmentTree(SGT,0,n-1,0,x,y)){
            long long ans = (y-x)+1;
            cout<<ans<<nline;
            cout<<((ans*(ans+1))/2)-1<<nline;
        }
        else{
            cout<<0<<nline;
        }
    }

}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

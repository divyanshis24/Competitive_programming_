#include <bits/stdc++.h>
#define ll long long 
#define int long long 
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define ff first
#define ss second
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);

        // cout << seg << endl;
	}

	int query(int ind, int low, int high, int l, int r, int val) {
		// no overlap
		// l r low high or low high l r
		// if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		// if (low >= l && high <= r) return seg[ind];
		
		if(low == high)
		{
			cout << "hit 0" ;

			if(seg[ind] >= val)
			{
				cout << seg[ind] << " sds  "<< low << endl;
				cout << "hit 1" ;

				// return low + 1;

			}
			else
			{
				cout << seg[ind] << " sds  "<< low << endl;

				cout << " hit 2" ;
				// return -1;

			}
		}

		cout << "hit 4" << endl;


		int mid = (low + high) >> 1;

		cout << low << " " << high << endl;
		cout << mid << endl;

		if(seg[2 * ind + 1] >= val)
		query(2 * ind + 1, low, mid, l, r, val);
		else if(seg[2 * ind + 2] >= val)
		query(2 * ind + 2, mid + 1, high, l, r, val);
		else
		return -1;

	}

	int query_value(int ind, int low, int high, int l, int r, int val) {
		// no overlap
		// l r low high or low high l r
		// if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		// if (low >= l && high <= r) return seg[ind];

		if(low == high)
		{
			if(seg[ind] >= val)
			{
				cout << seg[ind] << " sds  "<< low << endl;

				return seg[ind];

			}
			else
			{
				return -1;

			}
		}

		int mid = (low + high) >> 1;

		if(seg[2 * ind + 1] >= val)
		query(2 * ind + 1, low, mid, l, r, val);
		
		else if(seg[2 * ind + 2] >= val)
		query(2 * ind + 2, mid + 1, high, l, r, val);

	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] -= val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] =  max(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

    void display(int n)
    {
        n = 4 * n + 1;
        for (int i = 0; i < n; i++)
        {
            cout << seg[i] << " ";
        }
        cout << endl;
        
    }
};

const int MOD = 1e9 + 7;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll mult(ll x, ll y) {ll res = x * y;return (res >= MOD ? res % MOD : res);}
ll factorial(ll v){ll ans=1;for(int i=2;i<=v;i++){ans*=i;ans%=MOD;}return ans;}
ll power(ll x, ll y){   if (y < 0)return 1;ll res = 1; x %= MOD;while (y!=0) {if ((y & 1)==1)res = mult(res, x); y >>= 1;x = mult(x, x);} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void vin( vector<int> &v , int n ){for (int i = 0; i < n; i++){int x ;cin >> x; v.push_back(x);}}
void vout(vector<int> &v){for (int i = 0; i < v.size(); i++){cout << v[i] << " " ;}cout << endl;}
ll highestPowerof2(ll n){ ll p = (ll)log2(n);   return (ll)pow(2, p);}
bool isPowerOfTwo(int n){ if(n==0)   return false;   return (ceil(log2(n)) == floor(log2(n)));}
bool chkprime(int n){ for(int i = 2 ; i*i <= n ; i++){ if( n % i == 0) return false;} return true; }
string to_binary(int n) { string s = ""; for (int i = 31; i >= 0; i--) { int k = n >> i; if (k & 1) s = s + "1";else s = s + "0";}return s ; }
static void removeTrailingCharacters(std::string &str, const char charToRemove) {str.erase (str.find_last_not_of(charToRemove) + 1, std::string::npos );}
static void removeLeadingCharacters(std::string &str, const char charToRemove) {str.erase(0, std::min(str.find_first_not_of(charToRemove), str.size() - 1));}
long long lcm(int a, int b){    return (a / gcd(a, b)) * b;}
int digits_count(int n){int d=0;while(n != 0){d++;n /=10;}return d;}

void prakhar() {

    int n ;
    cin >> n ; 
    vi v;
    vin(v, n);

    vi ans;
    ans.pb(v[0]);

    int f = 0 ;

    for (int i = 1; i < n; i++)
    {
        // v[i] if  b/w 1 and ans[i-1] - 1 then false

        if( v[i] >= 1 && v[i] < ans[i-1])
        {
            cout << -1 << endl;
            return;
        }
        else {

            ans.pb(ans[i-1] + v[i]);
        } 
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    

    



}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    ll t = 1 ;
    cin >> t ;
    for (int i = 0; i < t; i++) {
        prakhar();
    }
    
    return 0;
    
}
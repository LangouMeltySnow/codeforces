//Another
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define endl "\n"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> PLL;
typedef tuple<ll, ll, ll> TLLL;

const ll INF = (ll)2e18 + 9;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ld PI = 3.14159265358979323;
const int MAXN = 20005;
const int MAXM = 2005;
const int N = 100010;

template<typename T> inline void rd(T &x) {x = 0; short f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();} while (isdigit(ch)) {x = (x << 3) + (x << 1) + (ch ^ 0x30); ch = getchar();} x *= f;}
template<typename T> inline void pt(T x) {if (x < 0) putchar('-'), x = -x; if (x > 9) pt(x / 10); putchar(x % 10 | 0x30);}

ll ksm(ll a, ll b, ll MOD) {ll res = 1; a %= MOD; while (b) {if (b & 1) {res = (res * a) % MOD;} a = (a * a) % MOD; b >>= 1;} return res % MOD;}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> mp(n, vector<ll> (n));
	vector<ll> a(n), b(n);
	vector<ll> dp(2), ndp(2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mp[i][j];
		}
	}
	ll ans = 0;
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;
	dp[0] = 0, dp[1] = a[0];
	for (int i = 1; i < n; ++i) {
		ndp = {INF, INF};
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				bool ok = true;
				for (int j = 0; j < n; ++j) {
					if (mp[i - 1][j] + x == mp[i][j] + y) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ndp[y] = min(ndp[y], dp[x] + y * a[i]);
				}
			}
		}
		dp = ndp;
	}
	ans += min(dp[0], dp[1]);

	dp[0] = 0, dp[1] = b[0];
	for (int j = 1; j < n; ++j) {
		ndp = {INF, INF};
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				bool ok = true;
				for (int i = 0; i < n; ++i) {
					if (mp[i][j - 1] + x == mp[i][j] + y) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ndp[y] = min(ndp[y], dp[x] + y * b[j]);
				}
			}
		}
		dp = ndp;
	}

	ans += min(dp[0], dp[1]);
	cout << (ans >= INF ? -1 : ans) << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
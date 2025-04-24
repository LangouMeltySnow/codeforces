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
	ll n, k, sum = 0, mx = -1, mn = INF;
	bool f = true;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (auto &v : a) cin >> v, mx = max(mx, v), mn = min(mn, v);
	for (auto &v : b) cin >> v;
	for (int i = 0; i < n; ++i) {
		if (b[i] != -1) {
			if (f) {
				sum = a[i] + b[i];
				f = 0;
			} else {
				if (sum != a[i] + b[i]) {
					cout << 0 << endl;
					return;
				}
			}
		}
	}
	if (f) {
		cout << k + mn - mx + 1 << endl;
	} else if (sum < mx || mn + k < sum) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
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
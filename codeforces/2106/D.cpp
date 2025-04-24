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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (ll &v : a) cin >> v;
	for (ll &v : b) cin >> v;

	ll cur = 0;
	bool f = true;
	for (ll i = 0; i < m; ++i) {
		while (cur < n && a[cur] < b[i]) {
			++cur;
		}
		if (cur >= n) {
			f = false;
			break;
		}
		++cur;
	}
	if (f) {
		cout << 0 << endl;
		return;
	}

	vector<ll> pre(m + 1, INF);
	pre[0] = -1;
	cur = 0;
	for (ll i = 0; i < m; ++i) {
		while (cur < n && a[cur] < b[i]) {
			++cur;
		}
		if (cur >= n) break;
		pre[i + 1] = cur;
		++cur;
	}

	vector<ll> suf(m + 1, -1);
	suf[0] = n;
	cur = n - 1;
	for (ll i = 0; i < m; ++i) {
		ll j = m - 1 - i;
		while (cur >= 0 && a[cur] < b[j]) {
			--cur;
		}
		if (cur < 0) break;
		suf[i + 1] = cur;
		--cur;
	}

	if (pre[m] <= n - 1) {
		cout << 0 << endl;
		return;
	}

	ll ans = INF;

	for (ll i = 0; i < m; ++i) {
		if (pre[i] == INF) continue;
		ll need_suf = m - i - 1;
		if (suf[need_suf] == -1) continue;
		if (pre[i] < suf[need_suf]) {
			ans = min(ans, b[i]);
		}
	}

	if (pre[m - 1] != INF) {
		ans = min(ans, b[m - 1]);
	}

	if (ans == INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
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
//Another
#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
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

//const ll INF = (ll)2e18 + 9;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ld PI = 3.14159265358979323;
const int MAXN = 2e4 + 5;
const int MAXM = 2e3 + 5;
const int N = 1e5;

template<typename T> inline void rd(T &x) {x = 0; short f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();} while (isdigit(ch)) {x = (x << 3) + (x << 1) + (ch ^ 0x30); ch = getchar();} x *= f;}
template<typename T> inline void pt(T x) {if (x < 0) putchar('-'), x = -x; if (x > 9) pt(x / 10); putchar(x % 10 | 0x30);}

ll ksm(ll a, ll b, ll MOD) {ll res = 1; a %= MOD; while (b) {if (b & 1) {res = (res * a) % MOD;} a = (a * a) % MOD; b >>= 1;} return res % MOD;}

ll pos[N + 5];
vector<ll> sep[N + 5];

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (auto &v : a) cin >> v;

	vector<ll> k(q), r(q);
	vector<vector<ll>> qry(n);
	for (int i = 0; i < q; ++i) {
		ll l;
		cin >> k[i] >> l >> r[i];
		l--;
		qry[l].pb(i);
	}
	vector<ll> ans(q);

	vector<ll> nxt(n, INF);
	for (int i = n - 1; i >= 0; --i) {
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		for (auto v : qry[i]) {
			while (k[v] % a[i] == 0) {
				k[v] /= a[i];
			}
			ll t = INF;
			for (auto u : sep[k[v]]) {
				t = min(t, pos[u]);
			}
			if (t >= r[v]) {
				ans[v] += 1LL * (r[v] - i) * k[v];
			} else {
				ans[v] += 1LL * (t - i) * k[v];
				qry[t].pb(v);
			}
		}
		pos[a[i]] = nxt[i];
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(pos, pos + N + 1, INF);
	for (ll i = 2; i <= N; ++i) {
		for (ll j = i; j <= N; j += i) {
			sep[j].pb(i);
		}
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
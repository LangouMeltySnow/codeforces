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
	ll q, x;
	cin >> q;
	ll op;
	ll ans = 0, reans = 0;
	ll sum = 0, sz = 0;
	deque<ll> a, rea;
	while (q--) {
		cin >> op;
		if (op == 1) {
			ans += sum - a.back() * sz;
			reans += rea.front() * sz - sum;
			a.pf(a.back());
			a.pop_back();
			rea.pb(rea.front());
			rea.pop_front();
		} else if (op == 2) {
			swap(ans, reans);
			swap(a, rea);
		} else if (op == 3) {
			cin >> x;
			a.pb(x);
			rea.pf(x);
			sz++;
			ans += sz * x;
			reans += sum + x;
			sum += x;
		}
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
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
	ll n, q, x, y;
	cin >> n >> q;
	string op;
	while (q--) {
		cin >> op;
		if (op == "<-") {
			cin >> x;
			x--;
			ll X = 0, Y = 0;
			for (int i = n - 1; i >= 0; --i) {
				ll cur = x >> (2 * i);
				if ((cur & 3) == 0) {
					X ^= 0 << i;
					Y ^= 0 << i;
				} else if ((cur & 3) == 1) {
					X ^= 1 << i;
					Y ^= 1 << i;
				} else if ((cur & 3) == 2) {
					X ^= 1 << i;
					Y ^= 0 << i;
				} else if ((cur & 3) == 3) {
					X ^= 0 << i;
					Y ^= 1 << i;
				}
			}
			cout << X + 1 << " " << Y + 1 << endl;
		} else {
			cin >> x >> y;
			x--, y--;
			ll X = 0;
			for (int i = n - 1; i >= 0; --i) {
				ll cur = 1 << i;
				if (!(x & cur) && !(y & cur)) {
					X ^= 0ll << (2 * i);
				} else if ((x & cur) && (y & cur)) {
					X ^= 1ll << (2 * i);
				} else if ((x & cur) && !(y & cur)) {
					X ^= 2ll << (2 * i);
				} else if (!(x & cur) && (y & cur)) {
					X ^= 3ll << (2 * i);
				}
			}
			cout << X + 1 << endl;
		}
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
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
	string s;
	cin >> n >> s;
	ll cnt0 = 0, cnt1 = 0, cut = 0;
	char tar = '0';
	for (auto v : s) {
		if (v != tar) {
			if (v == '1') cnt0++;
			else cnt1++;
			tar = v;
			cut++;
		}
	}
	// (0) 1 1 -> 0
	// (0) 1 0 -> -1
	// (0) 1 0 1 -> -2
	if (cnt0 <= 1 && cnt1 == 0) {
		cout << n + cut << endl;
	} else if (cnt0 == 1 && cnt1 == 1) {
		cout << n + cut - 1 << endl;
	} else {
		cout << n + cut - 2 << endl;
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
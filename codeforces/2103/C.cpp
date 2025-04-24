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

bool check(vector<ll> a, ll n) {
    vector<ll> pref(n), minpref(n);
    pref[0] = minpref[0] = a[0];

    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        minpref[i] = min(minpref[i - 1], pref[i]);
    }

    ll sum = 0;
    for (int i = n - 1; i - 2 >= 0; --i) {
        sum += a[i];
        if (sum < 0) continue;
        if (minpref[i - 2] <= pref[i - 1]) return true;
    }
    return false;
}
void solve() {
    ll n, k, t;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a[i] = t <= k ? 1 : -1;
    }

    ll sum, l = 0, r = n - 1;
    sum = a[l];
    while (l < n && sum < 0) {
        sum += a[++l];
    }
    sum = a[r];
    while (r >= 0 && sum < 0) {
        sum += a[--r];
    }
    if (r - l > 1) {
        cout << "YES" << endl;
        return;
    }

    if (check(a, n)) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n - i - 1; ++i) {
        swap(a[i], a[n - i - 1]);
    }

    if (check(a, n)) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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
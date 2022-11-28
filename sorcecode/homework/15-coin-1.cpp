#include<vector>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
ll n, m, a[2000005], q, x = 1, ans = 1, po = 1;
inline ll read() {
	ll x = 0, f = 1; char ch = ' ';
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
	return f == 1 ? x : -x;
}
int main() {
	n = read();
	m = read();
	for (ll i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] == 1) {
			q = 1;
		}
	}
	if (q == 0) {
		cout << "No answer!!!";
		return 0;
	}
	sort(a + 1, a + n + 1);
	while (1) {
		if (po == n) {
			ans += (m - x) / a[po];
			if ((m - x) % a[po] != 0)ans++;
			cout << ans;
			return 0;
		}
		for (int i = po; i <= n + 1; i++) {
			if (a[i] > x + 1 || i > n) {
				po = i - 1;
				x += a[po];
				ans++;
				break;
			}
		}
		if (x >= m) {
			cout << ans;
			return 0;
		}
	}
}
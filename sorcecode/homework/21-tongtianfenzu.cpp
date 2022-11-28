#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int v, n, t;
int x;
int g[205][205];
int i, j, k;
int w[10001], z[10001];
int b[10001];
int dp[10001];
int main() {
	cin >> v >> n;
	for (i = 1; i <= n; i++) {
		cin >> w[i] >> z[i] >> x;
		t = max(t, x);
		b[x]++;
		g[x][b[x]] = i;
	}
	for (i = 1; i <= t; i++) {
		for (j = v; j >= 0; j--) {
			for (k = 1; k <= b[i]; k++) {
				if (j >= w[g[i][k]]) {
					dp[j] = max(dp[j], dp[j - w[g[i][k]]] + z[g[i][k]]);
				}
			}
		}
	}
	cout << dp[v];
	return 0;
}
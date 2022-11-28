#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <list>
#include <queue>
#include <set>
using namespace std;
#define ll long long

int f[10000];
int find(int n) {
	if (f[n] != n)
		find(f[n]);
	else return n;
}

void together(int n, int m) {
	f[find(n)] = find(m);
}

int main() {
	int n, m, p, i, x, y;
	cin >> n >> m >> p;
	for (i = 1; i < 10000; i++) {
		f[i] = i;
	}
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		together(x, y);
	}
	for (i = 0; i < p; i++) {
		cin >> x >> y;
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

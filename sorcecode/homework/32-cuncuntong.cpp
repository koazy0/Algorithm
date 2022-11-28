#include<iostream>
#include<cstdio>
using namespace std;

int n, m;
int f[2010];

inline int find(int k) {
	return f[k] == k ? k : f[k] = find(f[k]);
}

void unionn(int x, int y) {
	x = find(x);
	y = find(y);
	f[x] = y;
}

int main() {
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d", &m);
		for (int i = 1; i <= n; i++)
			f[i] = i;
		for (int i = 1; i <= m; i++) {
			register int u, v;
			scanf("%d%d", &u, &v);
			u = find(u);
			v = find(v);
			if (u != v)
				unionn(u, v);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (f[i] == i) //如果自己的父亲是自己，就存在一个集合
				ans++;
		printf("%d\n", ans - 1);
		scanf("%d", &n);
	}
	return 0;
}
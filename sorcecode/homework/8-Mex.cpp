//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define LL long long int
const int N = 200005;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int mex[N];
int a[N];
int nex[N];
LL lazy[N << 2];
LL sum[N << 2];
int maxn[N << 2];

inline LL getmex(int n)
{
	map<int, int> mp;
	map<int, int> f;
	fill(nex, nex + 1 + n, n + 1);
	int m = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		mp[a[i]] = 1;
		while (mp[m]) ++m;
		mex[i] = m;
		ans += m;
		if (f[a[i]])
			nex[f[a[i]]] = i;
		f[a[i]] = i;
	}
	return ans;
}
inline void PushUp(int rt)
{
	maxn[rt] = max(maxn[rt << 1], maxn[rt << 1 | 1]);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
inline void PushDown(int rt, int m)
{
	if (lazy[rt] != -1)
	{
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		maxn[rt << 1] = maxn[rt << 1 | 1] = lazy[rt];
		sum[rt << 1] = lazy[rt] * (m - (m >> 1));
		sum[rt << 1 | 1] = lazy[rt] * (m >> 1);
		lazy[rt] = -1;
	}
}
inline void build(int l, int r, int rt)
{
	lazy[rt] = -1;
	if (l == r)
	{
		maxn[rt] = mex[l];
		sum[rt] = mex[l];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
inline void update(int L, int R, int c, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		lazy[rt] = c;
		sum[rt] = (LL)c*(r - l + 1);
		maxn[rt] = c;
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, c, lson);
	if (m < R) update(L, R, c, rson);
	PushUp(rt);
}
inline LL query(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		return sum[rt];
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (L <= m) ret += query(L, R, lson);
	if (m < R) ret += query(L, R, rson);
	return ret;
}
inline int ask_k(int L, int R, int MAXN, int l, int r, int rt)
{
	if (l == r)
	{
		if (sum[rt] < MAXN) return 0;
		return l;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;

	if (L <= m && MAXN < maxn[rt << 1])
	{
		int k = ask_k(L, R, MAXN, lson);
		if (k)
			return k;
	}
	if (m < R&&MAXN < maxn[rt << 1 | 1])
	{
		int k = ask_k(L, R, MAXN, rson);
		if (k)
			return k;
	}
	return 0;
}
int main()
{
	int n;
	while (scanf("%d", &n))
	{
		if (!n) break;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		LL ans = getmex(n);
		build(1, n, 1);
		for (int i = 1; i < n; i++)
		{
			int p = ask_k(i + 1, nex[i] - 1, a[i], 1, n, 1);
			if (p > 0) update(p, nex[i] - 1, a[i], 1, n, 1);
			ans += query(i + 1, n, 1, n, 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
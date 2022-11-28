//#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
const int Max = 1010;
int t, n, h, r, flag, father[Max];
struct shu { long long x, y, z; };
shu a[Max];
inline int get_int()
{
	int x = 0, f = 1;
	char c;
	for (c = getchar(); (!isdigit(c)) && (c != '-'); c = getchar());
	if (c == '-') { f = -1; c = getchar(); }
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	return x * f;
}
inline bool comp(const shu &a, const shu &b) { return a.z < b.z; }
inline double calc(int i, int j) { return sqrt(double(a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y) + (a[i].z - a[j].z)*(a[i].z - a[j].z)); }
inline int getfather(int v) { return father[v] == v ? v : father[v] = getfather(father[v]); }
int main()
{
	t = get_int();
	while (t--)
	{
		memset(a, 0, sizeof(a));
		n = get_int(), h = get_int(), r = get_int();
		for (int i = 1; i <= n; i++) a[i].x = get_int(), a[i].y = get_int(), a[i].z = get_int();
		sort(a + 1, a + n + 1, comp);
		for (int i = 1; i <= n; i++) father[i] = i;
		if (a[n].z + r<h || a[1].z>r) { cout << "No\n"; continue; }
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (calc(i, j) <= 2 * r)
				{
					int fax = getfather(i), fay = getfather(j);
					if (fax != fay) father[fay] = fax;
				}
		flag = 0;
		for (int i = n; i >= 1; i--)
		{
			if (flag) break;
			if (a[i].z + r < h || flag) break;
			for (int j = 1; j <= n; j++)
			{
				if (a[j].z > r) break;
				if (getfather(j) == getfather(i) && a[j].z + r >= 0) { flag = 1; break; }
			}
		}
		cout << (flag ? "Yes\n" : "No\n");
	}

	return 0;
}
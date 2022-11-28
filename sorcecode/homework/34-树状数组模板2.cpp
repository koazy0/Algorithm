#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 530000
long int t[N << 2], n, op, l, r, type, x, k, a[N];
inline long int lowbit(long int &x) { return x & (-x); }
long int getsum(long int x)
{
	long int sum = 0;
	while (x > 0)
	{
		sum += t[x];
		x -= lowbit(x);
	}
	return sum;
}
void update(long int x, long int dlt)
{
	while (x <= n)
	{
		t[x] += dlt;
		x += lowbit(x);
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	cin >> n >> op;
	for (int i = 1; i <= n; i++)
	{
		scanf("%ld", &a[i]); update(i, a[i] - a[i - 1]);
	}
	while (op--)
	{
		scanf("%d", &type);
		if (type == 2) { scanf("%d", &l); printf("%ld\n", getsum(l)); }
		else
		{
			scanf("%ld%ld%ld", &l, &r, &k);
			update(r + 1, -k);
			//���������ֱ�Ӱ�1���Ҷ˵�r+1�Ĳ������ǰ׺�ͼ�ȥk��1��l�Ĳ��ǰ׺�ͼ���k
			update(l, k);
		}
	}
	return 0;
}

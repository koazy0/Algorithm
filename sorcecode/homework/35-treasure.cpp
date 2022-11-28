#include <bits/stdc++.h>
using namespace std;
const int N = 2500 + 1;
const int K = 5;
unsigned int t1[N][N], t2[N][N], t3[N][N], t4[N][N];
int m, n, k;
int X1, Y1, X2, Y2;
int ak, bk;
unsigned int ans, val;
char op;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int y, unsigned int p)
{
	for (int X = x; X <= n; X += lowbit(X))
		for (int Y = y; Y <= n; Y += lowbit(Y)) {
			t1[X][Y] ^= p;
			t2[X][Y] ^= ((y) & 1) ? p : 0;	//���(y-1)��ż���������κ���Ҳ��ż�����Խ����Ӱ��
			t3[X][Y] ^= ((x) & 1) ? p : 0;
			t4[X][Y] ^= ((x)&(y) & 1) ? p : 0;
		}
}
void range_update(int xa, int ya, int xb, int yb, int p)
{
	update(xa, ya, p);
	update(xa, yb + 1, p);
	update(xb + 1, ya, p);
	update(xb + 1, yb + 1, p);
}
unsigned int query(int x, int y)
{
	unsigned int ans = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			ans ^= (((x + 1)&(y + 1) & 1) ? t1[i][j] : 0) ^
			(((x + 1) & 1) ? t2[i][j] : 0) ^
			(((y + 1) & 1) ? t3[i][j] : 0) ^
			t4[i][j];
	return ans;
}
unsigned int range_query(int xa, int ya, int xb, int yb)
{
	return query(xb, yb) ^ query(xb, ya - 1) ^ query(xa - 1, yb) ^ query(xa - 1, ya - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		cin >> op;
		if (op == 'P')
		{
			val = 0;
			cin >> X1 >> Y1 >> X2 >> Y2 >> k;
			while (k--)
			{
				cin >> ak >> bk;
				if (bk & 1)
					val ^= (1 << ak);//ֻ���������и��µı�Ҫ��ż������Ӱ����
			}
			range_update(X1, Y1, X2, Y2, val);
		}
		if (op == 'Q')
		{
			cin >> X1 >> Y1 >> X2 >> Y2;
			ans = range_query(X1, Y1, X2, Y2);
			for (int i = 1; i <= 30; i++)
			{
				ans = ans >> 1;
				if (ans & 1)
					cout << 2;
				else
					cout << 1;
			}
			cout << endl;
		}
	}
	return 0;
}
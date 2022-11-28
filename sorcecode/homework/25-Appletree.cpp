#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct hhx {
	int to, next;
}a[220];
int n, m, x, y, z, t;
int p[120], b[120][120], f[120][120], head[120];
void dp(int d)
{
	p[d] = 1;
	for (int i = head[d]; i; i = a[i].next)  //���ӽڵ�
	{
		if (p[a[i].to] == 1) continue;  //�������ظ��ߵ����ڵ�
		dp(a[i].to);  //�������ӽڵ���Ϊ���ڵ�
		for (int j = m; j > 0; j--)  //��01�������Ӻ���ǰ��
			for (int k = j - 1; k >= 0; k--)  //ת�۵�
				f[d][j] = max(f[d][j], f[a[i].to][k] + f[d][j - k - 1] + b[d][a[i].to]);  //���´�
	}
}
void add(int x, int y)  //����
{
	a[++t].to = y;
	a[t].next = head[x];
	head[x] = t;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		b[x][y] = b[y][x] = z;	 //����ƻ����
		add(x, y);
		add(y, x);
	}
	dp(1);
	cout << f[1][m];
	return 0;
}

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m, dp[10000][10000];
int a[1000], b[1000];
void tree_DP(int x)
{
	int t1, t2;
	cin >> t1 >> t2;
	t1 *= 2;
	if (t2 > 0)
	{
		for (int i = 1; i <= t2; i++)
		{
			cin >> a[i] >> b[i];
		}
		for (int i = 1; i <= t2; i++)
		{
			for (int j = n; j >= b[i] + t1; j--)
			{
				dp[x][j] = max(dp[x][j], dp[x][j - b[i]] + a[i]);
			}
		}
	}
	if (t2 == 0)
	{
		tree_DP(x * 2);
		tree_DP(x * 2 + 1);
		for (int j = t1; j <= n; j++)
		{
			for (int k = 0; k <= j - t1; k++)
			{
				dp[x][j] = max(dp[x][j], dp[x * 2][j - k - t1] + dp[x * 2 + 1][k]);
			}
		}
		return;
	}
}
int main()
{
	cin >> n;
	n--;
	tree_DP(1);
	cout << dp[1][n];
	return 0;
}
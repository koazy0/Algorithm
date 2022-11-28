#include<cstdio>
#include<algorithm>
using namespace std;

long long int max(long long int maxa,long long int maxb){
	return maxa>maxb?maxa:maxb;
}

int route[1010][1010] = { 0 };
int maxxi1[1010][1010] = { 0 };
int maxgua1[1010][1010] = { 0 };

int maxxi2[1010][1010] = { 0 };
int maxgua2[1010][1010] = { 0 };
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &route[i][j]);
		}
	}

	for (int x = 1; x <= n; x++)//小西自起点至某点（相遇点）的最大路径
	{
		for (int y = 1; y <= m; y++)
			maxxi1[x][y] = route[x][y] + max(maxxi1[x - 1][y], maxxi1[x][y - 1]);
	}

	for (int x = n; x >= 1; x--)//小西自该点至终点的最大路径
	{
		for (int y = m; y >= 1; y--)
			maxxi2[x][y] = route[x][y] + max(maxxi2[x + 1][y], maxxi2[x][y + 1]);

	}

	for (int x = n; x >= 1; x--)//小瓜自起点至该点的最大路径
	{
		for (int y = 1; y <= m; y++)
			maxgua1[x][y] = route[x][y] + max(maxgua1[x + 1][y], maxgua1[x][y - 1]);
	}
	for (int x = 1; x <= n; x++)//小瓜自该点至终点的最大路径
	{
		for (int y = m; y >= 1; y--)
			maxgua2[x][y] = route[x][y] + max(maxgua2[x - 1][y], maxgua2[x][y + 1]);

	}

	long long int ans = 0;
	int num1, num2;

	for (int x = 2; x < n; x++)
	{
		for (int y = 2; y < m; y++)
		{
			num2 = maxxi1[x][y - 1] + maxxi2[x][y + 1] + maxgua2[x - 1][y] + maxgua1[x + 1][y];
			ans = max(ans, num2);
			num1 = maxxi1[x - 1][y] + maxxi2[x + 1][y] + maxgua2[x][y + 1] + maxgua1[x][y - 1];
			ans = max(ans, num1);
		}
	}

	printf("%lld", ans);

}

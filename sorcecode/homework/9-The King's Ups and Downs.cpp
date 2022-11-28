#include<iostream>
#include<cstdio> 
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const int inf = 0x3f3f3f3f;

const int N = 1e5 + 100;

int n;

LL dp[25][25][2];//pos,pre

bool vis[25];

LL ans = 0;

LL dfs(int pos, int pre, bool state)//state:0表示该上升，1表示该下降
{
	if (pos == 0)
		return 1;
	if (dp[pos][pre][state] != -1)
		return dp[pos][pre][state];
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		if (state&&pre > i)
		{
			vis[i] = true;
			ans += dfs(pos - 1, i, !state);
			vis[i] = false;
		}
		else if (!state&&pre < i)
		{
			vis[i] = true;
			ans += dfs(pos - 1, i, !state);
			vis[i] = false;
		}
	}
	return dp[pos][pre][state] = ans;
}

int main()
{
	//  freopen("input.txt","r",stdin)
	int w;
	cin >> w;
	while (w--)
	{
		int num;
		memset(dp, -1, sizeof(dp));
		cin >> num >> n;
		if (n == 1)//1记得要特判
		{
			printf("%d 1\n", num);
			continue;
		}
		memset(vis, false, sizeof(vis));
		cout << num << ' ' << dfs(n, -1, 0) + dfs(n, 25, 1) << endl;
	}
	return 0;
}
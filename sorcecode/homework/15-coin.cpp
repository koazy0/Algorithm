#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

int n;
long long dp[100001][3][3];		//第i个位置种树j,比两边k高或者低
long long int tree[100005][3];//每轮的树

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int PlantTree(int n) {
	long long int ans, tmpsum[3] = { 0,0,0 };

	//三种初始状态
	for (int tmp = 0; tmp < 3; tmp++) {
		switch (tmp)
		{

		case 0://最开始种最矮的树
			dp[2][0][2] = -9999;
			dp[2][1][2] = -9999;
			dp[2][1][1] = tree[2][1] + tree[1][0];
			dp[2][2][1] = tree[2][2] + tree[1][0];
			break;
		case 1:
			dp[2][0][2] = tree[2][0] + tree[1][1];
			dp[2][1][2] = -9999;
			dp[2][1][1] = -9999;
			dp[2][2][1] = tree[2][2] + tree[1][1];
			break;
		case 2://最开始种最高的树
			dp[2][0][2] = tree[2][0] + tree[1][2];
			dp[2][1][2] = tree[2][1] + tree[1][2];
			dp[2][1][1] = -9999;
			dp[2][2][1] = -9999;
			break;
		}
		for (int i = 3; i <= n - 1; i++) {
			dp[i][0][2] = max(dp[i - 1][1][1], dp[i - 1][2][1]) + tree[i][0];
			dp[i][1][1] = dp[i - 1][0][2] + tree[i][1];
			dp[i][1][2] = dp[i - 1][2][1] + tree[i][1];
			dp[i][2][1] = max(dp[i - 1][0][2], dp[i - 1][1][2]) + tree[i][2];
		}
		switch (tmp)
		{
		case 0:
			tmpsum[tmp] = max(max(dp[n - 1][0][2] + tree[n][1], dp[n - 1][0][2] + tree[n][2]), dp[n - 1][1][2] + tree[n][2]);
			break;
		case 1:
			tmpsum[tmp] = max(max(dp[n - 1][1][1] + tree[n][0], dp[n - 1][2][1] + tree[n][0]), max(dp[n - 1][0][2] + tree[n][2], dp[n - 1][1][2] + tree[n][2]));
			break;
		case 2:
			tmpsum[tmp] = max(max(dp[n - 1][2][1] + tree[n][1], dp[n - 1][2][1] + tree[n][0]), dp[n - 1][1][1] + tree[n][0]);
			break;
		}
	}

	return max(tmpsum[0], max(tmpsum[1], tmpsum[2]));
}

int main() {
	long long int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
	}
	if (n < 3) {
		switch (n)
		{
		case 1:
			sum = max(tree[1][0], max(tree[1][1], tree[1][2]));
			break;
		case 2:
			for (int i = 0; i <= 2; i++)
				for (int j = 0; j <= 2; j++)
					if (j != i)sum = max(sum, tree[1][i] + tree[2][j]);
			break;
		}
	}
	else sum = PlantTree(n);
	printf("%lld", sum);

	//对于最后一项n另外结算
	//printf("%lld", method);
	return 0;
}
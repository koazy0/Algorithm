#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

struct good {
	int v;
	int m;
	int c;
};

int v, m, n;
long long int dp[50][400][400];//d[n][m][v]
good goods[50];

int main() {
	cin >> v >> m >> n;

	for (int i = 1; i <= n; i++) {
		cin >> goods[i].v >> goods[i].m >> goods[i].c;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= v; k++) {
				if (j < goods[i].m || k < goods[i].v)
					dp[i][j][k] = dp[i - 1][j][k];
				else dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j- goods[i].m][k- goods[i].v]+goods[i].c);
			}
		}
	}
	printf("%lld", dp[n][m][v]);
	return 0;
}
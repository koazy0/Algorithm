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
	long long int price;
	long long int weight;
};
int n, m;
long long int dp[26][100000];//d[[m][n]
good goods[26];

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> goods[i].price>> goods[i].weight;
		goods[i].weight = goods[i].weight * goods[i].price;
	}
	

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(j>=goods[i].price)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - goods[i].price]+ goods[i].weight );
			else dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%lld", dp[m][n]);
	return 0;
}
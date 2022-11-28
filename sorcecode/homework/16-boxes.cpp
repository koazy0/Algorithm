#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int n,v,vs[31];
int dp[31][20001];//dp[n][v],表示能占用的最大空间

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

int main() {
	cin >> v>> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> vs[i];
	}

	vector<int> vectorV(vs+1, vs+n+1);
	sort(vectorV.begin(), vectorV.begin() + n);
	int tmp;

	for (int i = 1; i <= n; i++) {
		tmp = vectorV[i - 1];
		for (int j = 1; j <= v; j++) {

			if (j >= tmp)
				dp[i][j] = max(dp[i - 1][j - tmp] + tmp, dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << v-dp[n][v];
	return 0;
}
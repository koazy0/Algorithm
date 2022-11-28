#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

int n;
long long int a[2001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	vector<long long int> vec(a + 1, a + n + 1);
	sort(vec.begin(), vec.begin() + n);

	int tmp;

	for (int i = 1; i <= n; i++) {
		
		for (int j = n-1; j >=0; j--) {
			if (a[i] == vec[j]) {
				cout << n - j << " ";
				break;
			}
		}
		
	}

	//cout << v - dp[n][v];
	return 0;
}
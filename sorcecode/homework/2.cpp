#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

//70·Ö´úÂë

using namespace std;

struct Dian
{
	long long int x;
	long long int y;
};

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int n;
static int dp1[10000001], dp2[10000001];
static Dian dian, dians[10000001];


int main() {
	long long int count = 0;
	scanf("%lld", &n);

	if (n <= 1000) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld", &dians[i].x, &dians[i].y);
		}

		for (int i = n; i > 0; i--) {
			for (int j = 1; j < i; j++) {
				if (dians[i].x == dians[j].x || dians[i].y == dians[j].y)
					count++;
			}
		}
	}

	else {
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld", &dians[i].x, &dians[i].y);
			dp1[dians[i].x]++;
			dp2[dians[i].y]++;
		}

		for (int i = 0; i <= 10000001; i++) {
			count += (dp1[i] * (dp1[i] - 1)) / 2 + (dp2[i] * (dp2[i] - 1)) / 2;
		}
	}



	printf("%lld", count);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;


int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

int n, a[5001];
long long int xulie[2][5001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		xulie[0][i] = 1;
	}xulie[1][1] = 1;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j < i; j++) {
			if (a[j] > a[i]) {

				if (xulie[0][j] + 1 > xulie[0][i]) {
					xulie[1][i] = xulie[1][j];
					xulie[0][i] = xulie[0][j] + 1;
				}
				else if (xulie[0][j] + 1 == xulie[0][i]) {
					xulie[1][i] = xulie[1][i] + xulie[1][j];
				}
			}
		}
		if (!xulie[1][i])xulie[1][i] = 1;
		xulie[0][0] = max(xulie[0][0], xulie[0][i]);
	}
	long long int method = 0;
	for (int i = 1; i <= n; i++) {
		if (xulie[0][i] == xulie[0][0])method += xulie[1][i];
	}
	cout << xulie[0][0] << " ";
	printf("%lld", method);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;


int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

int n,maxa;
int a[231];
int xulie[2][231];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > a[0]) {
			a[0] = a[i];
			maxa = i;
		}
	}

	for (int i = i; i <= maxa; i++) {
		int maxn;
		xulie[1][i]=max(xulie[1][i-1],maxn)
	}
	for (int i = n; i >= maxa; i++) {

	}

	//cout << n - MAX << endl;
	return 0;
}
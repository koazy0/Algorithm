#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;


int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

int n;
int a[231];
int xulie[2][231];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		xulie[0][i] = 1;
		xulie[1][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int maxn=1;
		for (int j = 1; j < i; j++) {
			if(a[j]<a[i])
			xulie[0][i] = max(xulie[0][j]+1, maxn);
		}
	}


	for (int i = n; i >= 1; i--) {
		int maxn = 1;
		for (int j = n; j > i; j--) {
			if(a[j]<a[i])
			xulie[1][i] = max(xulie[1][j]+1, maxn);
		}
	}
	for (int i = 1; i <= n; i++) {
		xulie[1][0] = max(xulie[1][0],xulie[1][i] + xulie[0][i]);
	}
	cout << n - xulie[1][0]+1<< endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;


int m[10000000];
long long int stairs[40];

void Born() {
	stairs[0] = 0;
	stairs[1] = 1;
	stairs[2] = 2;
	for (int i = 3; i < 40; i++) {
		stairs[i] = stairs[i - 1] + stairs[i - 2];
	}
}


int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
	}

	Born();
	for (int i = 0; i < n; i++) {
		printf("%lld\n", stairs[m[i]-1]);
	}

	
	return 0;
}
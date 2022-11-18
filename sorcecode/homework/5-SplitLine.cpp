#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

long long int n[10000000];

//逗出来的公式，乌鱼子
int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		scanf("%d", &n[i]);
	}
	
	for (int i = 0; i < c; i++) {
		printf("%lld\n", 2*(n[i]*n[i])-n[i]+1);
	}
	return 0;
}
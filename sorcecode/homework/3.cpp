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

int n, m;

vector<int>row;
int line[100001];
//int row[100001];

int main() {
	long long int count = 0;
	
	int tmp, size = 0;
	cin >> n >> m>>tmp;
	row.push_back(tmp);
	
	for (int i = 1; i < m; i++) {
		cin >> tmp;
		if (row.back() == tmp) row.pop_back();
		else row.push_back(tmp);
	}
	for (int i = 1; i <=n; i++) {
		line[i] = i;
	}

	for (int i = 0; i < row.size(); i++) {
		
		for (int j = 1; j <= n; j++) {
			if (row[i] == line[j])line[j]++;
			else if (row[i] == (line[j]-1))line[j]--;
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (line[i] == j)cout <<i <<" ";
		}
	}
	

	printf("\n%d", row.size());
	return 0;
}
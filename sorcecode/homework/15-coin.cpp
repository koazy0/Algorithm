#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

long long int n,m;
long long int coin[200001];

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

long long int max(long long int num1, long long int num2) {
	return num1 > num2 ? num1 : num2;
}

int main() {
	long long int count1 = 0,tmp,count_coin=0;
	vector<long long int> vec;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.begin() + vec.size() - 1);
	if (vec[0] != 1) cout << "No answer!!!";
	else {

		//for (int i = vec[vec.size() - 1]; i <= m; i++) {
		for (int i = 2; i <= m; i++) {
			int tmp1 = i;
			for (int j = n - 1; j > -1; j--) {
				while (vec[j] <= tmp1) {
					tmp1 -= vec[j];
					count1++;
				}
			}
			count_coin = max(count1, count_coin);
			count1 = 0;
		}
		
		printf("%lld", count_coin);
	}
	//printf("%lld", sum);

	return 0;
}
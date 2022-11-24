#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;


int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

struct Horse
{
	int x;
	int y;
};

Horse b, horses[10];
long long dp[1000][1000];

void inithorse() {
	horses[2] = { horses[1].x+1,horses[1].y+2 };
	horses[3] = { horses[1].x+2,horses[1].y+1 };
	horses[4] = { horses[1].x+2,horses[1].y-1 };
	horses[5] = { horses[1].x+1,horses[1].y-2 };
	horses[6] = { horses[1].x-1,horses[1].y-2 };
	horses[7] = { horses[1].x-2,horses[1].y-1 };
	horses[8] = { horses[1].x-2,horses[1].y+1 };
	horses[9] = { horses[1].x-1,horses[1].y+2 };
	dp[0][1] = 1; dp[1][0] = 1;
	
}

long long int Road(int x,int y) {
	for (int i = 1; i < 10;i++) {
		if (x == horses[i].x&&y == horses[i].y)
			return 0;
	}
	if (x == 0 && y == 0)return 0;
	if (!dp[x][y]) {
		if (x == 0) {
			dp[x][y] = Road(x, y - 1);
		}
		else if (y == 0) {
			dp[x][y] = Road(x - 1, y);
		}
		else {
			dp[x][y] = Road(x - 1, y) + Road(x, y - 1);
		}
			
	}
	return dp[x][y];
}

int main() {
	cin >> b.x >> b.y >> horses[1].x >> horses[1].y;
	inithorse();
	long long int max = Road(b.x, b.y);
	printf("%lld", max);
	
	//printf("%lld", method);
	return 0;
}

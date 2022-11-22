#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

struct Goods
{
	int value;
	int weight;
};

Goods goods[10000];
Goods goods1[6] = { {0,0},{9,4},{10,5},{9,4},{2,3},{24,10} };

//动态规划，维护两个表
//一个是本元素是否使用的Rec表
//另一个是动态规划表,Dynamic[count+1][weight+1]

int max(int a, int b) {

	return a > b ? a : b;
}

int max1(int a, int b) {
	if (a > b) {
		
		
		return a;
	}
	else return b;
	
}

int Dynamic[6][14];
int Rec[6][14];
int Count[6];

void InitRec(int count,int weight) {
	int a, b;
	for (int i = 1; i <= count; i++) {
		for (int j = goods1[i].weight; j <= weight; j++) {
			a = goods1[i].value + Dynamic[i - 1][j - goods1[i].weight];
			b = Dynamic[i - 1][j];
			if (a > b) {
				Dynamic[i][j] = a;
				Rec[i][j] = 1;
			}
			else Dynamic[i][j] = b;
			//填充完规划表
		}
	}
}

int Dynamix(int count,int weight) {
	
	int i = count,j=weight;
	while (i > 0) {
		if (Rec[i][j])	//表示选中了当前物品
		{
			Count[i] = 1;
			j -= goods1[i].weight;
		}
		else {
			Count[i] = 0;
		}
		i--;
	}
	
	return Dynamic[count][weight];
}

//递归暴力求解
int KnapsackSR(int count, int weight) {
	if (weight < 0)return -99999;
	if (count < 1)	return 0;
	return max(KnapsackSR(count - 1, weight-goods1[count].weight)+ goods1[count].value, KnapsackSR(count - 1, weight));
}



int main() {
	InitRec(5, 13);
	
	int max=Dynamix(5, 13);
	max=Dynamix(5, 12);
	max = KnapsackSR(5,12);
	return 0;
}
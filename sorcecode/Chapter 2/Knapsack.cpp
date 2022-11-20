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

int max(int a, int b) {
	
	return a > b ? a : b;
}

int KnapsackSR(int count, int weight) {
	if (weight < 0)return -99999;
	if (count < 1)	return 0;
	return max(KnapsackSR(count - 1, weight-goods1[count].weight)+ goods1[count].value, KnapsackSR(count - 1, weight));
}


int main() {
	int max = KnapsackSR(5,13);
	return 0;
}
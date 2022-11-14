#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int c[15] = { 23,432,15,54,67,34,78,13,76,99,45,12,47,68,2 };
int d[6] = { 12,23,45,14,15,35 };

void Swap(int &c, int &d) {
	int tmp;
	tmp = d;
	d = c;
	c = tmp;
}

int QuickSortSub(int *a, int left, int right) {	
	int i = left ;
	int j = left;
	while (j <= right)			//这里不能保证数据的原序性  8  8*->8*  8
	{
		if (a[j] > a[right]) j++;
		else {
			Swap(a[i++], a[j++]);
		}
	}
	return i - 1;
}

void QuickSort(int *a, int left, int right) {
	
	int mid;				//不是常规意义上的mid
	if (left >= right) {

	}
	else {
		mid=QuickSortSub(a, left, right);
		QuickSort(a, left, mid-1);
		QuickSort(a, mid+1, right);
	}
}

int main() {
	
	QuickSort(c, 0, 14);
	QuickSort(d, 0, 5);
	return 0;
}
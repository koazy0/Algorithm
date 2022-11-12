// algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
int tmp[100000];

using namespace std;

void Merge(int *a, int left, int right) {
	//left right 为该分组的范围
	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	int *ptmp = tmp;


	cout << a << endl;
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			*ptmp++ = a[i++];
		}
		else {
			*ptmp++ = a[j++];
		}
	}

	if (i > mid) {
		while (j <= right) {
			*ptmp++ = a[j++];
		}
	}
	else {
		while (i <= mid) {
			*ptmp++ = a[i++];
		}
	}

	
	//数组长度:right - left + 1
	//数组开始:&a[left]
	for (int i = 0; i < right - left + 1; i++) {
		a[i+left] = tmp[i];						
	}
	//memcpy(&a[left], tmp, right - left + 1);
}


void MergeSort(int *a, int left, int right) {
	int mid = (left + right) / 2;
	if (left >= right)
		;
	else {
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, right);
	}
}

int main()
{
	int a[15] = { 23,432,15,54,67,34,78,13,76,99,45,12,47,68,2 };
	int b[6] = {12,23,45,14,15,35};
	Merge(b, 0, 5);
	MergeSort(a, 0, 14);

    std::cout << "Hello World!\n";
}

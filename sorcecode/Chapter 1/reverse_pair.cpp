#include<iostream>

//#define Enum

#ifdef Enum
#define CountSub CountSub1
#else
#define CountSub CountSub3
#endif // Enum

int a[8] = { 2,4,8,9,5,6,7,8 };

int b[10] = { 5,4,6,6,2,3,1,4,8,10 };
int tmp[100000];
using namespace std;

//枚举
int CountSub1(int *a,int left,int right) {
	int mid = (left + right) / 2,count=0;
	for (int i = left; i <= mid; i++)
		for (int j = mid + 1; j <= right; j++) {
			if (a[i] > a[j]) count++;
		}
	return count;
}


//融合到归并中
int CountSub3(int *a, int left, int right) {
	int mid = (left + right) / 2, count = 0, count_tmp = 0;
	int i = left, j = mid+1;
	int *ptmp = tmp;
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			*ptmp++ = a[i++];
			count += count_tmp;
		}
		else {
			*ptmp++ = a[j++];
			count_tmp++;
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
			count += count_tmp;
		}
	}
	for (int i = left; i <= right;i++) {
		a[i] = tmp[i - left];
	}
	return count;
}

int Count(int *a, int left, int right) {
	int mid = (left + right) / 2;
	if (left >= right)
		return 0;
	else
		return (Count(a, left, mid)+Count(a, mid + 1, right)+CountSub(a, left, right));
}

int main() {
	//int s=Count(a, 0, 7);
	int t=Count(b, 0, 9);
	return 0;
}
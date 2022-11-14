#include<iostream>

using namespace std;

int knumber;
int tmp;
int b[10] = { 2,4,8,6,3,1,9,5,7,0 };

void Swap(int &a, int &b) {
	tmp = a;
	a = b;
	b = tmp;
}

int KstNumberSub(int *a, int left, int right) {
	int i = left, j = left;
	if (left >= right) return (right+left)/2;
	while (j <= right) {
		if (a[j] > a[right])j++;
		else {
			Swap(a[i++], a[j++]);
		}
	}
	return i - 1;
}

void KstNumber(int *a,int left,int right,int k) {
	
	int mid = KstNumberSub(a, left, right);
	if (mid == k) knumber = a[mid];
	else if (mid > k) KstNumber(a, left, mid - 1, k);
	else  KstNumber(a, mid+1, right, k);
}

int main() {
	int k = 8;

	KstNumber(b, 0, 9, k-1);
	return 0;
}
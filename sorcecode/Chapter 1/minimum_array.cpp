#include<iostream>

using namespace std;

int a[10] = { -1,-3,3,5,-4,3,2,-2,3,6 };
int b[8] = { 3,5,-6,5,6,-7,5,4 };

//暴力枚举法
void EnumerSort(int *a,int n, _Out_ int &l, _Out_ int &r) {
	int Smax=0, S_tmp;
	
	for (int left = 0; left < n; left++) {
		S_tmp = 0;
		for (int right = left; right < n; right++) {
			S_tmp += a[right];
			if (S_tmp > Smax) {
				Smax = S_tmp;
				l = left;
				r = right;
			}
			else if (S_tmp == Smax) {
				if((r-l)>(right-left))			//假设这里要取最短的优先,
				{								//且已满足编号靠前的优先
					l = left;
					r = right;
				}
				
			}
		}
	}
}

void divide_mid(int *a, int L, int R, _Out_ int &l, _Out_ int &r) {
	int mid = (L + R) / 2, mid1 = mid + 1;
	int Sleftmax=-10000,Srightmax= -10000,Sleft=0, Sright=0;
	for (int i = mid; i >=L; i--) {
		Sleft += a[i];
		if (Sleft > Sleftmax) {
			Sleftmax = Sleft;
			l = i;
		}
	}

	for (int i = mid1; i <=R; i++) {
		Sright += a[i];
		if (Sright > Srightmax) {
			Srightmax = Sright;
			r = i;
		}
	}
	
}

void divide_conquer(int *a,_In_ int L,_In_ int R, _Out_ int &l, _Out_ int &r) {
	int mid = (L + R) / 2,l2,l3,r2,r3;
	int s1=0, s2=0, s3=0;
	if (L < R) {
		
		divide_conquer(a, L, mid, l, r);
		divide_conquer(a, mid + 1, R, l2, r2);
		divide_mid(a, L, R, l3, r3);
		for (int i = l; i <= r; i++) {
			s1 += a[i];
		}
		for (int i = l2; i <= r2; i++) {
			s2 += a[i];
		}
		for (int i = l3; i <= r3; i++) {
			s3 += a[i];
		}
		if (s1 < s2) {
			s1 = s2;
			l = l2;
			r = r2;
		}

		if (s1 < s3) {
			s1 = s3;
			l = l3;
			r = r3;
		}
		
	}
	
	else {
		l = L;
		r = R;
	}//递归终止条件，表示只有一个元素
}


int main() {
	int l=0, r=10;
	EnumerSort(a, 10, l, r);
	//divide_conquer(a, 0, 9, l, r);
	divide_conquer(b, 0, 7, l, r);
 	return 0;
}
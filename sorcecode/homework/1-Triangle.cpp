#include<stdio.h>
#include<iostream>

using namespace std;
int a[1000][1000];
int st[1000][1000];

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

//遍历的暴力枚举法
//i 三角形大小，x,y位下标
//score:10
int Path_Enum(int i,int  *b,int x, int y) {
	if (i != 1)return b[x*1000+y] + max(Path_Enum(i - 1, b, x + 1, y), Path_Enum(i - 1, b, x + 1, y + 1));
		
	else return b[1000*x+y];

}

//状态转移方程，新建数据长度数组
//来保存从父节点到这一点的形式长度
//score:100
int Path_ST(int  *b,int r) {
	int tmp=0;
	if (r == 1) {
		return b[0];
	}
	for (int i = 1; i < r; i++) {
		for (int j = 0; j <= i; j++) {
			
			if (j == 0) st[i][j] = b[i * 1000 + j] + st[i-1][j];
			else if (j == i)	st[i][j] = b[i * 1000 + j] + st[i - 1][j-1];
			else st[i][j] = max(b[i*1000+j]+ st[i-1][j-1], b[i * 1000 + j] + st[i - 1][j]);
		}
	}
	for (int i = 0; i < r;i++) {
		if (st[r - 1][i] > tmp) tmp = st[r - 1][i];
	}

	return tmp;
}
int main() {
	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	st[0][0] = a[0][0];
	//int sum = Path_Enum(r, (int *)a, 0, 0);
	int sum = Path_ST((int *)a,r);
	cout << sum << endl;

	return 0;
}
#include<stdio.h>
#include<iostream>

using namespace std;
int a[1000][1000];
int st[1000][1000];

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

//�����ı���ö�ٷ�
//i �����δ�С��x,yλ�±�
//score:10
int Path_Enum(int i,int  *b,int x, int y) {
	if (i != 1)return b[x*1000+y] + max(Path_Enum(i - 1, b, x + 1, y), Path_Enum(i - 1, b, x + 1, y + 1));
		
	else return b[1000*x+y];

}

//״̬ת�Ʒ��̣��½����ݳ�������
//������Ӹ��ڵ㵽��һ�����ʽ����
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
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}
int n, a[110], f[110][2], MAX;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int mx = 0;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				mx = max(mx, f[j][1]);//�����������е����ֵ��Ҳ���ǵ�һ���ֿ������µ��������
			}
		}
		f[i][1] = mx + 1;
	}
	for (int i = n; i >= 1; i--)
	{
		int mx = 0;
		for (int j = n; j > i; j--)
		{
			if (a[j] < a[i])
			{
				mx = max(mx, f[j][2]);
			}
		}
		f[i][2] = mx + 1;
		MAX = max(MAX, f[i][1] + f[i][2] - 1);//f[i][1]+f[i][2]-1��ʾ��a[i]��ߵ�ʱ���µ������������һ����Ϊ�������½��ĸ�������������ߵ㣬���Լ�ȥһ��
	}
	cout << n - MAX << endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

struct Path
{
	int m;	//start
	int n;	//end
};


long long  int p[51];
Path path[1000000];



//经典的遍历枚举
//score:80
long long int Path_Enum(int m,int n){
	if (n - m <= 1) return 1;
	else {
		if (p[n - 2 - m] == 0) {
			p[n - 2 - m] = Path_Enum(m, n - 2);
		}
		if (p[n - 1 - m] == 0) {
			p[n - 1 - m] = Path_Enum(m, n - 1);
		}
		return p[n - 1 - m] + p[n - 2 - m];
	}
	
}


//直接生成数组

void Born(long long int *p) {
	p[0] = 1;
	p[1] = 1;
	p[2] = 2;
	for (int i = 3; i < 51; i++) {
		p[i] = p[i - 2] + p[i - 1];
	}
}

int main() {

	int r;
	//printf("%lld\n", Path_Enum(1, 55));
	p[0] = 1;
	p[1] = 1;
	p[2] = 2;
	scanf("%d",&r);
	Born(p);
	for(int i=0;i<r;i++)
	scanf("%d %d", &path[i].m,&path[i].n);
	

	for (int i = 0; i < r; i++) {
		printf("%lld\n", Path_Enum(path[i].m,path[i].n));
	}
	
	return 0;
}
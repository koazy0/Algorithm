#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000
#define MAXM 100000

int father[MAXN + 5];//��¼���ڵ�ʵ�ֲ��鼯
int sum = 0;//�ۼ��������ı����� �����ж��Ƿ��ܹ���
struct node {
	int a, b, n;
}s[MAXM + 5];//�洢ÿ�ߵ���Ϣ

int find(int x) {//��������
	if (father[x] != x) {
		father[x] = find(father[x]);//·��ѹ��
	}
	return father[x];//�Խ����ڵ���Ϊ�˸��ڵ㣬ֱ�ӷ���
}
int op(int x, int y, int n) {//�жϴ˱��Ƿ���Լ���������
	int a = find(x), b = find(y);//�ȷֱ�������ڵ�����Ƚڵ�
	if (a != b) {//������Ȳ�һ��
		sum++;//��¼�����������һ����
		father[a] = b;//�������������鼯
		return n;//���ش˱�ʱ��
	}
	else {//���������������ṹ�ɻ�
		return -1;//����-1����ʾ���ܼ���
	}
}

bool cmp(node a, node b) {//�������ձߵĽ���ʱ���������
 //ʱ��̵���ǰ��
	if (a.n > b.n) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int n, m;
	int ans;

	//��������
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].n);
	}

	//��ʼ�����鼯��ߵ�˳��
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	sort(s + 1, s + 1 + m, cmp);

	//���β����
	for (int i = 1; i <= m && sum <= n - 1; i++) {
		int x = op(s[i].a, s[i].b, s[i].n);
		if (x != -1) {
			ans = x;
		}
	}

	//�ж��Ƿ��������������ڵ�֮�䶼�ܵ���
	if (sum < n - 1) {
		printf("-1");
		return 0;
	}
	else {
		printf("%d", ans);
		return 0;
	}
}
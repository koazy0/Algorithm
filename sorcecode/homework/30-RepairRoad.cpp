#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000
#define MAXM 100000

int father[MAXN + 5];//记录父节点实现并查集
int sum = 0;//累加生成树的边数， 用来判断是否能构成
struct node {
	int a, b, n;
}s[MAXM + 5];//存储每边的信息

int find(int x) {//查找祖先
	if (father[x] != x) {
		father[x] = find(father[x]);//路径压缩
	}
	return father[x];//以将父节点置为了根节点，直接返回
}
int op(int x, int y, int n) {//判断此边是否可以加入生成树
	int a = find(x), b = find(y);//先分别查找两节点的祖先节点
	if (a != b) {//如果祖先不一样
		sum++;//记录生成树里多了一条边
		father[a] = b;//并连接两个并查集
		return n;//返回此边时间
	}
	else {//如果加入生成树后会构成环
		return -1;//返回-1，表示不能加入
	}
}

bool cmp(node a, node b) {//用来按照边的建好时间来排序边
 //时间短的排前面
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

	//输入数据
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].n);
	}

	//初始化并查集与边的顺序
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	sort(s + 1, s + 1 + m, cmp);

	//依次插入边
	for (int i = 1; i <= m && sum <= n - 1; i++) {
		int x = op(s[i].a, s[i].b, s[i].n);
		if (x != -1) {
			ans = x;
		}
	}

	//判断是否满足任意两个节点之间都能到达
	if (sum < n - 1) {
		printf("-1");
		return 0;
	}
	else {
		printf("%d", ans);
		return 0;
	}
}
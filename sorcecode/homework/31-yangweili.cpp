#include<bits/stdc++.h>
using namespace std;
int fa[30001], front[30001], num[30001], x, y, i, j, n, T, ans;    //fa[i]��ʾ�ɴ�i������
//front[i]��ʾ�ɴ�i���������ж�ͷ�ľ���
										//num[i]��ʾ��i�еķɴ����� 
char ins;
int find(int n) {                                        //�������ȵĺ��� 
	if (fa[n] == n)return fa[n];
	int fn = find(fa[n]);                                    //�ȵݹ��ҵ����� 
	front[n] += front[fa[n]];    //�ڻ��ݵ�ʱ�����front����Ϊ����ʱҪ�õ���ȷ��front[����]��
									//����ֻ���ڻ��ݵ�ʱ����£� 
	return fa[n] = fn;
}
int main() {
	cin >> T;
	for (i = 1; i <= 30000; ++i) {                                //����ֵ 
		fa[i] = i;
		front[i] = 0;
		num[i] = 1;
	}
	while (T--) {
		cin >> ins >> x >> y;
		int fx = find(x);                                    //fxΪx�����еĶ�ͷ 
		int fy = find(y);                                    //fyͬ�� 
		if (ins == 'M') {
			front[fx] += num[fy];        //����front[x�����ж�ͷ(������y���ڶ��к���)]
//������y���ڶ��еĳ��� 
			fa[fx] = fy;                                    //��fy��Ϊfx������ 
			num[fy] += num[fx];                            //������fyΪ��ͷ���еĳ��� 
			num[fx] = 0;                        //��fxΪ��ͷ�Ķ����Ѳ����ڣ����� 
		}
		if (ins == 'C') {
			if (fx != fy)cout << "-1" << endl;            //��x��y�����Ȳ���ͬ������ͬһ�� 
			else cout << abs(front[x] - front[y]) - 1 << endl;    //��������x��y���ͷ�ľ�����
			//�����ǵľ��� 
		}
	}
	return 0;
}
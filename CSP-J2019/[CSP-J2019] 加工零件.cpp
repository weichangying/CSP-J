/*************************************
* ��Ŀ��[CSP-J2019] �ӹ����
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com

* ˼·��
	��Ҫ 1 ��Ϊ a �������� L ���׶��ṩԭ���� <==> �Ƿ���� 1 �� a �ĳ���Ϊ L ��·�� 
	������� 1 �� a �ĳ���Ϊ L ��·������ L + 2, L + 4, L + 8...Ҳ�� 1 �� a ��·��(L + 2���ص���һ�����ֻ���)
	���� L ��·�� ==> �Ƿ���� <= L�����Һ� L ��ż����ͬ��·�� 
	���ԣ��ֱ��� 1->a ����Ϊ���������·��1->a ����Ϊż�������· 
	���Խ��в����������⣺a�桢aż 
	���ߵĹ����У�ż --> �棬�� --> ż 
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, q;
int odd[N], even[N];  // �������·��ż�����· 
int head[N], to[M], nex[M], idx;

void add(int u, int v) {  // ����һ�� u->v �ı� 
	to[++idx] = v;
	nex[idx] = head[u];
	head[u] = idx;
}

void BFS(int s) {
	memset(odd , 0x7f, sizeof  odd);  // ��ʼ��Ϊ����� 
	memset(even, 0x7f, sizeof even);  // ��ʼ��Ϊ�����
	queue<int> q;
	q.push(s);  // ������ 
	even[1] = 0;  // �� 1 ��ż�����·�� 0��ע�ⲻҪ���ǳ�ʼ���� 
	while(!q.empty()) {
		int u = q.front();  // ���� 
		q.pop();  // ���׳��� 
		for(int i = head[u]; i; i = nex[i]) {  // u �����ڵ� 
			int v = to[i];
			if(odd[u] + 1 < even[v]) {  // �� u ���������� 1 ��ż��  
				even[v] = odd[u] + 1;
				q.push(v);
			}
			if(even[u] + 1 < odd[v]) {  // �� u ��ż������ 1 ������
				odd[v] = even[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	
	cin >> n >> m >> q;
	while(m--) {
		int u, v;  // u -- v
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	BFS(1);
	while(q--) {
		int a, L;  // ���Ϊ a �Ĺ��ˣ��� L �׶ε����
		cin >> a >> L;
		// L ��ż����1 �� a ��ż��·���Ҳ����� L
		// L ��������1 �� a ������·���Ҳ����� L
		if(L % 2 == 1 && odd[a] <= L || L % 2 == 0 && even[a] <= L) {
			cout << "Yes\n";
		}else {
			cout << "No\n";
		}
	}

	return 0;
}

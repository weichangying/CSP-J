/*************************************
* ��Ŀ��[CSP-J2019] ��������
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct ticket {  // �Ż�Ʊ 
	int tim;  // ��ʼ�˳�ʱ�� 
	int price;  // �۸�
	bool used = false;  // �Ƿ�ʹ�ù�����ʼ��Ϊ false (ûʹ��) 
} t[N];

int main() {
	
	int n;
	cin >> n;
	int cnt = 0;  // �Ż�Ʊ������ 
	int cost = 0;  // �ܻ��� 
	int idx = 0;  // ����ģ�û�й��ڵ��Ż�Ʊ���±� 
	for(int i = 0; i < n; i++) {
		int way, price, tim;  // �˳�����(0 ������1 ����)���۸񣬿�ʼ�˳�ʱ�� 
		cin >> way;
		if(way == 0) {  // �������˳������Ż�Ʊ 
			cin >> t[cnt].price >> t[cnt].tim;
			cost += t[cnt++].price;  // �˵�����Ǯ 
		}else if(way == 1) {  // �������������Ż�Ʊ�����������Լ���Ǯ 
			cin >> price >> tim;
			bool ok = false;  // ���Ż�Ʊ�ı�־ 
			while(tim - t[idx].tim > 45) idx++;  // �������ڵ��Ż�Ʊ�������Ż�ʱ��Ĺؼ�
			for(int j = idx; j < cnt; j++) {
				if(!t[j].used && price <= t[j].price) {  // û���ù� && �۸�û�г����Ż�Ʊ 
					t[j].used = true;  // ����ù� 
					ok = true;  // ��������Ż�Ʊ 
					break;  // �����Ż�Ʊ���˳� 
				}
			} 
			if(!ok) cost += price;  // �������Ż�Ʊ���Լ���Ǯ������ 
		}
	}
	cout << cost; 

	return 0;
}

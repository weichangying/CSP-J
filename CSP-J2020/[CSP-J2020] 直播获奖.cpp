// [CSP-J2020] ֱ����
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

const int N = 610;
int cnt[N];  // ÿ���������ֵĴ��� 

int main() {

	int n, w;  // �������񽱰ٷְ� w% 
	cin >> n >> w;
	for(int i = 1; i <= n; i++) {
		int score;  // �� i ���˵ķ��� 
		cin >> score;
		cnt[score]++;  // �÷������ִ����� 1 
		int p = max(1, i * w / 100);  // ������ 
		int num = 0;  // Ŀǰ�Ļ����� 
		for(int j = 600; j >= 0; j--) {  // �Ӹߵ���ö��ÿ������ 
			if(cnt[j]) {
				num += cnt[j];  // Ŀǰ�Ļ����� 
				if(num >= p) {  // �������㹻 
					cout << j << " ";  // ������ 
					break;
				}
			}
		}
	}
	
	return 0;
}

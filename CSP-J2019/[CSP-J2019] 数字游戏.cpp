/*************************************
* ��Ŀ��[CSP-J2019] ������Ϸ
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int ans = 0;  // ע��Ҫ��ʼ��Ϊ 0 
	char c;
	for(int i = 0; i < 8; i++) {
		cin >> c;
		if(c == '1') ans++;  // ע�����ַ� 1������������ 1 
	}
	cout << ans;

	return 0;
}

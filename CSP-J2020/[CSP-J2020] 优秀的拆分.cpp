// [CSP-J2020] ����Ĳ��
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve(int n) {  // �ֽ�ɶ����� 
	int e = 0;
	while(n) {
		if(n & 1) ans.push_back(1 << e);  // 2^e  
		n >>= 1;
		e++;
	}
}

int main() {
	
	int n;
	cin >> n;
	if(n & 1) cout << "-1";  // ������û������Ĳ��
	else {
		solve(n);  // �ֽ�ɶ����� 
		for(int i = ans.size() - 1; i >= 0; i--) {  // ������� 
			cout << ans[i] << " ";
		}
	} 

	return 0;
}

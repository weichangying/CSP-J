#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
LL a[N][N];
LL d[N];  // ÿһ�У��� --> ��
LL u[N];  // ÿһ�У��� --> ��
LL dp[N][N];  // dp[i][j] �� (i, j) ����֮�͵����ֵ

int main(){

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[1][0] = 0;  // ��֤�����Ͻǿ�ʼ 
	for(int j = 1; j <= m; j++) {  // �����ң�һ��һ����
		// ���ڵ� (i, j)�����������max(����������������������������)
		for(int i = 1; i <= n; i++) {  // �� --> ��
			d[i] = u[i] = dp[i][j-1] + a[i][j];
		}
		for(int i = 2; i <= n; i++) {  // �� --> ��
			d[i] = max(d[i], d[i-1] + a[i][j]);
		}
		for(int i = n-1; i >= 1; i--) {  // �� --> ��
			u[i] = max(u[i], u[i+1] + a[i][j]);
		}
		for(int i = 1; i <= n; i++) {  // max(����������������������������)
			dp[i][j] = max(u[i], d[i]);
		}
	}
	cout << dp[n][m];

	return 0;
}

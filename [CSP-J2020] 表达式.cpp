// [CSP-J2020] ���ʽ 
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int w[N];  // �������ĳ�ʼֵ 
char op[N];  // �洢���������±귶Χ��n+1~n+m 
stack<int> st;  // �洢��׺���ʽ���������� 
int head[N], to[N], nex[N], idx;
bool change[N];

void add(int u, int v) {
	to[++idx] = v;
	nex[idx] = head[u];
	head[u] = idx;
}

int dfs1(int u) {  // ��ԭ�� 
	if(!op[u]) return w[u];  // Ҷ�ӽ��(������)
	if(op[u] == '!') w[u] = !dfs1(to[head[u]]);  // �Ժ���ȡ��  
	else {
		int a = to[head[u]], b = to[nex[head[u]]];  // �����ӽ�� 
		if(op[u] == '&') w[u] = dfs1(a) & dfs1(b);
		if(op[u] == '|') w[u] = dfs1(a) | dfs1(b);
	}
	return w[u];
}

void dfs2(int u) {
	change[u] = true;
	if(!op[u]) return;  // Ҷ�ӽ��(������) 
	if(op[u] == '!') dfs2(to[head[u]]);  // ! ���㣬�ı亢�Ӽ��ɸı�� 
	else {
		int a = to[head[u]], b = to[nex[head[u]]];  // �����ӽ�� 
		if(op[u] == '&') {  // & ���㣬����һ���� 1����һ����Ӱ��� 
			if(w[a]) dfs2(b);
			if(w[b]) dfs2(a);
		}
		if(op[u] == '|') {  // | ���㣬����һ���� 0����һ����Ӱ���
			if(!w[a]) dfs2(b);
			if(!w[b]) dfs2(a);
		}
	} 
}

int main() {

	string s;
	getline(cin, s);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	// ����׺���ʽ��������������� 1~n������������� n+1~n+m
	int m = n; 
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') continue;
		else if(s[i] == 'x') {
			int x = 0, j = i + 1;
			while(j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
			st.push(x);  // ��������ջ 
			i = j;  // �����ո� 
		}else if(s[i] == '!') {
			op[++m] = s[i];  // �洢������
			add(m, st.top());  // m �� st.top() �ĸ����
			st.pop();
			st.push(m);  // �����������ջ 
		}else {  // & �� | 
			op[++m] = s[i];
			add(m, st.top());  // m �� st.top() �ĸ����
			st.pop();
			add(m, st.top());  // m �� st.top() �ĸ����
			st.pop();
			st.push(m);  // �����������ջ
		}
	}
	
	int ans = dfs1(m);  // ��ԭ��
	dfs2(m);  // ÿ�������ı�᲻������𰸸ı� 
	
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(change[x]) cout << (!ans) << endl;  // x ȡ�����ô𰸸ı�
		else cout << ans << endl;
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define i64 long long
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

const int N = 1e5 + 5, P = 998244353, inf = 0x3f3f3f3f;
string s[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	getline(cin, s[0]);

	cout << "int M1[30][30] =\n";
	for (re int t = 0; t < n; ++t)
	{
		getline(cin, s[t]);
		cout << "{";
		for (re int i = 0; i < m; ++i)
		{
			char x = s[t][i];
			if (x == ' ' || x == 'X' || x == '*') cout << '0';
			else if (x == '#') cout << '1';
			else if (x == 'O' || x == '0') cout << '2';
			if (i != m - 1) cout << ", ";
		}
		cout << "},\n";
	}
	
	cout << "int M2[30][30] =\n";
	for (re int t = 0; t < n; ++t)
	{
		cout << "{";
		for (re int i = 0; i < m; ++i)
		{
			char x = s[t][i];
			if (x == ' ' || x == '#' || x == 'O') cout << '0';
			else if (x == 'X' || x == '0') cout << '1';
			else if (x == '*') cout << '2';
			if (i != m - 1) cout << ", ";
		}
		cout << "},\n";
	}

	return 0;
}
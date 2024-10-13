#include <bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define i64 long long
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

const int N = 1e5 + 5, P = 998244353, inf = 0x3f3f3f3f;

double st[N];
int tp;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	for (auto x : s)
	{
		if (isdigit(x)) st[++tp] = x - '0';
		else if (x == '+') st[tp - 1] += st[tp], --tp;
		else if (x == '-') st[tp - 1] -= st[tp], --tp;
		else if (x == '*') st[tp - 1] *= st[tp], --tp;
		else if (x == '/') st[tp - 1] /= st[tp], --tp;
	}
	cout << st[tp] << '\n';

	return 0;
}
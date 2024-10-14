#include <bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define i64 long long
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

const int N = 1e5 + 5, P = 998244353, inf = 0x3f3f3f3f;

mt19937 rd(chrono::system_clock().now().time_since_epoch().count());

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("1.in", "w", stdout);
	int T = 500000;
	const int W = 1e2;
	cout << T << '\n';
	while (T--)
	{
		cout << rd() % 3 + 1 << ' ' << rd() % W + 1 << '\n';
	}

	return 0;
}
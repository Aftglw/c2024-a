// #include <bits/stdc++.h>
// using namespace std;

// #define re register
// #define Re register
// #define i64 long long
// #define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

// const int N = 1e3 + 5, P = 998244353, inf = 0x3f3f3f3f;

// mt19937 rd(chrono::system_clock().now().time_since_epoch().count());

// bool vis[N][N];

// signed main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	freopen("1.in", "w", stdout);
//     int n = 25;
// 	for (re int i = 1; i <= n; ++i)
// 	{
// 		int x = rd() % 15 + 1, y = rd() % 15 + 1;
// 		while (vis[x][y])
// 			x = rd() % 15 + 1, y = rd() % 15 + 1;
// 		vis[x][y] = 1;
// 		cout << x << ' ' << y << '\n';
// 	}
// 	for (re int i = 1; i <= n; ++i)
// 	{
// 		int x = rd() % 15 + 1, y = rd() % 15 + 1;
// 		while (vis[x][y])
// 			x = rd() % 15 + 1, y = rd() % 15 + 1;
// 		vis[x][y] = 1;
// 		cout << x << ' ' << y << '\n';
// 	}


// 	return 0;
// }

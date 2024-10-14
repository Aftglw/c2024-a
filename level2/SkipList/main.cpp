#include <bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define i64 long long
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

const int N = 1e5 + 5, P = 998244353, inf = 0x3f3f3f3f;

struct node
{
	int val, num;
	node *nex, *down;
}*rt[33], *null;
unordered_map<int, int> lv;
const int lg = 10;

mt19937 rd(chrono::system_clock().now().time_since_epoch().count());
inline int Random_level()
{
	return __builtin_ctz(rd());
}

inline node *New(int val)
{
	return new node {val, 1, null, null};
}

inline void Insert(int val)
{
	if (lv.find(val) == lv.end()) lv.emplace(val, Random_level());
	int d = lv.at(val), nowd = lg;
	node *p = rt[lg], *q = null;
	while (1)
	{
		if (p -> val == val)
		{
			++p -> num;
			if (!nowd) break;
			p = p -> down, --nowd;
			continue;
		}
		if (p -> nex == null || p -> nex -> val > val)
		{
			if (d >= nowd)
			{
				if (q != null) q -> down = New(val), q = q -> down;
				else q = New(val);
				q -> nex = p -> nex;
				p -> nex = q;
			}
			if (nowd) p = p -> down, --nowd;
			else break;
		}
		else p = p -> nex;
	}
}

inline bool Delete(int val)
{
	if (lv.find(val) == lv.end()) return false;
	int d = lv.at(val), nowd = lg;
	node *p = rt[lg], *q = null;
	while (1)
	{
		if (p -> nex == null || p -> nex -> val > val)
		{
			if (!nowd) return false;
			p = p -> down, --nowd;
			continue;
		}
		if (p -> nex -> val == val)
		{
			if (!--p -> nex -> num) p -> nex = p -> nex -> nex;
			if (!nowd) break;
			p = p -> down, --nowd;
		}	
		else p = p -> nex;
	}
	return true;
}

inline int Count(int val)
{
	if (lv.find(val) == lv.end()) return 0;
	int d = lv.at(val), nowd = lg;
	node *p = rt[lg], *q = null;
	while (1)
	{
		if (p -> val == val) return p -> num;
		if (p -> nex == null || p -> nex -> val > val)
		{
			if (!nowd) return 0;
			p = p -> down, --nowd;
			continue;
		}	
		else p = p -> nex;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	File("1");
	clock_t ST = clock();
	null = new node {0, 0, 0, 0};
	null -> nex = null -> down = null;

	for (re int i = 0; i <= lg; ++i)
		rt[i] = new node {0, 0, null, null};
	for (re int i = 1; i <= lg; ++i)
		rt[i] -> down = rt[i - 1];


	int T; cin >> T;
	while (T--)
	{
		int op, x; cin >> op >> x;
		if (op == 1) Insert(x);
		else if (op == 2) cout << (Delete(x) ? "Succeed" : "Fail") << '\n';
		else if (op == 3) cout << Count(x) << '\n';
	}

	clock_t ED = clock();
	cerr << "Time: " << (double)(ED - ST) << ' ' << "ms" << '\n';

	return 0;
}
/*
1. 插入一个元素
2. 删除一个元素（返回是否删除成功）
3. 查询一个元素的数量
*/
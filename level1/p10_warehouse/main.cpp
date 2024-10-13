#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define re register
#define Re register

using namespace std;

unordered_map<string, int> mp;

inline void pt()
{
	system("cls");
	puts("   菜单   ");
	puts("1. 查看库存");
	puts("2. 入库");
	puts("3. 出库");
	puts("4. 退出程序");	
}

inline void Print()
{
	system("cls");
	int cnt = 0;
	for (auto x : mp)
		cout << ++cnt << ". " << x.first << ' ' << x.second << '\n';
	system("pause");
}

inline void Insert()
{
	system("cls");
	puts("输入货物的型号和数量");
	string s; cin >> s;
	int a; cin >> a;
	mp[s] += a;
	system("cls");
	cout << "货物" << ' ' << s << ' ' << "已入库" << ' ' << a << ' ' << "件\n";
	cout << "当前库存" << ' ' << mp[s] << ' ' << "件\n";
	system("pause");
}

inline void Delete()
{
	system("cls");
	puts("输入货物的型号和数量");
	string s; cin >> s;
	int a; cin >> a;
	if (a <= 0) puts("数量必须为正整数");
	else if (mp.find(s) == mp.end()) cout << "出库失败！货物" << ' ' << s << ' ' << "无库存\n";
	else if (mp[s] < a) cout << "出库失败！货物" << ' ' << s << ' ' << "仅剩" << ' ' << mp[s] << ' ' << "件\n";
	else
	{
		mp[s] -= a;
		if (!mp[s]) mp.erase(mp.find(s));
		system("cls");
		cout << "货物" << ' ' << s << ' ' << "已出库" << ' ' << a << ' ' << "件\n";
		cout << "当前库存" << ' ' << mp[s] << ' ' << "件\n";
	}
	system("pause");
}

signed main()
{
    freopen("log.txt", "r", stdin);
	int n; cin >> n;
	for (Re int i = 1; i <= n; ++i)
	{
		string name; int num;
		cin >> name >> num;
		mp.emplace(name, num);
	}
	freopen("CON","r",stdin);

	pt();
	while (1)
	{
		if (_kbhit())
        {
            int ch = _getch();
			if (ch == '4') break;
			if (ch == '1') Print();
			else if (ch == '2') Insert();
			else if (ch == '3') Delete();
			pt();
        }
	}

	freopen("log.txt", "w", stdout);
	cout << mp.size() << '\n';
	for (auto x : mp) cout << x.first << ' ' << x.second << '\n';

    return 0;
}
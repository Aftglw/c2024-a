/*
编译命令：
g++ main.cpp level1.cpp level2.cpp level3.cpp level4.cpp level5.cpp level_final.cpp -o main
*/
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "push_boxed.h"

#define re register
#define Re register

using namespace std;

//mp1: fixed element; mp2 mobile element;

/*
mp1:
0 空地 ( ,*,X)
1 墙 (#)
2 位置 (O,*,0)

mp2:
0 无单位
1 箱子
2 人
*/

int mp1[30][30], mp2[30][30], n, m;
int stx, sty, score, box;

inline void pt()
{
	system("cls");
	for (re int i = 0; i < n; ++i, putchar('\n')) 
		for (re int j = 0; j < m; ++j)
		{
			if (mp1[i][j] == 1) putchar('#');
			else if (mp2[i][j] == 2) putchar('*');
			else if (mp1[i][j] == 0) putchar(mp2[i][j] ? 'X' : ' ');
			else putchar(mp2[i][j] ? '0' : 'O');
		}
	cout << "Penalty: " << score << '\n';
	score += 100;
}

inline bool move(int x, int y, const int dx, const int dy)
{
	int u = x + dx, v = y + dy;
	if (mp1[u][v] == 1) return false;
	if (mp2[x][y] == 2)
	{
		if (mp2[u][v] == 1 && !move(u, v, dx, dy)) return false;
		swap(mp2[u][v], mp2[x][y]);
		return true;
	}
	if (mp2[u][v]) return false;
	if (mp1[u][v] == 2) --box;
	if (mp1[x][y] == 2) ++box;
	swap(mp2[u][v], mp2[x][y]);
	return true;	
}

signed main()
{
	puts("Choose the level: (1 ~ 5, 6)");
	int lv; cin >> lv;

	if (lv == 1) init1();
	else if (lv == 2) init2();
	else if (lv == 3) init3();
	else if (lv == 4) init4();
	else if (lv == 5) init5();
	else if (lv == 6) init_final();
	else return puts("Error input!"), 0;
	
	pt();

	int x = stx, y = sty;
    while (1)
	{
		if (_kbhit())
        {
            int ch = _getch();
			if (ch == 27) return 0;
			int dx, dy;
            if (ch == 'w') dx = -1, dy = 0;
			else if (ch == 'a') dx = 0, dy = -1;
			else if (ch == 's') dx = 1, dy = 0;
			else if (ch == 'd') dx = 0, dy = 1;
			else continue;

			if (move(x, y, dx, dy)) x += dx, y += dy;

			pt();
			if (!box) break;
        }
	}

	puts("You Win!");
    system("pause");
    return 0;
}
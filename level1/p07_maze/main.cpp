#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define re register
#define Re register

using namespace std;

char mp[12][30] =
    {
        "###########################",
        "@....#.#.#..........###...#",
        "#.##.#.#...########.###.#.#",
        "####.#.#.###.....##.#...###",
        "#....#...#######.##.###.###",
        "#.######.##.........###.###",
        "#.#......##.###########.###",
        "#.#.#######...............#",
        "#...#.#...####.##########.#",
        "#.###.###.###########.###.#",
        "#.......................#$#",
        "###########################",
    };

#define pt for (re int i = 0; i < 12; ++i) puts(mp[i])

signed main()
{
	pt;

	int x = 1, y = 0, u, v;
    while (1)
	{
		if (_kbhit())
        {
            int ch = _getch();
            if (ch == 'w') u = x - 1, v = y;
			else if (ch == 'a') u = x, v = y - 1;
			else if (ch == 's') u = x + 1, v = y;
			else if (ch == 'd') u = x, v = y + 1;
			else continue;
			if (mp[u][v] == '#') continue;
			if (mp[u][v] == '$') goto END;
			swap(mp[u][v], mp[x][y]);
			swap(x, u), swap(v, y);

			system("cls");
			pt;
        }
	}
	END:;

	system("cls");
	puts("You Win!");

    system("pause");
    return 0;
}
#include <bits/stdc++.h>
#include <windows.h>

#define re register
#define Re register

using namespace std;

signed main()
{
    system("mode con cols = 10 lines = 1");
    char ch = '#';
    int x = 0, d = 1;
    while (1)
    {
        for (re int i = 1; i <= x; ++i) cout << ' ';
        cout << ch;
        x += d;
        if (x == 10 || !x) d = -d;
        Sleep(50);
        system("cls");
    }
    return 0;
}
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define re register
#define Re register

using namespace std;

signed main()
{
    int ch;
    while (1)
    {
        if (_kbhit())
        {
            ch = _getch();
            cout << ch;
            if (ch == 27){ break; }
        }
    }
    system("pause");
    return 0;
}
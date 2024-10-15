#include <stdio.h>
#include <windows.h>

#define re register

signed main()
{
    system("mode con cols = 10 lines = 1");
	char ch = '#';
	int i = 0, d = 1;
	while (1)
	{
		for (re int j = 1; j <= i; ++j) putchar(' ');
		putchar(ch);
		i += d;
		if (d == -1 && !i) d = -d;
		else if (d == 1 && i == 9) d = -d;
		Sleep(20);
		system("cls");
	}

	return 0;
}
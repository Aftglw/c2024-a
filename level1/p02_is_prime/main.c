#include <stdio.h>

#define re register

signed main()
{
	int n; scanf("%d", &n);
	for (re int i = 2; 1ll * i * i <= n; ++i) {
		if (n % i == 0) return puts("NO"), 0;
	}
	puts("YES");

	return 0;
}
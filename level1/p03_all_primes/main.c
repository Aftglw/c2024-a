#include <stdio.h>

#define re register

int pri[1002], num;
_Bool vis[1002];

signed main()
{
	printf("%d", num);
	for (re int i = 2; i <= 1000; ++i) {
		if (!vis[i]) pri[++num] = i;
		for (re int j = 1; j <= num && 1ll * pri[j] * i <= 1000; ++j) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	for (re int i = 1; i <= num; ++i) {
		printf("%d ", pri[i]);
	}

	return 0;
}
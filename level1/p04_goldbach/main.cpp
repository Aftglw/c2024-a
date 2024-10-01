#include <bits/stdc++.h>

#define re register
#define Re register

using namespace std;

const int N = 102;
int pri[N], num;
bool vis[N];

signed main()
{
    for (re int i = 2; i <= 100; ++i)
    {
        if (!vis[i]) pri[++num] = i;
        for (re int j = 1; j <= num && pri[j] * i <= 100; ++j)
        {
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }

    for (re int i = 1; i <= num; ++i)
        for (re int j = i; j <= num; ++j)
            vis[pri[i] + pri[j]] = 0;

    for (re int i = 4; i <= 100; i += 2) assert(!vis[i]);

    return 0;
}
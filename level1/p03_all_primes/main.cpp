#include <bits/stdc++.h>

#define re register
#define Re register

using namespace std;

const int N = 1e3 + 3;
int pri[N], num;
bool vis[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    clock_t begin = clock();

    for (re int i = 2; i <= 1000; ++i)
    {
        if (!vis[i]) pri[++num] = i, cout << i << ' ';
        for (re int j = 1; j <= num && pri[j] * i <= 1000; ++j)
        {
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }

    clock_t end = clock();
    cout << '\n' << end - begin << "ms" << endl;

    return 0;
}
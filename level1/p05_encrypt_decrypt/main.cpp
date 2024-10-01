#include <bits/stdc++.h>

#define re register
#define Re register

using namespace std;
mt19937 rd(chrono::system_clock::now().time_since_epoch().count());
short A[1000000];

inline void encrypt(char *a)
{
    int n = strlen(a);
    for (re int i = 0; i < n; ++i)
        A[i] = rd() % 128, a[i] = a[i] ^ A[i];
}

inline void decrypt(char *a)
{
    int n = strlen(a);
    for (re int i = 0; i < n; ++i)
        a[i] = a[i] ^ A[i];
}

char s[1000000];

signed main()
{
    cin >> s;
    encrypt(s);
    cout << s << '\n';
    decrypt(s);
    cout << s << '\n';

    return 0;
}
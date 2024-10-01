#include <bits/stdc++.h>

#define re register
#define Re register
#define i64 long long

using namespace std;

inline i64 mul(const i64 &x, const i64 &y, const i64 &P) {return (x * y - (i64)((long double) x / P * y) * P + P) % P;}
inline i64 ksm(i64 a, i64 b, const i64 &P)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a, P);
        a = mul(a, a, P);
        b >>= 1;
    }
    return res % P;
}
inline bool test(int a, i64 P)
{
    if (ksm(a, P - 1, P) != 1) return 0;
    re i64 now = P - 1;
    while (!(now & 1))
    {
        now >>= 1;
        i64 b = ksm(a, now, P);
        if (b == P - 1) return 1;
        if (b != 1) return 0;
    }
    return 1;
}
mt19937 rd(chrono::system_clock::now().time_since_epoch().count());
inline bool Miller_Rabin(i64 x)
{
    if (x == 1) return 0;
    if (x == 2) return 1;
    for (re int i = 1; i <= 5; ++i)
    {
        i64 a = rd() % (x - 2) + 2;
        if (x == a) return 1;
        if (!test(a, x)) return 0;
    }
    return 1;
}

signed main()
{
    int n; cin >> n;

    // for (re int i = 2; 1ll * i * i <= n; ++i)
    //     if (n % i == 0) return cout << "YES\n", 0;
    // cout << "NO\n";

    cout << (Miller_Rabin(n) ? "YES\n" : "NO\n");


    return 0;
}
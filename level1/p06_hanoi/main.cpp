#include <bits/stdc++.h>

#define re register
#define Re register

using namespace std;

#define M(A, B) (void)printf("%c -> %c\n", (A), (B));

inline void move(char A, char B, char C, int d) // Move the top d layers of A to B when C is empty.
{
    if (d == 1) return M(A, B);
    move(A, C, B, d - 1);
    move(A, B, C, 1);
    move(C, B, A, d - 1);
}

signed main()
{
    move('A', 'B', 'C', 4);

    return 0;
}
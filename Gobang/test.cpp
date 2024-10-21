// #include "ai.h"
// #include <iostream>
// #include <ctime>

// signed main()
// {
//     freopen("1.in", "r", stdin);

//     Init();


//     vector<chess> chesses;

//     int n = 25;
//     for (int i = 1; i <= n; ++i) {
//         int x, y;
//         cin >> x >> y;
//         chesses.emplace_back(chess{x, y, 0});
//     }
//     for (int i = 1; i <= n; ++i) {
//         int x, y;
//         cin >> x >> y;
//         chesses.emplace_back(chess{x, y, 1});
//     }

//     clock_t sum = 0;
//     for (int T = 1; T <= 3; ++T) {
//         clock_t t = clock();
//         for (int i = 1; i <= 10000; ++i) Board_Evaluate(chesses);
//         sum += clock() - t;
//     }

//     cout << 1. * sum / 3 << "ms\n";


//     return 0;
// }
// /*
// g++ rand.cpp -o rand && rand
// g++ test.cpp ai.cpp -o test && test
// */

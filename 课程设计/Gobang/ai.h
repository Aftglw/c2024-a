#include <vector>
#include <string>

#define ui64 unsigned long long
#define uint unsigned

using namespace std;

const int inf = 0x3f3f3f3f, N = 16;

struct chess {
    int x, y;
    bool color; // 0 -> AI, black; 1 -> Player, white
};

struct step {
    chess x;
    int score;

    inline bool operator < (const step &rhs) const {
        return score < rhs.score;
    }
};

// alpha-beta 剪枝优化 min-max 搜索
step dfs(vector<chess> &chesses, bool color, int alpha, int beta, int dep, int maxdep);

// 对整体局面估价
int Board_Evaluate(vector<chess> &chesses);

// 对一个棋子估价（正整数）
uint Chess_Evaluate(int x, int y);

// 对一个棋子的一个方向估价（正整数）（0 <= dir < 4）
uint Chess_Evaluate(int x, int y, int dir);

// 哈希初始化
void Hash_Init();

// AC 自动机初始化
void ACDFA_Init();

uint String_Match(string s);

// 获取当前局面的哈希值
ui64 Get_Hash(vector<chess> &chesses);

// 获取下一步可能的走法（按估值降序(AI)或升序(Player)）
vector<chess> Get_Next_Steps(vector<chess> &chesses, bool color);

/*--------Private--------*/

// AI 搜索下一步
inline step Get_Next_Step(vector<chess> &chesses, int maxdep)
{
    return dfs(chesses, 0, -inf, inf, 0, maxdep);
}

// 全局初始化
inline void Init()
{
    Hash_Init();
    ACDFA_Init();
}

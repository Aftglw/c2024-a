#include <bits/stdc++.h>
#include "ai.h"

ui64 Hash[2][N][N];
mt19937_64 rd(chrono::system_clock::now().time_since_epoch().count());
unordered_map<ui64, int> f;

// 右 右上 上 左上 左 左下 下 右下
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int mp[N][N];
// extern long long Times;

#define in(x, y) (1 <= x && x <= 15 && 1 <= y && y <= 15)

string str[] = {"11111", "011110", "011100", "001110", "011010", "010110", "11110", "01111", "11011", "10111", "11101", "001100", "001010", "010100", "000100", "001000"};
uint value[] = {50000, 4320, 720, 720, 720, 720, 720, 720, 720, 720, 720, 120, 120, 120, 20, 20};

struct ACDFA
{
    int ch[50][3], num, fail[50];
    bool vis[50];
    uint val[50];
    inline void Insert(string &s, uint v)
    {
        int n = s.size(), p = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            if (!ch[p][x]) ch[p][x] = ++num;
            p = ch[p][x];
        }
        val[p] += v;
    }

    inline void built()
    {
        queue<int> q;
        for (int i = 0; i < 3; ++i)
            if (ch[0][i]) q.emplace(ch[0][i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 3; ++i)
                if (ch[u][i]) q.emplace(ch[u][i]), fail[ch[u][i]]= ch[fail[u]][i];
                else ch[u][i] = ch[fail[u]][i];
        }
    }

    inline ui64 Match(string &s)
    {
        memset(vis, 0, sizeof vis);
        int n = s.size(), p = 0;
        ui64 res = 0;
        for (int i = 0; i < n; ++i) {
            p = ch[p][s[i] - '0'];
            for (int u = p; u && !vis[u]; u = fail[u])
                res += val[u], vis[u] = 1;
        }
        return res;
    }
}AC;

void ACDFA_Init()
{
    for (int i = 0; i < 16; ++i) {
        AC.Insert(str[i], value[i]);
    }
    AC.built();
}

void Hash_Init()
{
    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            Hash[0][i][j] = rd(), Hash[1][i][j] = rd();
        }
    }
}

ui64 Get_Hash(vector<chess> &chesses)
{
    ui64 res = 0;
    for (auto x : chesses) {
        res ^= Hash[x.color][x.x][x.y];
    }
    return res;
}

step dfs(vector<chess> &chesses, bool color, int alpha, int beta, int dep, int maxdep)
{
    if (dep == maxdep)
        return step{chesses[chesses.size() - maxdep], Board_Evaluate(chesses)};

    vector<chess> vec = Get_Next_Steps(chesses, color);

    step mx, mn;
    mx.score = -inf, mn.score = inf;

    int cnt = 0;
    for (auto x : vec) {
        if (maxdep > 4 && ++cnt > 10) break;

        chesses.emplace_back(x);
        step res = dfs(chesses, !color, alpha, beta, dep + 1, maxdep);
        chesses.pop_back();

        if (dep & 1) {
            mn = min(mn, res);
            beta = min(beta, mn.score);
        }
        else {
            mx = max(mx, res);
            alpha = max(alpha, mx.score);
        }

        if (alpha >= beta) break;
    }

    return dep & 1 ? mn : mx;
}

int Board_Evaluate(vector<chess> &chesses)
{
    ui64 hs = Get_Hash(chesses);

    if (f.find(hs) != f.end()) {
        return f.at(hs);
    }

    memset(mp, 0, sizeof mp);

    for (auto x : chesses) {
        if (!x.color) mp[x.x][x.y] = 1;
        else mp[x.x][x.y] = 2;
    }

    chess last = chesses.back();
    chesses.pop_back();
    ui64 phs = Get_Hash(chesses);
    int res = 0;

    if (f.find(phs) != f.end()) {
        res = f.at(phs);
        if (!last.color) res += Chess_Evaluate(last.x, last.y);
        else res -= Chess_Evaluate(last.x, last.y);

        for (int i = 0; i < 8; ++i) {
            for (int d = 1; d < 8; ++d) {
                int u = last.x + d * dx[i], v = last.y + d * dy[i];

                if (!in(u, v)) break;
                if (!mp[u][v]) continue;

                if (mp[u][v] == 1) res += Chess_Evaluate(u, v, i % 4);
                else res -= Chess_Evaluate(u, v, i % 4);
            }
        }

        mp[last.x][last.y] = 0;
        for (int i = 0; i < 8; ++i) {
            for (int d = 1; d < 8; ++d) {
                int u = last.x + d * dx[i], v = last.y + d * dy[i];

                if (!in(u, v)) break;
                if (!mp[u][v]) continue;

                if (mp[u][v] == 1) res -= Chess_Evaluate(u, v, i % 4);
                else res += Chess_Evaluate(u, v, i % 4);
            }
        }

        chesses.emplace_back(last);
    }
    else {
        chesses.emplace_back(last);
        for (auto x : chesses) {
            if (!x.color) res += Chess_Evaluate(x.x, x.y);
            else res -= Chess_Evaluate(x.x, x.y);
        }
    }

    f.emplace(hs, res);
    return res;
}

uint String_Match(string s)
{
    uint res = 0;
    for (int i = 0; i < 16; ++i) {
        if (s.find(str[i]) != s.npos) {
            res += value[i];
        }
    }

    return res;
}

uint Chess_Evaluate(int x, int y, int dir)
{
    deque<int> dq;
    dq.emplace_back(1);

    for (int i = 1; i <= 3; ++i) {
        int u = x + dx[dir] * i;
        int v = y + dy[dir] * i;
        if (!in(u, v)) {
            dq.emplace_back(2);
            break;
        }
        if (!mp[u][v]) dq.emplace_back(0);
        else if (mp[u][v] != mp[x][y]) {
            dq.emplace_back(2);
            break;
        }
        else dq.emplace_back(1);
    }

    dir += 4;

    for (int i = 1; i <= 3; ++i) {
        int u = x + dx[dir] * i;
        int v = y + dy[dir] * i;
        if (!in(u, v)) {
            dq.emplace_back(2);
            break;
        }
        if (!mp[u][v]) dq.emplace_back(0);
        else if (mp[u][v] != mp[x][y]) {
            dq.emplace_back(2);
            break;
        }
        else dq.emplace_back(1);
    }

    string s;
    for (auto x : dq) {
        s.push_back(x + '0');
    }

    // return String_Match(s);
    return AC.Match(s);
}

uint Chess_Evaluate(int x, int y)
{
    uint res = 0;

    for (int i = 0; i < 4; ++i) {
        res += Chess_Evaluate(x, y, i);
    }

    return res;
}

vector<chess> Get_Next_Steps(vector<chess> &chesses, bool color)
{
    set<pair<int, int> > now;
    vector<pair<int, pair<int, int> > > res;

    for (chess x : chesses) {
        now.emplace(x.x, x.y);
    }

    for (chess ch : chesses) {
        int x = ch.x, y = ch.y;

        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i], v = y + dy[i];

            if (!in(u, v)) continue;
            if (now.find({u, v}) != now.end()) continue;

            chesses.emplace_back(chess{u, v, color});
            now.emplace(u, v);
            res.emplace_back(Board_Evaluate(chesses), make_pair(u, v));

            chesses.pop_back();
        }
    }

    sort(res.begin(), res.end());
    if (!color) {
        reverse(res.begin(), res.end());
    }

    vector<chess> ans;
    for (auto x : res) {
        ans.emplace_back(chess{x.second.first, x.second.second, color});
    }

    return ans;
}

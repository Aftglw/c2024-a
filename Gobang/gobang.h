#ifndef GOBANG_H
#define GOBANG_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

#include <stdio.h>
// #include "ai.h"
extern long long Times;

class Gobang : public QMainWindow
{
    Q_OBJECT

    int mp[15][15]; // 1: AI black; -1: Player White
    int X, Y, LX, LY;
    int Diff;

protected:

    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *evnet);

public:
    Gobang(QWidget *parent = nullptr);
    ~Gobang();

    void Draw(int x, int y, int color);

    inline void END(int color)
    {
        QMessageBox msgBox;

        // if (color == 1) msgBox.setText("You Lose!");
        // else msgBox.setText("You Win!");

        char str[100];
        if (color == 1) sprintf(str, "You Lose!");
        else sprintf(str, "You Win!");
        msgBox.setText(str);

        msgBox.exec();
    }

    inline bool Lcheck(int x, int y)
    {
        if (x < 4) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x - i][y] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool Rcheck(int x, int y)
    {
        if (x > 10) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x + i][y] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool Ucheck(int x, int y)
    {
        if (y < 4) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x][y - i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool Dcheck(int x, int y)
    {
        if (y > 10) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x][y + i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool LUcheck(int x, int y)
    {
        if (x < 4 || y < 4) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x - i][y - i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool RDcheck(int x, int y)
    {
        if (x > 10 || y > 10) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x + i][y + i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool RUcheck(int x, int y)
    {
        if (x > 10 || y < 4) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x + i][y - i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    inline bool LDcheck(int x, int y)
    {
        if (x < 4 || y > 10) return 0;
        for (int i = 0; i < 5; ++i) {
            if (mp[x - i][y + i] != mp[x][y]) {
                return 0;
            }
        }
        END(mp[x][y]);
        return 1;
    }
    void Check()
    {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                if (mp[i][j] == 0) continue;

                if (Lcheck(i, j) || Rcheck(i, j)) exit(0);
                if (Ucheck(i, j) || Dcheck(i, j)) exit(0);
                if (LUcheck(i, j) || RDcheck(i, j)) exit(0);
                if (LDcheck(i, j) || RUcheck(i, j)) exit(0);
            }
        }
    }
};
#endif // GOBANG_H

#include "gobang.h"
#include "ai.h"

vector<chess> chesses;

Gobang::~Gobang()
{
	
}

Gobang::Gobang(QWidget *parent) : QMainWindow(parent)
{
    this -> resize(600, 600);
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            mp[i][j] = 0;
        }
    }
    this -> setMouseTracking(true);
    Diff = 4; // 设置难度

    LX = LY = 7;
    Draw(7, 7, 1);
    Init();
}

void Gobang::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen(Qt::black);
    QBrush brush(QColor(235, 207, 104));

    p.setRenderHint(QPainter::Antialiasing);

    // 画背景
    p.setBrush(brush);
    p.drawRect(rect());

    // 画棋盘
    pen.setWidthF(1.25);
    p.setPen(pen);
    for (int i = 20; i <= 600; i += 40) {
        p.drawLine(QPoint(i, 20), QPoint(i, 580));
        p.drawLine(QPoint(20, i), QPoint(580, i));
    }
    pen.setWidthF(5);
    p.setPen(pen);
    p.drawPoint(QPoint(140, 140));
    p.drawPoint(QPoint(460, 460));
    p.drawPoint(QPoint(140, 460));
    p.drawPoint(QPoint(460, 140));
    p.drawPoint(QPoint(300, 300));

    // 画棋子
    pen.setColor(Qt::black);
    pen.setWidthF(0.5);
    p.setPen(pen);

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (!mp[i][j]) continue;
            if (mp[i][j] == 1) brush.setColor(Qt::black);
            else brush.setColor(Qt::white);

            p.setBrush(brush);
            p.drawEllipse(2 + i * 40, 2 + j * 40, 36, 36);

            if (i == LX && j == LY) {
                brush.setColor(Qt::red);
                p.setBrush(brush);
                p.drawEllipse(17 + LX * 40, 17 + LY * 40, 6, 6);
            }
        }
    }

    // 画预览棋子
    pen.setColor(QColor(0, 0, 0, 0));
    pen.setWidthF(0.5);
    p.setPen(pen);
    brush.setColor(QColor(255, 255, 255, 200));
    p.setBrush(brush);
    p.drawEllipse(2 + X * 40, 2 + Y * 40, 36, 36);
}

void Gobang::Draw(int x, int y, int color)
{
    mp[x][y] = color;
    chesses.emplace_back(chess{x + 1, y + 1, color == -1});
    repaint();
    Check();
}

void Gobang::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pt = event -> pos();
    X = pt.x() / 40, Y = pt.y() / 40;
    repaint();
}

void Gobang::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pt = event -> pos();
    int x = pt.x() / 40, y = pt.y() / 40;
    if (mp[x][y]) return;
    Draw(x, y, -1);

    step S = Get_Next_Step(chesses, Diff);
    Draw(LX = S.x.x - 1, LY = S.x.y - 1, 1);
}

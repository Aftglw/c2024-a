#include "gobang.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#pragma GCC optimize(3,"Ofast","inline")

long long Times;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Gobang_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Gobang w;
    w.show();

    return a.exec();
}

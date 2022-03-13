#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);  // 注册二进制资源文件
    MainScene w;
    w.show();

    return a.exec();
}

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>

#include "map.h"


class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);

    // 场景的初始化操作：场景长宽设置
    void initScene();

    // 启动游戏
    void playGame();

    // 更新所有游戏中元素的坐标
    void updatePosition();

    // 绘制到屏幕中
    void paintEvent(QPaintEvent *);

public:
    // 无限循环的timer：刷新游戏的间隔
    QTimer m_Timer;

    // 地图对象
    Map m_map;

    ~MainScene();

};

#endif // MAINSCENE_H

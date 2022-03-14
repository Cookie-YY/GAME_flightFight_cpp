#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>

#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "enemyboss.h"


class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);

    // 场景的初始化操作：场景长宽设置
    void initScene();

    // 启动游戏
    void playGame();

    // 更新所有游戏界面
    void refresh();

    // 绘制到屏幕中：系统函数
    void paintEvent(QPaintEvent *);

    // 跟踪鼠标移动：系统函数
    void mouseMoveEvent(QMouseEvent *);

    // 碰撞检测
    void collisionDetection();

public:
    // 无限循环的timer：刷新游戏的间隔
    QTimer m_Timer;

    // 地图对象
    Map m_map;

    // 飞机对象
    HeroPlane m_plane;

    // 敌人管理员
    EnemyBoss m_enemyBoss;

//    // 主场景测试子弹
//    Bullet m_tmp_bullet;

    ~MainScene();

};

#endif // MAINSCENE_H

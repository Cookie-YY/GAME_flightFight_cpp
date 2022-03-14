#include <QIcon>
#include <QPainter>
#include <QMouseEvent>

#include "mainscene.h"
#include "config.h"


/*
 *  主场景：刷新地图，控制飞机
*/

/* MainScene: 构造函数
 *   1. 初始化屏幕
 *   2. 开始游戏
*/
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    this->initScene();
    this->playGame();
}

/* initScene: 初始化屏幕
 *   1. 设置大小，绑定刷新事件
*/
void MainScene::initScene()
{
    // 大小
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    // 图标
    setWindowIcon(QIcon(GAME_ICON));
    // 标题
    setWindowTitle(GAME_TITLE);
    // 刷新
    m_Timer.setInterval(GAME_REFRESH_RATE);
    connect(&m_Timer, &QTimer::timeout, [=](){
        refresh(); // 里面包含了所有对象的 upDatePosition 方法（更新坐标）
        update();         // 相当于手动调用了 paintEvent 方法（画图）
        collisionDetection(); // 碰撞检测
    });
}

/* playGame: 开始游戏
 *   1. 启动定时器（无限循环，控制刷新屏幕）
*/
void MainScene::playGame()
{
    // 启动定时器
    m_Timer.start();
}

/* refresh: 刷新，所有变量的更新操作（主要是更新游戏中元素的坐标）
 *   1. 更新地图坐标
 *   2. 发射子弹：初始化子弹的坐标 + 找到一颗闲置的子弹，设置为非闲置
 *   3. 找到所有非闲置状态的子弹，更新坐标
*/
void MainScene::refresh()
{
    // 1. 更新地图坐标
    m_map.refreshPosition();

    // 2. 测试子弹
//    m_tmp_bullet.m_free = false;
//    m_tmp_bullet.refreshPosition();

    // 2. 发射子弹：初始化子弹的坐标
    m_plane.shoot();
    // 3. 更新flying状态的子弹坐标：
    for (Bullet* b : m_plane.getAllFlyingBullets())
    {
        b->refreshPosition();
    }

    // 4. 分发敌机
    m_enemyBoss.dispatchEnemy();
    // 5. 更新flying状态的敌机坐标：
    for (EnemyPlane* e : m_enemyBoss.getAllFlyingEnemys())
    {
        e->refreshPosition();
    }

}

/* paintEvent: 绘制背景
 *   1. 绘制地图：地图的Qpixmap对象已经加载好了，绘制即可
 *   2. 绘制飞机：飞机同理
*/
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  // 找一个画家 QPainter对象

    // 绘制地图
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);  // 画map1
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);  // 画map2

    // 绘制飞机
    painter.drawPixmap(m_plane.m_plane_X, m_plane.m_plane_Y, m_plane.m_plane);

//    // 测试子弹
//    painter.drawPixmap(m_tmp_bullet.m_bullet_X, m_tmp_bullet.m_bullet_Y, m_tmp_bullet.m_bullet);

    // 绘制flying状态的子弹
    for (Bullet* b : m_plane.getAllFlyingBullets())
    {
        painter.drawPixmap(b->m_bullet_X, b->m_bullet_Y, b->m_bullet);
    }
    // 绘制flying状态的敌机
    for (EnemyPlane* e : m_enemyBoss.getAllFlyingEnemys())
    {
        painter.drawPixmap(e->m_enemy_X, e->m_enemy_Y, e->m_enemy);
    }
}

/* mouseMoveEvent: 监听鼠标移动事件
 *   1. 当鼠标移动时更新飞机坐标
*/
void MainScene::mouseMoveEvent(QMouseEvent * event)
{
    int x = event->x() - m_plane.m_rect.width() / 2;
    int y = event->y() - m_plane.m_rect.height() / 2;
    m_plane.updatePosition(x, y); // 根据鼠标的移动，更新飞机的位置

}

void MainScene::collisionDetection()
{
    for (EnemyPlane * ep : m_enemyBoss.getAllFlyingEnemys())
    {
        for (Bullet * b : m_plane.getAllFlyingBullets())
        {
            if (ep->m_rect.intersects(b->m_rect))
            {
                ep->m_isFlying = false;
                b->m_isFlying = false;
            }
        }
    }
}


MainScene::~MainScene()
{

}

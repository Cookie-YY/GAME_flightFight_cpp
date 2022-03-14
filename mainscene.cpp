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
        refreshPosition(); // 里面包含了所有对象的 upDatePosition方法
        update();         // 相当于手动调用了 paintEvent 方法
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

/* playGame: 开始游戏
 *   1. 启动定时器（无限循环，控制刷新屏幕）
*/
void MainScene::refreshPosition()
{
    // 1. 更新地图坐标
    m_map.refreshPosition();

    // 2. 测试子弹
    m_tmp_bullet.m_free = false;
    m_tmp_bullet.refreshPosition();
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
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);  // 画map1

    // 绘制飞机
    painter.drawPixmap(m_plane.m_plane_X, m_plane.m_plane_Y, m_plane.m_plane);

    // 测试子弹
    painter.drawPixmap(m_tmp_bullet.m_bullet_X, m_tmp_bullet.m_bullet_Y, m_tmp_bullet.m_bullet);


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

MainScene::~MainScene()
{

}

#include <QIcon>
#include <QPainter>

#include "mainscene.h"
#include "config.h"

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    this->initScene();
    this->playGame();
}

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
        updatePosition(); // 里面包含了所有对象的 upDatePosition方法
        update();         // 相当于手动调用了 paintEvent 方法
    });
}

void MainScene::playGame()
{
    // 启动定时器
    m_Timer.start();
}

void MainScene::updatePosition()
{
    // 1. 更新地图坐标
    m_map.updatePosition();

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  // 找一个画家 QPainter对象
    painter.drawPixmap(0,m_map.m_map1_posY, m_map.m_map1);  // 画map1
    painter.drawPixmap(0,m_map.m_map2_posY, m_map.m_map2);  // 画map1

}

MainScene::~MainScene()
{

}

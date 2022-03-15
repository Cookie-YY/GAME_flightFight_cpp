#ifndef HEROPLANE_H
#define HEROPLANE_H

#include <QPixmap>
#include <QRect>

#include <vector>

#include "bullet.h"
#include "config.h"

class HeroPlane
{
public:
    HeroPlane();

    // 发射子弹：初始化子弹位置
    void shoot();

    // 更新飞机坐标值
    void updatePosition(int x, int y);

    // 找到所有飞行状态的子弹
    std::vector<Bullet*> getAllFlyingBullets();

    // 找到一颗不是飞行状态的子弹
    Bullet* getNotFlyingBullet();

public:
    // 飞机图片对象
    QPixmap m_plane;

    // 飞机坐标
    int m_plane_X;
    int m_plane_Y;

    // 飞机矩形边框：边缘的碰撞检测
    QRect m_rect;

    // 弹匣
    Bullet m_bullets[BULLET_NUM];

    // 子弹的间隔记录：发射子弹时需要满足间隔（m_bullet_interval++后与目标值比较）
    int m_bullet_interval = 0;

};

#endif // HEROPLANE_H

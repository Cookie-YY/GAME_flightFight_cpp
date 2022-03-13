#ifndef HEROPLANE_H
#define HEROPLANE_H

#include <QPixmap>
#include <QRect>


class HeroPlane
{
public:
    HeroPlane();

    // 发射子弹
    void shoot();

    // 更新飞机坐标值
    void updatePosition(int x, int y);

public:
    // 飞机图片对象
    QPixmap m_plane;

    // 飞机坐标
    int m_plane_X;
    int m_plane_Y;

    // 飞机矩形边框：边缘的碰撞检测
    QRect m_rect;

};

#endif // HEROPLANE_H

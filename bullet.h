#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QRect>


class Bullet
{
public:
    Bullet();

    // 更新子弹坐标值
    void refreshPosition();

public:
    // 子弹图片对象
    QPixmap m_bullet;

    // 子弹坐标
    int m_bullet_X;
    int m_bullet_Y;

    // 子弹矩形边框：边缘的碰撞检测
    QRect m_rect;

    // 子弹移动速度
    int m_speed;

    // 子弹是否闲置：闲置为true的子弹不会更新坐标（避免重复的创建和删除对象）
    bool m_free;
};

#endif // BULLET_H

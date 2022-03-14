#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>

class EnemyPlane
{
public:
    EnemyPlane();

    // 更新子弹坐标值
    void refreshPosition();

public:
    // 敌机图片对象
    QPixmap m_enemy;

    // 敌机坐标
    int m_enemy_X;
    int m_enemy_Y;

    // 敌机矩形边框：边缘的碰撞检测
    QRect m_rect;

    // 子弹移动速度
    int m_speed;

    // 敌机是否飞～：为false敌机不会更新坐标（避免重复的创建和删除对象）
    bool m_isFlying;
};

#endif // ENEMYPLANE_H

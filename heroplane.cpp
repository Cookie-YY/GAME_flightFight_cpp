#include <QDebug>

#include "heroplane.h"
#include "config.h"

/*
 *  主角飞机的封装，移动和攻击 + 子弹管理（找到一发可用的子弹 / 找到所有飞行的子弹）
*/


/* HeroPlane: 构造函数
 *   1. 加载图片
 *   2. 初始化位置坐标
 *   3. 初始化边缘检测框
 *      * 之后使用这个框的长和宽指代飞机的长和宽
 *      * 之后使用这个框进行碰撞检测
*/
HeroPlane::HeroPlane()
{
    // 初始化飞机图片
    m_plane.load(HERO_PATH);
    // 初始化位置
    m_plane_X = (GAME_WIDTH-m_plane.width()) / 2;  // 初始化x位置是屏幕的一半-自己的一半
    m_plane_Y = GAME_HEIGHT-m_plane.height();      // 初始化y位置是最底下
    // 初始化边缘框
    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(m_plane_X, m_plane_Y);  // 移动到图片的起始位置

}

/* shoot: 发射：子弹出场
 *   1. 间隔++后进行判断
 *   2. 符合要求后重置间隔
 *   3. 找到可用的子弹后，置成飞行状态并初始化其x和y坐标
*/
void HeroPlane::shoot()
{
    // 不到间隔不发射
    m_bullet_interval ++;
    if (m_bullet_interval < BULLET_INTERVAL) return;

    // 重置间隔
    m_bullet_interval = 0;

    // 找到子弹
    Bullet * b = getNotFlyingBullet();
    if (b == nullptr) {
        qDebug() << "没有子弹了。。";
        return;
    }
    b->m_isFlying = true;  // 置成飞行状态
    b->m_bullet_X = m_plane_X + m_rect.width() / 2 -10;  // 子弹的x坐标在飞机的中间
    b->m_bullet_Y = m_plane_Y - 25;

}


/* updatePosition: 更新位置坐标（通过指定位置进行更新：鼠标）
 *   1. 边缘检测：位置坐标不能超界
 *   2. 更新坐标值
*/
void HeroPlane::updatePosition(int x, int y)
{
    // 边缘检测部分
    //   x的范围: [0, GAME_WIDTH - m_rect.width()]
    //   y的范围: [0, GAME_HEIGHT - m_rect.height()]
    // 边缘检测: x
    if (x <= 0) x = 0;
    if (x >= GAME_WIDTH - m_rect.width()) x = GAME_WIDTH - m_rect.width();

    // 边缘检测: y
    if (y <= 0) y = 0;
    if (y >= GAME_HEIGHT - m_rect.height()) y = GAME_HEIGHT - m_rect.height();

    // 飞机移动
    m_plane_X = x;
    m_plane_Y = y;

    // 边缘框的移动
    m_rect.moveTo(m_plane_X, m_plane_Y);  // 移动到图片的位置

}

/* getAllFlyingBullets: 子弹管理：找到所有飞行的子弹
 *   1. 检查所有子弹
 *   2. 将flying状态的子弹的指针放到vecotor中
*/
std::vector<Bullet*> HeroPlane::getAllFlyingBullets()
{
    std::vector<Bullet*> flyingBullets;
    // 检查弹匣
    for (int i = 0; i < BULLET_NUM; ++i)
    {
        if (m_bullets[i].m_isFlying)
        {
            flyingBullets.push_back(&m_bullets[i]);
        }
    }
    return flyingBullets;
}

/* getNotFlyingBullet: 子弹管理：找到一发可用的子弹
 *   1. 检查所有子弹
 *   2. 找到一发不是flying状态的子弹，返回地址
*/
Bullet* HeroPlane::getNotFlyingBullet()
{
    // 检查弹匣
    for (int i = 0; i < BULLET_NUM; ++i)
    {
        if (!m_bullets[i].m_isFlying)
        {
            return &m_bullets[i];
        }
    }
    return nullptr;
}

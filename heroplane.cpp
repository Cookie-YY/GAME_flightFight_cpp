#include "heroplane.h"
#include "config.h"

/*
 *  主角飞机的封装，移动和攻击
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

void HeroPlane::shoot()
{

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
    if (x <= 0) {
        x = 0;
    }
    if (x >= GAME_WIDTH - m_rect.width()) {
        x = GAME_WIDTH - m_rect.width();
    }
    // 边缘检测: y
    if (y <= 0) {
        y = 0;
    }
    if (y >= GAME_HEIGHT - m_rect.height()) {
        y = GAME_HEIGHT - m_rect.height();
    }
    m_plane_X = x;
    m_plane_Y = y;
}

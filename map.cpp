#include "map.h"
#include "config.h"


/*
 *  地图的封装，场景一直在移动：通过两张图的拼接感觉地图一直在变
*/


/* Map: 构造函数
 *   1. 加载图片
 *   2. 初始化位置坐标：第一张图在屏幕上面（屏幕外），第二张图是背景
 *   3. 初始化滚动速度
*/
Map::Map()
{
    // 初始化地图：两张图是同一张图，首尾可以拼上
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    // 初始化Y轴坐标
    m_map1_posY = -GAME_HEIGHT;  // 第一张图的y在屏幕上面
    m_map2_posY = 0;             // 第二张图就是最开始的背景

    // 地图滚动速度
    m_scroll_speed= MAP_SCROLL_SPEED;
}

/* updatePosition: 更新地图坐标（这个函数是会被即时refresh的）
 *   1. 更新第一张图：往下走，越界后回到屏幕上面
 *   2. 更新第一张图：往下走，越界后回到屏幕中央
*/
void Map::refreshPosition()
{
    m_map1_posY += m_scroll_speed;
    if (m_map1_posY >= 0) m_map1_posY = -GAME_HEIGHT;

    m_map2_posY += m_scroll_speed;
    if (m_map2_posY >= GAME_HEIGHT) m_map2_posY = 0;

}

#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class Map
{
public:
    Map();

    // 更新地图坐标值
    void refreshPosition();

public:
    // 地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;

    // 地图Y轴坐标
    int m_map1_posY;
    int m_map2_posY;

    // 地图滚动速度
    int m_scroll_speed;

};

#endif // MAP_H

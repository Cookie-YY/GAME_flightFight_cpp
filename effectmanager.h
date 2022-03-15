#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <QSound>

#include "bomb.h"
#include "config.h"

class EffectManager
{
public:
    EffectManager();

    /*************** 爆炸管理 ***************/
    // 找到所有正在爆炸的 “爆炸”（绘制效果，更新图片索引）
    std::vector<Bomb*> getAllBombingBombs();

    // 找到一个不是正在爆炸的 “爆炸” （碰撞检测后进行爆炸）
    Bomb* getNotBombingBomb();

    // 分发一个“爆炸”
    void dispatchBomb(int x, int y);

    // 爆炸效果数组
    Bomb m_bombs[BOMB_NUM];

    // 不需要间隔记录，只要发生爆炸，就得爆炸，并不是满足时间条件后才出现的爆炸
//     // 敌机的间隔记录：发射敌机时需要满足间隔（m_enemy_interval++后与目标值比较）
//    int m_enemy_interval = 0;

    /*************** 音效管理 ***************/
    void playBackGroundSound();  // 播放背景音乐
    void playBombSound();  // 播放爆炸特效音乐
    QSound * m_backGroundSound;  // 背景音乐资源
    QSound * m_bombSound;  // 爆炸音乐资源
};

#endif // EFFECTMANAGER_H

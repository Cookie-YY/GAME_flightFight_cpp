#include <QSound>
#include <QDebug>

#include "effectmanager.h"


/*
 *  特效管理的封装：特效管理（爆炸效果的管理 + 音乐效果的管理）
 *      * 类似EnemyBoss对于敌机的管理 *
 *  1. 加载背景音乐和爆炸音乐
 *  2. 背景音乐无限循环
*/


EffectManager::EffectManager()
{
    m_backGroundSound = new QSound(SOUND_BACKGROUND_PATH);
    m_bombSound = new QSound(SOUND_BOMB_PATH);
    m_backGroundSound->setLoops(-1); // 背景音乐无限循环
}

/* getAllBombingBombs: 爆炸管理：找到所有正在爆炸的爆炸
 *   1. 检查所有爆炸
 *   2. 将bombing状态的敌机的指针放到vecotor中
*/
std::vector<Bomb *> EffectManager::getAllBombingBombs()
{
    std::vector<Bomb*> bombingBombs;
    // 检查爆炸
    for (int i=0; i<ENEMY_NUM; ++i)
    {
        if (m_bombs[i].m_isBombing)
        {
            bombingBombs.push_back(&m_bombs[i]);
        }
    }
    return bombingBombs;
}

/* getNotBombingBomb: 爆炸管理：找到一个可用的爆炸
 *   1. 检查所有爆炸
 *   2. 找到一个不是bombing状态的爆炸，返回地址
*/
Bomb *EffectManager::getNotBombingBomb()
{
    // 检查爆炸
    for (int i=0; i<ENEMY_NUM; ++i)
    {
        if (!m_bombs[i].m_isBombing)
        {
            return &m_bombs[i];
        }
    }
    return nullptr;
}

/* dispatchBomb: 分发爆炸：修改爆炸的状态并初始化坐标
 *   1. 找到可用的敌机后，置成飞行状态并初始化其x和y坐标
*/
void EffectManager::dispatchBomb(int x, int y)
{
//    // 不到间隔不能分发敌人
//    m_enemy_interval ++;
//    if (m_enemy_interval < ENEMY_INTERVAL) return;

//    // 重置间隔
//    m_enemy_interval = 0;

    // 找到可用的爆炸
    Bomb * b = getNotBombingBomb();
    if (b == nullptr) {
        qDebug() << "没有可用爆炸效果了。。";
        return;
    }

    // 更新坐标
    b->m_isBombing = true;  // 置成爆炸状态
    b->m_bomb_X = x;
    b->m_bomb_Y = y;

}


/* playBackGroundSound: 播放背景音乐
*/
void EffectManager::playBackGroundSound()
{
    m_backGroundSound->play();
}

/* playBackGroundSound: 播放爆炸效果音乐
*/
void EffectManager::playBombSound()
{
    m_bombSound->play();
}

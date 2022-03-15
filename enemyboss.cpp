#include <QDebug>
#include <ctime>

#include "enemyboss.h"
#include "enemyplane.h"
#include "config.h"

/*
 *  敌机管理的封装：敌机管理（找到一个可用的敌机 / 找到所有飞行的敌机）
 *      * 类似HeroPlane对于子弹的管理 *
*/

/* EnemyBoss: 构造函数
 *   1. 初始化随机种子
*/
EnemyBoss::EnemyBoss()
{
    srand( (unsigned int) time (nullptr) );  // 随机数种子
}

/* getAllFlyingBullets: 敌机管理：找到所有飞行的敌机
 *   1. 检查所有敌机
 *   2. 将flying状态的敌机的指针放到vecotor中
*/
std::vector<EnemyPlane *> EnemyBoss::getAllFlyingEnemys()
{
    std::vector<EnemyPlane*> flyingEnemys;
    // 检查敌机
    for (int i=0; i<ENEMY_NUM; ++i)
    {
        if (m_enemys[i].m_isFlying)
        {
            flyingEnemys.push_back(&m_enemys[i]);
        }
    }
    return flyingEnemys;
}

/* getNotFlyingBullet: 敌机管理：找到一个可用的敌机
 *   1. 检查所有敌机
 *   2. 找到一个不是flying状态的敌机，返回地址
*/
EnemyPlane *EnemyBoss::getNotFlyingEnemy()
{
    // 检查敌机
    for (int i=0; i<ENEMY_NUM; ++i)
    {
        if (!m_enemys[i].m_isFlying)
        {
            return &m_enemys[i];
        }
    }
    return nullptr;
}

/* dispatchEnemy: 分发敌机：敌机出场
 *   1. 间隔++后进行判断
 *   2. 符合要求后重置间隔
 *   3. 找到可用的敌机后，置成飞行状态并初始化其x和y坐标
*/
void EnemyBoss::dispatchEnemy()
{
    // 不到间隔不能分发敌人
    m_enemy_interval ++;
    if (m_enemy_interval < ENEMY_INTERVAL) return;

    // 重置间隔
    m_enemy_interval = 0;

    // 找到可用的敌人
    EnemyPlane * ep = getNotFlyingEnemy();
    if (ep == nullptr) {
        qDebug() << "没有可用敌人了。。";
        return;
    }

    // 更新坐标
    ep->m_isFlying = true;  // 置成飞行状态
    ep->m_enemy_X = rand() % (GAME_WIDTH - ep->m_rect.width());  // 在(屏幕宽度-敌机宽度)中随机
    ep->m_enemy_Y = 0;

}

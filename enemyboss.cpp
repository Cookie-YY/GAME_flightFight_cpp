#include <QDebug>
#include <ctime>

#include "enemyboss.h"
#include "enemyplane.h"
#include "config.h"

EnemyBoss::EnemyBoss()
{
    srand( (unsigned int) time (nullptr) );  // 随机数种子
}

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

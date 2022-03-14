#ifndef ENEMYBOSS_H
#define ENEMYBOSS_H

#include "enemyplane.h"
#include "config.h"

class EnemyBoss
{
public:
    EnemyBoss();

    // 找到所有飞行状态的敌机
    std::vector<EnemyPlane*> getAllFlyingEnemys();

    // 找到一颗不是飞行状态的子弹
    EnemyPlane* getNotFlyingEnemy();

    // 敌机出场
    void dispatchEnemy();

public:
    // 敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    // 敌机的间隔记录
    int m_enemy_interval = 0;

};

#endif // ENEMYBOSS_H

#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    // 初始化敌机图片
    m_enemy.load(ENEMY_PATH);
//    // 初始化位置
//    m_enemy_X = (GAME_WIDTH-m_enemy.width()) / 2;  // 初始化x位置是随机数
//    m_enemy_Y = 0;      // 初始化y位置是最上面
//    // 初始化边缘框
    m_rect.setWidth(m_enemy.width());
    m_rect.setHeight(m_enemy.height());
//    m_rect.moveTo(m_enemy_X, m_enemy_Y);  // 移动到图片的起始位置

    // 敌机状态
    m_isFlying = false;

    // 子弹速度
    m_speed = ENEMY_SPEED;
}

void EnemyPlane::refreshPosition()
{
    // 非flying状态的敌机不更新坐标
    if (!m_isFlying) return;

    // 边缘检测：超过上边缘就闲置
    if (m_enemy_Y + m_speed >= GAME_HEIGHT) {
        m_isFlying = false;
        return;
    }

    // 子弹坐标移动
    m_enemy_Y += m_speed;

    // 边缘框移动
    m_rect.moveTo(m_enemy_X, m_enemy_Y);  // 移动到图片的位置


}

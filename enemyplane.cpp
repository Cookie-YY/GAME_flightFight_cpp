#include "enemyplane.h"
#include "config.h"

/*
 *  敌机的封装，目前只有移动：更新位置
*/


/* EnemyPlane: 构造函数
 *   1. 加载图片
 *   2. flying状态置为false（由EnemyBoss进行初始化）
 *   3. 初始化边缘检测框
 *      * 之后使用这个框的长和宽指代敌机的长和宽
 *      * 之后使用这个框进行碰撞检测
 *   * 位置信息由EnemyBoss进行初始化
*/
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

/* refreshPosition: 刷新位置坐标
 *   1. 状态检测，非flying不移动
 *   2. 边缘检测，超出边缘，修改状态
 *   3. 更新敌机的y坐标，更新矩形框
*/
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

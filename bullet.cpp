#include "bullet.h"
#include "config.h"

Bullet::Bullet()
{
    // 初始化子弹图片
    m_bullet.load(BULLET_PATH);
//    // 初始化位置
//    m_bullet_X = (GAME_WIDTH-m_bullet.width()) / 2;  // 初始化x位置是屏幕的一半-自己的一半
//    m_bullet_Y = GAME_HEIGHT-m_bullet.height();      // 初始化y位置是最底下
//    // 初始化边缘框
    m_rect.setWidth(m_bullet.width());
    m_rect.setHeight(m_bullet.height());
//    m_rect.moveTo(m_bullet_X, m_bullet_Y);  // 移动到图片的起始位置

    // 子弹状态
    m_isFlying = false;

    // 子弹速度
    m_speed = BULLET_SPEED;
}

void Bullet::refreshPosition()
{
    // 非flying状态的子弹不更新坐标
    if (!m_isFlying) return;

    // 边缘检测：超过上边缘就闲置
    if (m_bullet_Y - m_speed <= -m_rect.height()) {
        m_isFlying = false;
        return;
    }

    // 子弹坐标移动
    m_bullet_Y -= m_speed;

    // 边缘框移动
    m_rect.moveTo(m_bullet_X, m_bullet_Y);  // 移动到图片的位置

}

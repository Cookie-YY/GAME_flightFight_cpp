#include <QPixmap>

#include "bomb.h"
#include "config.h"

/*
 *  爆炸的封装，管理一组图片进行切图
*/


/* Bomb: 构造函数
 *   1. 加载一组爆炸效果
 *   2. bombing状态置为false（由EffectManager进行初始化）
*/
Bomb::Bomb()
{
    // 加载爆炸资源组
    for (int i = 1; i <= BOMB_MAX; ++i)
    {
        m_imgs.push_back(QPixmap(QString(BOMB_PATH).arg(i)));
    }

    // 爆炸状态
    m_isBombing = false;
}

/* refreshImgIndex: 刷新图片索引
 *   1. 状态检测，非bombing不刷新
 *   2. 边缘检测，超出图片索引的范围，重置索引
 *   3. 更新图片索引
*/
void Bomb::refreshImgIndex()
{
    // 非bombing状态的爆炸不更新图片下标
    if (!m_isBombing) return;

    // 不到间隔不能切图
    m_bomb_interval ++;
    if (m_bomb_interval < BOMB_INTERVAL) return;

    // 重置间隔
    m_bomb_interval = 0;

    // 边界检测：超过图片的最大索引就闲置
    if (m_imgIndex >= BOMB_MAX) {
        m_isBombing = false;
        m_imgIndex = 1;
        return;
    }

    // 爆炸图片索引+1
    m_imgIndex ++;

}

#ifndef BOMB_H
#define BOMB_H

# include <QVector>
# include <QPixmap>

class Bomb
{
public:
    Bomb();

    // 更新爆炸图片索引
    void refreshImgIndex();

public:
    // 爆炸资源数组
    QVector<QPixmap> m_imgs;

    // 当前的图片下标：从1开始
    int m_imgIndex = 1;

    // 爆炸点坐标
    int m_bomb_X;
    int m_bomb_Y;

    // 爆炸状态是否正在爆炸～：为false爆炸不会被绘制（避免重复的创建和删除对象）
    bool m_isBombing;

    // 爆炸切图时间间隔记录：切图时需要满足间隔（m_bomb_interval++后与目标值比较）
    int m_bomb_interval = 0;


};

#endif // BOMB_H

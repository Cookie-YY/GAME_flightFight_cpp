#ifndef CONFIG_H
#define CONFIG_H

/******** 飞机大战的全局配置文件 ********/
#define GAME_WIDTH 512  // 宽度
#define GAME_HEIGHT 768  // 高度
#define GAME_TITLE "飞机大战——by cookie"  // 标题
#define GAME_RES_PATH "./plane.rcc"  // rcc文件路径
#define GAME_ICON ":/res/app.ico" // 游戏图标
#define GAME_REFRESH_RATE 10  // 刷新时间ms

/******** 地图配置数据 ********/
#define MAP_PATH ":/res/img_bg_level_1.jpg"  // 地图背景路径
#define MAP_SCROLL_SPEED 2  // 地图滚动速度

/******** 飞机配置数据 ********/
#define HERO_PATH ":/res/hero2.png"  // 飞机图片路径

/******** 子弹配置数据 ********/
#define BULLET_PATH ":/res/bullet_1.png"  // 子弹图片路径
#define BULLET_SPEED 5  // 子弹速度
#define BULLET_NUM 30   // 弹匣中子弹数量
#define BULLET_INTERVAL 20  // 发射间隔：每 GAME_REFRESH_RATE 毫秒刷新一次，刷新 BULLET_INTERVAL 次进行发射

/******** 敌机配置数据 ********/
#define ENEMY_PATH ":/res/img-plane_5.png"  // 敌机图片路径
#define ENEMY_SPEED 5  // 敌机速度
#define ENEMY_NUM 20  // 敌机总数量
#define ENEMY_INTERVAL 30  // 出场间隔



#endif // CONFIG_H

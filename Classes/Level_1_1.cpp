#include"Level_1_1.h"
#include"sound&music.h"
#include"GameData.h"
USING_NS_CC;
extern int if_speed_up;//是否加速
extern int if_pause;//是否暂停
extern int game_money;//金钱
extern int game_waves;//当前波数
extern char game_map[7][12];//辅助地图数组
int level_1_1_waves = 15;
/*******************************  错误处理  ************************************/
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}
/**********************************  Level_1_1  ***********************************/
Layer* Level_1_1::createLayer()
{
    return Level_1_1::create();
}
//初始化
bool Level_1_1::init()
{
    if (!Layer::init()) {
        return false;
    }
    //获取屏幕大小
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /***********************  部分全局变量初始化  *******************/
    //更新金钱显示
    game_money = 450;
    //更新波数显示
    game_waves = 1;
    //更新地图
     const char level_1_1_map[7][12] = {
        {0,0,0,1,1,1,1,1,1,0,0,0},
        {0,1,0,1,1,1,1,1,1,0,1,0},
        {0,1,0,0,1,0,0,1,0,0,1,0},
        {0,1,1,0,1,1,1,1,0,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };
    for (int i = 0; i <7; i++) {
        for (int j = 0; j < 12; j++) {
            game_map[i][j] = level_1_1_map[i][j];
        }
    }
    /***********************  背景  ************************/
    auto bg_image = Sprite::create("/Level_1_1/Level_1_1_bg.png");
    if (bg_image == nullptr) {
        problemLoading("'Level_1_1_bg.png'");
    }
    bg_image->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));
    this->addChild(bg_image);
    //出怪点
    /*auto start_point = Sprite::create("/Level_1_1/startPoint.PNG");
    if (start_point == nullptr) {
        
    }*/
    return true;
}


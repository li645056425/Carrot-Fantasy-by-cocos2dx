#include"Level_1_1.h"
#include"sound&music.h"
#include"GameData.h"
USING_NS_CC;
extern int if_speed_up;//�Ƿ����
extern int if_pause;//�Ƿ���ͣ
extern int game_money;//��Ǯ
extern int game_waves;//��ǰ����
extern char game_map[7][12];//������ͼ����
int level_1_1_waves = 15;
/*******************************  ������  ************************************/
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}
/**********************************  Level_1_1  ***********************************/
Layer* Level_1_1::createLayer()
{
    return Level_1_1::create();
}
//��ʼ��
bool Level_1_1::init()
{
    if (!Layer::init()) {
        return false;
    }
    //��ȡ��Ļ��С
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /***********************  ����ȫ�ֱ�����ʼ��  *******************/
    //���½�Ǯ��ʾ
    game_money = 450;
    //���²�����ʾ
    game_waves = 1;
    //���µ�ͼ
    char level_1_1_map[7][12] = {
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
    /***********************  ����  ************************/
    auto bg_image = Sprite::create("/Level_1_1/Level_1_1_bg.png");
    if (bg_image == nullptr) {
        problemLoading("'Level_1_1_bg.png'");
    }
    bg_image->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));
    this->addChild(bg_image);
    //���ֵ�
    /*auto start_point = Sprite::create("/Level_1_1/startPoint.PNG");
    if (start_point == nullptr) {
        
    }*/
    return true;
}


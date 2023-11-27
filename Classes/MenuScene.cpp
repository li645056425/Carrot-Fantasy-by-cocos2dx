#include "MenuScene.h"

USING_NS_CC;
/*�˵�����*/
Scene* MenuScene::createScene()
{
    return MenuScene::create();
}
/*������*/
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
/*��ʼ��*/
bool MenuScene::init()
{
    /*��ʼ������*/
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*����ͼ*/
    auto background_image = Sprite::create("/MenuScene/MainBG.PNG");
    if (background_image == nullptr)
    {
        problemLoading("'MainBG.PNG'");
    }
    else
    {
        background_image->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height / 2));

        this->addChild(background_image);
    }
    /*��*/
    auto cloud = Sprite::create();
    cloud->setName("Cloud");
    //����
    auto cloud1 = Sprite::create("/MenuScene/Cloud.PNG");
    if (cloud1 == nullptr)
    {
        problemLoading("'Cloud.PNG'");
    }
    else
    {
        cloud1->setPosition(Vec2(origin.x - cloud1->getContentSize().width,
            origin.y + visibleSize.height * 0.85));
        cloud1->setTag(1);
        cloud->addChild(cloud1);
    }
    ////�����˶�
    //С��
    auto cloud2 = Sprite::create("/MenuScene/Cloud.PNG");
    if (cloud2 == nullptr)
    {
        problemLoading("'Cloud.PNG'");
    }
    else
    {
        cloud2->setScale(0.5);
        cloud2->setPosition(Vec2(origin.x + visibleSize.width + cloud2->getContentSize().width,
            origin.y + visibleSize.height * 0.8));
        cloud2->setTag(2);
        cloud->addChild(cloud2);
    }

    this->addChild(cloud);
    /*��ӹ���ͼ��*/
    auto monster = Sprite::create("/MenuScene/FlyMonster.PNG");
    if (monster == nullptr) {
        problemLoading("'FlyMonster.PNG'");
    }
    else {
        monster->setPosition(Vec2(origin.x + visibleSize.width / 4,
            origin.y + visibleSize.height * 0.8));
        monster->setName("Monster");
        this->addChild(monster);
    }
    /*����ܲ�ͼ��*/
    auto carrot = Sprite::create();
    //1,����ܲ�Ҷ��
    auto carrot_leaf1 = Sprite::create("/MenuScene/Leaf1.PNG");
    if (carrot_leaf1 == nullptr)
    {
        problemLoading("'Leaf1.PNG'");
    }
    else
    {
        carrot_leaf1->setPosition(Vec2(origin.x + visibleSize.width / 2 - carrot_leaf1->getContentSize().width / 2,
            origin.y + visibleSize.height / 2 + carrot_leaf1->getContentSize().height * 1.2));
        carrot->addChild(carrot_leaf1);
    }

    auto carrot_leaf2 = Sprite::create("/MenuScene/Leaf2.PNG");
    if (carrot_leaf2 == nullptr)
    {
        problemLoading("'Leaf2.PNG'");
    }
    else
    {
        carrot_leaf2->setPosition(Vec2(origin.x + visibleSize.width / 2 + carrot_leaf2->getContentSize().width / 2,
            origin.y + visibleSize.height / 2 + carrot_leaf2->getContentSize().height * 1.3));
        carrot_leaf2->setName("Leaf2");
        carrot->addChild(carrot_leaf2);
    }

    auto carrot_leaf3 = Sprite::create("/MenuScene/Leaf3.PNG");
    if (carrot_leaf3 == nullptr)
    {
        problemLoading("'Leaf3.PNG'");
    }
    else
    {
        carrot_leaf3->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height / 2 + carrot_leaf3->getContentSize().height * 1.1));
        carrot_leaf3->setName("Leaf3");
        carrot->addChild(carrot_leaf3);
    }

    //2,����ܲ�����
    auto carrot_body = Sprite::create("/MenuScene/CarrotBody.PNG");
    if (carrot_body == nullptr)
    {
        problemLoading("'CarrotBody.PNG'");
    }
    else
    {
        carrot_body->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height / 2 + carrot_body->getContentSize().height / 4));

        carrot->addChild(carrot_body);
    }

    this->addChild(carrot);
    /*��ӱ����ܲ�����*/
    auto title = Sprite::create("/MenuScene/MainTitle.PNG");
    if (title == nullptr) {
        problemLoading("'MainTitle.PNG'");
    }
    else {
        title->setPosition(Vec2(origin.x + visibleSize.width / 2 + title->getContentSize().width / 20,
            origin.y + visibleSize.height / 2 - title->getContentSize().height / 7));
        this->addChild(title);
    }

    /*�˵�����*/
    auto menu = Menu::create();
    menu->setPosition(Vec2::ZERO);
    //�˳���Ϸ��ť
    auto close_item = MenuItemFont::create("EXIT", CC_CALLBACK_1(MenuScene::close_game, this));
    if (close_item == nullptr) {
        problemLoading("'EXIT'");
    }
    else {
        close_item->setPosition(Vec2(origin.x + visibleSize.width - close_item->getContentSize().width * 0.6,
            origin.y + visibleSize.height - close_item->getContentSize().height / 2));
        menu->addChild(close_item);
    }
    //���ð�ť
    auto options_item = MenuItemImage::create("/MenuScene/Btn_Set.PNG", "/MenuScene/Btn_SetLight.PNG", CC_CALLBACK_1(MenuScene::goto_options, this));
    if (options_item == nullptr) {
        problemLoading("'options_item'");
    }
    else {
        options_item->setPosition(Vec2(origin.x + visibleSize.width * 0.2,
            origin.y + visibleSize.height / 3));
        menu->addChild(options_item);
    }
    //������ť
    auto helper_item = MenuItemImage::create("/MenuScene/Btn_Help.PNG", "/MenuScene/Btn_HelpLight.PNG", CC_CALLBACK_1(MenuScene::goto_helper, this));
    if (helper_item == nullptr) {
        problemLoading("'helper_item'");
    }
    else {
        helper_item->setPosition(Vec2(origin.x + visibleSize.width * 0.8,
            origin.y + visibleSize.height / 3));
        menu->addChild(helper_item);
    }
    //ð��ģʽ
    auto adventure_item = MenuItemImage::create("/MenuScene/Btn_NormalModle.PNG", "/MenuScene/Btn_NormalModleLight.PNG", CC_CALLBACK_1(MenuScene::goto_adventure, this));
    if (adventure_item == nullptr) {
        problemLoading("'adventure_item'");
    }
    else {
        adventure_item->setScale(0.9f);
        adventure_item->setPosition(Vec2(origin.x + visibleSize.width / 2 - adventure_item->getContentSize().width,
            origin.y + visibleSize.height / 8));
        menu->addChild(adventure_item);
    }
    //BOSSģʽ
    auto boss_item = MenuItemImage::create("/MenuScene/Btn_Boss.PNG", "/MenuScene/Btn_BossLight.PNG", CC_CALLBACK_1(MenuScene::goto_boss, this));
    if (boss_item == nullptr) {
        problemLoading("'boss_item'");
    }
    else {
        boss_item->setScale(0.9f);
        boss_item->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height / 8));
        menu->addChild(boss_item);
    }
    //���ﳲ
    auto nest_item = MenuItemImage::create("/MenuScene/Btn_MonsterNest.PNG", "/MenuScene/Btn_MonsterNestLight.PNG", CC_CALLBACK_1(MenuScene::goto_nest, this));
    if (nest_item == nullptr) {
        problemLoading("'nest_item'");
    }
    else {
        nest_item->setScale(0.9f);
        nest_item->setPosition(Vec2(origin.x + visibleSize.width / 2 + nest_item->getContentSize().width,
            origin.y + visibleSize.height / 8));
        menu->addChild(nest_item);
    }


    this->addChild(menu);
    /*����������*/
    this->scheduleUpdate();


    return true;
}

void MenuScene::update(float dt) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /*����������˶�*/
    Node* Monster = this->getChildByName("Monster");
    static bool direction = 1;//�����˶�
    static float dx = 0;
    if (direction == 1) {
        Monster->setPosition(Vec2(Monster->getPosition().x, Monster->getPosition().y - 20 * dt));
        dx += 20 * dt;
        if (dx >= Monster->getContentSize().height / 4) {
            direction = 0;
            dx = 0;
        }
    }
    else {
        Monster->setPosition(Vec2(Monster->getPosition().x, Monster->getPosition().y + 20 * dt));
        dx += 20 * dt;
        if (dx >= Monster->getContentSize().height / 4) {
            direction = 1;
            dx = 0;
        }
    }

    /*�Ƶ��˶�*/
    Node* Cloud = this->getChildByName("Cloud");
    Node* Cloud1 = Cloud->getChildByTag(1);
    Node* Cloud2 = Cloud->getChildByTag(2);

    Cloud1->setPosition(Vec2(Cloud1->getPosition().x + 50 * dt, Cloud1->getPosition().y));
    Cloud2->setPosition(Vec2(Cloud2->getPosition().x - 50 * dt, Cloud2->getPosition().y));
    if (Cloud1->getPosition().x >= visibleSize.width + Cloud1->getContentSize().width&& Cloud2->getPosition().x <= 0 - Cloud2->getContentSize().width) {
        Cloud1->setPosition(Vec2(0 - Cloud1->getContentSize().width, Cloud1->getPosition().y));
        Cloud2->setPosition(Vec2(visibleSize.width + Cloud2->getContentSize().width, Cloud2->getPosition().y));
    }
}

void MenuScene::close_game(Ref* psender) {

    Director::getInstance()->end();

    exit(0);
}

void  MenuScene::goto_options(Ref* pSender) {
    //������
}

void  MenuScene::goto_helper(Ref* pSender) {
    //������
}

void  MenuScene::goto_adventure(Ref* psender) {
    //������
}

void  MenuScene::goto_boss(Ref* psender) {
    //������
}

void  MenuScene::goto_nest(Ref* psender) {
    //������
}
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
    //����
    auto cloud1 = Sprite::create("/MenuScene/Cloud.PNG");
    if (cloud1 == nullptr)
    {
        problemLoading("'Cloud.PNG'");
    }
    else
    {
        cloud1->setPosition(Vec2(origin.x + visibleSize.width / 4,
            origin.y + visibleSize.height * 0.85));
        Color3B c = cloud1->getColor();
        c.r *= -0.7;
        c.g *= -0.7;
        c.b *= -0.7;
        cloud1->setColor(c);
        cloud->addChild(cloud1);
    }
    //С��
    auto cloud2 = Sprite::create("/MenuScene/Cloud.PNG");
    if (cloud2 == nullptr)
    {
        problemLoading("'Cloud.PNG'");
    }
    else
    {
        cloud2->setScale(0.5);
        cloud2->setPosition(Vec2(origin.x + visibleSize.width * 0.85,
            origin.y + visibleSize.height * 0.8));
        cloud->addChild(cloud2);
    }

    this->addChild(cloud);
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
    return true;
}


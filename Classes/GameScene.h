#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__

#include "cocos2d.h"

#define EMPTY 0
#define DISABLED 1
#define TOWER 2
//���ߺ���
struct pos {
    int i;
    int j;
};
struct vec2 {
    float x;
    float y;
};
//��ÿ��������������ת��Ϊ��������
static vec2 trans_ij_to_xy(pos position);
//��ÿ����������ת���ɶ�Ӧ�ĸ�����������
static pos trans_xy_to_ij(vec2 vec);
//ð��ģʽ��Ϸ��
class GameScene : public cocos2d::Scene
{
public:
    //���캯��
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
};
//��Ϸ�˵���
class GameMenu :public cocos2d::Layer 
{
public:
    //���캯��
    static cocos2d::Layer* createLayer();
    virtual bool init();
    CREATE_FUNC(GameMenu);
    //ѡ��
    void options();
    //��ʼ
    void start();
    //����
    void build(pos position, Vector<int> tower_available);
    //����ɾ��
    void tower_operations(pos position);
    //ʵʱ���½�ҵ�����
    virtual void update(float dt);
};
#endif // __Game_SCENE_H__

#ifndef __SCENE_102_H__
#define __SCENE_102_H__

#include "cocos2d.h"

class Scene102 : public cocos2d::Layer
{
private:
	cocos2d::Sprite *cuberbtn;
	cocos2d::Sprite *replaybtn;
	cocos2d::Sprite *returnbtn;
	cocos2d::Rect    rectCuber;
	cocos2d::Rect    rectReplay;
	cocos2d::Rect    rectReturn;

	int  _sceneno;
	char _cSceneNo[10];

public:
    static cocos2d::Scene* createScene();

	Scene102(){}; //�غc��
	~Scene102();//�Ѻc��


    virtual bool init();
	void doStep(float dt);

	//Ĳ�I
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�}�l�ƥ�
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I���ʨƥ�
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�����ƥ� 
    
    // implement the "static create()" method manually
    CREATE_FUNC(Scene102);
};

#endif // __SCENE_102_H__

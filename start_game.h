#ifndef __START_GAME_H__
#define __START_GAME_H__
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class StartGame : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StartGame);

public:
	//��ʼ��Ϸ��ť�ص�
	void start_play(Ref* ref);
};

#endif // !__START_GAME_H__

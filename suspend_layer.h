#ifndef __SUSPEND_LAYER_H__
#define __SUSPEND_LAYER_H__
#include "cocos2d.h"
USING_NS_CC;
class SuspendLayer: public cocos2d::Layer
{
public:
	SuspendLayer();
	~SuspendLayer();
public:
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(SuspendLayer);

public:
	//开始菜单点击
	void back_game(Ref* ref);

};

#endif // __SUSPEND_LAYER_H__
#ifndef __ACHIEVEMENT_LAYER_H__
#define __ACHIEVEMENT_LAYER_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;


class AchievementLayer:public cocos2d::Layer
{
public:
	CREATE_FUNC(AchievementLayer);
	static void showAchiecement(int id);
	void initWithAchievementId(int id);
private:
	
	int achievement_id_;
	Sprite* achievement_frame_;
	Sprite* achievement_icon_;
	Label* achievement_name_;
	Label* achievement_info_;
	void showWithAnimation();
	void remove_achievement();


};


#endif  //__ACHIEVEMENT_LAYER_H__



#ifndef __ENEMY_BASE_H__
#define __ENEMY_BASE_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;


class EnemyBase: public cocos2d::Sprite
{
public:
	EnemyBase();
	~EnemyBase();
public:
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(EnemyBase);
	void onEnterTransitionDidFinish();
	void onExit();
	virtual void update(float delta);
	
public:
	//初始化敌机
	void initEnemy(int index = 1);
	//爆炸动画
	void enemy_death();
	//删除自己
	void remove_enemy();

	//敌机血量
	void set_hp(int hp);
	int get_hp() { return enemy_hp_; }
public:
	//敌机类型
	int enemy_index_;
	//敌机血量
	int enemy_hp_;
	//是否爆炸
	bool is_death_;
};

#endif


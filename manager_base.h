#ifndef __MANAGER_BASE_H__
#define __MANAGER_BASE_H__

#include "cocos2d.h"
#include "enemy_base.h"
#include "bullet.h"
USING_NS_CC;

class ManagerBase
{
public:
	ManagerBase();
	~ManagerBase();

public:
	//创建单例相关的方法
	static ManagerBase* getInstance();
	//删除
	static void deleteInstance();
private :
	static ManagerBase* manager_;
public:
	//管理子弹和敌机
	Vector<EnemyBase*> &getEnemyList() { return enemy_list_; }
	Vector<Bullet*> &getBulletList() { return bullet_list_; }
	//添加敌机
	void set_enemy_list(EnemyBase* enemy);
	//添加子弹
	void set_bullet_list(Bullet* bullet);
	//删除敌机
	void remove_enemy_list(EnemyBase* enemy);
	//删除子弹
	void remove_bullet_list(Bullet* bullet);
public:
	Vector<EnemyBase*> enemy_list_;
	Vector<Bullet*> bullet_list_;
};

#endif // 
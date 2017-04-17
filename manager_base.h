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
	//����������صķ���
	static ManagerBase* getInstance();
	//ɾ��
	static void deleteInstance();
private :
	static ManagerBase* manager_;
public:
	//�����ӵ��͵л�
	Vector<EnemyBase*> &getEnemyList() { return enemy_list_; }
	Vector<Bullet*> &getBulletList() { return bullet_list_; }
	//��ӵл�
	void set_enemy_list(EnemyBase* enemy);
	//����ӵ�
	void set_bullet_list(Bullet* bullet);
	//ɾ���л�
	void remove_enemy_list(EnemyBase* enemy);
	//ɾ���ӵ�
	void remove_bullet_list(Bullet* bullet);
public:
	Vector<EnemyBase*> enemy_list_;
	Vector<Bullet*> bullet_list_;
};

#endif // 
#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__
#include "cocos2d.h"

USING_NS_CC;
class PlaneSupport;
class MainGame : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MainGame);
	void onEnterTransitionDidFinish();
	void onExit();

	void update(float delta);
public:
	//���㴥������
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
public:
	//��ʼ����ҷɻ�
	void init_hero_plane(int index);
public:
	//��ӵл�
	void add_enemy(float delta);

	//����ӵ�
	void add_bullet(float tm);
	//��ײ���
	void is_crash(float tm);
	//��������
	void hero_death();
	void hero_player_action_end();

	//�������
	void add_support(float tm);
	//��ӻ�����ʺ���ӵ�Ч��
	void add_support_bullet(float tm);

public:
	void suspend(Ref * ref);
public:
	Sprite* spr_bg1_;
	Sprite* spr_bg2_;

	//��ҷɻ�
	Sprite* hero_player_;
public:
	PlaneSupport* plane_support_; //֧Ԯ����
	int support_index_;//֧Ԯ����������
	int score_; //��ǰ����

	Label* label_score_num_; //��ǰ��

	Label*label_best_score_num_; // ��߷�
public:
	int plane_type_; //�ɻ�����
};


#endif // !__MAIN_GAME_H__

#include "enemy_base.h"
#include "manager_base.h"


EnemyBase::EnemyBase()
{
}


EnemyBase::~EnemyBase()
{
}

bool EnemyBase::init()
{
	is_death_ = false;
	if (!Sprite::init())
		return false;
	return true;
}

void EnemyBase::menuCloseCallback(cocos2d::Ref * pSender)
{
}

void EnemyBase::onEnterTransitionDidFinish()
{
	Sprite::onEnterTransitionDidFinish();
	scheduleUpdate();
}

void EnemyBase::onExit()
{
	unscheduleUpdate();
	Sprite::onExit();
}

void EnemyBase::update(float delta)
{
	//�����ը ���ƶ�
	if (is_death_)
		return;
	//ʵ�ֵл��˶�
	auto point = this->getPositionY() - 5;
	this->setPositionY(point);
	//����Ƴ���Ļ��Ӹ��ڵ��Ƴ�
	if (point < -this->getContentSize().height)
	{
		this->removeFromParentAndCleanup(true);
		remove_enemy();
	}

}

void EnemyBase::initEnemy(int name_index)
{
	//�л�Ѫ��
	enemy_hp_ = name_index;
	//��ʼ���л�
	string name_str = String::createWithFormat("plane/enemy%d.png", name_index)->getCString();
	//��ӵл�ͼƬ
	this->initWithFile(name_str);
	//��ȡ��Ļ��С
	Size size = Director::getInstance()->getWinSize();
	//����л�����
	Point pos = ccp(CCRANDOM_0_1()*
		(size.width - this->getContentSize().width-20) + this->getContentSize().width / 2+10, size.height);
	this->setPosition(pos);
}

void EnemyBase::enemy_death()
{
	//��ը
	is_death_ = true;
	auto animation = Animation::create();
	for (int i = 1; i <= 4; ++i)
	{
		auto enemy_name = String::createWithFormat("plane/b%d.png", i);
		animation->addSpriteFrameWithFile(enemy_name->getCString());
	}
	animation->setDelayPerUnit(0.2f);
	animation->setLoops(1);
	this->runAction(Sequence::create(
		Animate::create(animation), RemoveSelf::create(), CallFunc::create(CC_CALLBACK_0(EnemyBase::remove_enemy, this)), NULL));

}

void EnemyBase::remove_enemy()
{
	ManagerBase::getInstance()->remove_enemy_list(this);
}

void EnemyBase::set_hp(int hp)
{
	enemy_hp_ = hp;
}

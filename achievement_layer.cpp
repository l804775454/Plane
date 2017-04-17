#include "achievement_layer.h"



void AchievementLayer::showAchiecement(int id)
{
	if (Director::getInstance()->getRunningScene() != nullptr)
	{
		AchievementLayer* layer = AchievementLayer::create();
		layer->initWithAchievementId(id);
		Director::getInstance()->getRunningScene()->addChild(layer);
		int i = 0;
	}
}

void AchievementLayer::initWithAchievementId(int id)
{
	achievement_id_ = id;
	//获取屏幕大小
	Size size = Director::getInstance()->getWinSize();
	//frame
	achievement_frame_ = Sprite::create("achievement/chengjiu1.png");
	float frame_height = achievement_frame_->getContentSize().height;
	achievement_frame_->setPosition(Vec2(size.width / 2, size.height + frame_height / 2));
	this->addChild(achievement_frame_);

	//icon
	string name_str = String::createWithFormat("achievement/am%d.png", achievement_id_)->getCString();
	achievement_icon_ = Sprite::create(name_str);
	achievement_icon_->setPosition(Vec2(25,frame_height/2));
	achievement_frame_->addChild(achievement_icon_);


    //text
	auto dictionary = Dictionary::createWithContentsOfFile("fonts/text.xml");
	//根据成就id获取name
	name_str = String::createWithFormat("achievementName%d", achievement_id_)->getCString();
	achievement_name_ = Label::createWithSystemFont(((__String*)(dictionary->objectForKey(name_str)))->getCString(),"Arial",24);
	//根据成就id获取info
	name_str = String::createWithFormat("achievementInfo%d", achievement_id_)->getCString();
	achievement_info_ = Label::createWithSystemFont(((__String*)(dictionary->objectForKey(name_str)))->getCString(), "Arial", 20);
	
	//布局
	achievement_name_->setColor(Color3B::ORANGE);
	achievement_name_->setAnchorPoint(ccp(0, 0.5));
	achievement_info_->setAnchorPoint(ccp(0, 0.5));
	achievement_name_->setPosition(ccp(45, frame_height / 2 + 8));
	achievement_info_->setPosition(ccp(45, frame_height / 2 - 8));
	achievement_frame_->addChild(achievement_name_);
	achievement_frame_->addChild(achievement_info_);

	showWithAnimation();
}

void AchievementLayer::showWithAnimation()
{
	float frame_height = achievement_frame_->getContentSize().height;
	auto action1 = MoveBy::create(1, ccp(0, -frame_height));
	auto action2 = DelayTime::create(2);
	auto action3 = MoveBy::create(1, ccp(0, frame_height));
	Sequence* seq = Sequence::create(action1, action2, action3, CallFunc::create(CC_CALLBACK_0(AchievementLayer::remove_achievement, this)), NULL);
	achievement_frame_->runAction(seq);
}

void AchievementLayer::remove_achievement()
{
	this->removeFromParentAndCleanup(true);
}

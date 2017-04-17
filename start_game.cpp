#include "start_game.h"
#include "main_game.h"
#include "select_plane_scene.h"
#include "Sound.h"
cocos2d::Scene * StartGame::createScene()
{
	auto scene = Scene::create();

	auto layer = StartGame::create();

	scene->addChild(layer);
	return scene;
}

bool StartGame::init()
{
	if (!Layer::init()) {
		return false;
	}
	//游戏窗口大小
	auto size = Director::getInstance()->getWinSize();

	//游戏背景
	auto spr_bg = Sprite::create("ui/bg.png");
	spr_bg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(spr_bg);

	//读取xml
	auto dic = Dictionary::createWithContentsOfFile("fonts/text.xml");
	auto str = (String*)(dic->objectForKey("title"));
	//游戏标题
	auto title = Label::create();
	title->setString(str->getCString());
	title->setSystemFontSize(60);
	title->setPosition(ccp(size.width / 2, size.height));
	title->setColor(ccc3(174, 111, 23));
	this->addChild(title);
	//实现title动画
	auto action1 = MoveTo::create(0.4f, ccp(size.width / 2, size.height - title->getContentSize().height));
	auto action2 = RotateBy::create(0.2f, -30);
	auto action3 = RotateBy::create(0.3f, 60);
	auto action4 = RotateBy::create(0.2f, -30);
	title->runAction(Sequence::create(action1, action2, action3, action4, NULL));
	
	//创建帧动画
	auto animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		auto spr_name = String::createWithFormat("ui/start%d.png", i);
		animation->addSpriteFrameWithFile(spr_name->getCString());

	}
	//设置帧动画播放时间
	animation->setDelayPerUnit(0.3f);
	//设置帧动画的播放次数
	animation->setLoops(-1);//无限循环

	//创建精灵,用来播放帧动画
	auto sprite = Sprite::create("ui/start1.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(sprite);
	sprite->runAction(Animate::create(animation));

	//添加开始按钮
	str = (String*)(dic->objectForKey("play"));
	auto btn_label = Label::create();
	btn_label->setString(str->getCString());
	btn_label->setSystemFontSize(40);

	auto start_menu = MenuItemLabel::create(btn_label,
		CC_CALLBACK_1(StartGame::start_play,this));
	auto menu = Menu::create(start_menu,NULL);
	menu->setPosition(ccp(size.width / 2, size.height*0.3));
	this->addChild(menu);






	return true;
}

void StartGame::start_play(Ref * ref)
{

	//切换场景
	//Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5, MainGame::createScene()));
	Sound::getInstance()->play_bg_music(MUSIC_TYPE_BACKGROUND);
	//进入选择界面
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5, SelectPlaneScene::create()));
}

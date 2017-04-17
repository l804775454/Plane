#ifndef _SOUND_H_
#define _SOUND_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

//背景音乐
enum MUSIC_TYPE
{
	MUSIC_TYPE_BACKGROUND,
};

//音效
enum EFFECT_TYPE
{
	EFFECT_TYPE_DEATH,
	EFFECT_TYPE_ACHIEVE,
};
class Sound
{
public:
	static Sound * getInstance();
	static void freeInstance();
private:
	static Sound * m_sound;
	Sound();

	//根据不同音乐音效类型会的相应的音乐文件
	char * get_music(MUSIC_TYPE type);
	char * get_effect(EFFECT_TYPE type);
public:
	//声音的播放和暂停
	void play_effect(EFFECT_TYPE type);
	void play_bg_music(MUSIC_TYPE type);
	void pause_bg_music();
};


#endif // !__SOUND_H__
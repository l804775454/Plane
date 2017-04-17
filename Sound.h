#ifndef _SOUND_H_
#define _SOUND_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

//��������
enum MUSIC_TYPE
{
	MUSIC_TYPE_BACKGROUND,
};

//��Ч
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

	//���ݲ�ͬ������Ч���ͻ����Ӧ�������ļ�
	char * get_music(MUSIC_TYPE type);
	char * get_effect(EFFECT_TYPE type);
public:
	//�����Ĳ��ź���ͣ
	void play_effect(EFFECT_TYPE type);
	void play_bg_music(MUSIC_TYPE type);
	void pause_bg_music();
};


#endif // !__SOUND_H__
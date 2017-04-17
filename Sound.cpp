#include "Sound.h"

Sound* Sound::m_sound = NULL;

Sound * Sound::getInstance()
{
	if (m_sound==NULL)
	{
		m_sound = new Sound();
	}
	return m_sound;
}

void Sound::freeInstance()
{
	if (m_sound!=NULL)
	{
		delete m_sound;
		m_sound = NULL;
	}
}

Sound::Sound()
{
	//预先加载音效
	auto audio = SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic(this->get_music(MUSIC_TYPE_BACKGROUND));
	audio->preloadEffect(this->get_effect(EFFECT_TYPE_ACHIEVE));
	audio->preloadEffect(this->get_effect(EFFECT_TYPE_DEATH));
	audio->setBackgroundMusicVolume(0.5);
}

//获取音效音乐文件
char * Sound::get_music(MUSIC_TYPE type)
{
	switch (type)
	{
	case MUSIC_TYPE_BACKGROUND:
		return "sound/game_music.mp3";
		break;
	default:
		break;
	}
	return NULL;
}

char * Sound::get_effect(EFFECT_TYPE type)
{
	switch (type)
	{
	case EFFECT_TYPE_DEATH:
		return "sound/death.wav";
		break;
	case EFFECT_TYPE_ACHIEVE:
		return "sound/achieve.mp3";
		break;
	default:
		break;
	}
	return NULL;
}

void Sound::play_effect(EFFECT_TYPE type)
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect(this->get_effect(type));

}

void Sound::play_bg_music(MUSIC_TYPE type)
{
	auto audio = SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying()) {
		audio->playBackgroundMusic(this->get_music(type), true);
	}
	else
	{
		//恢复播放
		audio->pauseBackgroundMusic();
	}
}


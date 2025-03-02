#pragma once
#include"AudioEngine.h"
#include"CCUserDefault.h"
USING_NS_CC;
//初始化声音数据，即背景音乐+音效均为打开
static void init_sound() {
	UserDefault::getInstance()->setIntegerForKey("sound_effect", 1);
	UserDefault::getInstance()->setIntegerForKey("bg_music", 1);
}
//播放按钮音效
static void button_sound_effect() {
	//若音效打开，则播放按钮音效
	if (UserDefault::getInstance()->getIntegerForKey("sound_effect") == 1) {
		AudioEngine::play2d("/sound/button.mp3", false, 0.5f);
	}
}
//播放翻页音效
static void page_sound_effect() {
	if (UserDefault::getInstance()->getIntegerForKey("sound_effect") == 1) {
		//若音效打开，则播放翻页音效
		AudioEngine::play2d("/sound/page.mp3", false, 0.2f);
	}
}
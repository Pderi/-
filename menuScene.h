#pragma once
#include "scene.h"
struct menuScene
{
	struct scene super;
	IMAGE* bk;//背景图片
	RECT rectStartGame, rectEndGame;//开始游戏区域和结束游戏区域
	bool isStartGameHover, isEndGameHover;//鼠标是否悬停在游戏开始或结束按钮上
	bool isQuit;//场景是否退出
};
void menuSceneInit(struct menuScene* s);
void menuSceneDestroy(struct menuScene* s);
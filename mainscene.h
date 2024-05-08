#pragma once
#include "scene.h"
#include "background.h"
#include "hero.h"
#include "vector.h"
#include "bullet.h"
#include "enemy0.h"
#include "enemy1.h"
#include "enemy2.h"
#include <stdbool.h>
#include <stdio.h>
struct mainScene
{
	struct scene super;
	hero* hero;
	background* bk;
	vector vecElements;//存储出现在场景中的元素
	vector vecBullets;//存储子弹
	int bulletGenCnt;//子弹产生计数器
	vector vecEnemy;//存储出现在场景中的敌机
	bool isTrackOn;
	int mark;//记录当前玩家获得的分数
};
void mainSceneInit(struct mainScene* s);
void mainSceneDestroy(struct mainScene* s);
void mainSceneDraw(struct mainScene* s);
void mainSceneUpdate(struct mainScene* s);
void mainSceneControl(struct mainScene* s, ExMessage* msg);
bool mainSceneIsQuit(struct mainScene* s);
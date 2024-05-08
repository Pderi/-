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
	vector vecElements;//�洢�����ڳ����е�Ԫ��
	vector vecBullets;//�洢�ӵ�
	int bulletGenCnt;//�ӵ�����������
	vector vecEnemy;//�洢�����ڳ����еĵл�
	bool isTrackOn;
	int mark;//��¼��ǰ��һ�õķ���
};
void mainSceneInit(struct mainScene* s);
void mainSceneDestroy(struct mainScene* s);
void mainSceneDraw(struct mainScene* s);
void mainSceneUpdate(struct mainScene* s);
void mainSceneControl(struct mainScene* s, ExMessage* msg);
bool mainSceneIsQuit(struct mainScene* s);
#pragma once
#include "scene.h"
struct menuScene
{
	struct scene super;
	IMAGE* bk;//����ͼƬ
	RECT rectStartGame, rectEndGame;//��ʼ��Ϸ����ͽ�����Ϸ����
	bool isStartGameHover, isEndGameHover;//����Ƿ���ͣ����Ϸ��ʼ�������ť��
	bool isQuit;//�����Ƿ��˳�
};
void menuSceneInit(struct menuScene* s);
void menuSceneDestroy(struct menuScene* s);
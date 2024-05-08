#pragma once
#include "sprite.h"
#include <easyx.h>
enum enemyType
{
	enemyType0,
	enemyType1,
	enemyType2
};
enum enemyStatus
{
	enemy_normal1,//����״̬
	//��ը0����ը5��״̬
	enemy_down0,
	enemy_down1,
	enemy_down2,
	enemy_down3,
	//С�л����ел�:0-3,��л�:0-5
	enemy_down4,
	enemy_down5,
	enemy_destroy//�л�����״̬
};
struct enemy//�л���������С�д���̳�����
{
	struct sprite super;
	void (*hited)(struct enemy*);//�л������к�Ĵ���
	void (*destroy)(struct enemy*);//���ٵл�
	IMAGE** imgArrEnemy;
	IMAGE** imgArrEnemyMask;
	enum enemyType enemyType;
	int v;//�л��ƶ��ٶ�
	int life;//�л�����ֵ
	int enemyDownCnt;//��ը״̬�������������ۼӣ������л�״̬�ٶ�
	int status;//�л�״̬
	int lastStatusBeforeDestroy;//����ǰ�����һ��״̬
};
void enemyInit(struct enemy*);
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
	enemy_normal1,//正常状态
	//爆炸0到爆炸5的状态
	enemy_down0,
	enemy_down1,
	enemy_down2,
	enemy_down3,
	//小敌机和中敌机:0-3,大敌机:0-5
	enemy_down4,
	enemy_down5,
	enemy_destroy//敌机销毁状态
};
struct enemy//敌机基础对象，小中大均继承于它
{
	struct sprite super;
	void (*hited)(struct enemy*);//敌机被击中后的处理
	void (*destroy)(struct enemy*);//销毁敌机
	IMAGE** imgArrEnemy;
	IMAGE** imgArrEnemyMask;
	enum enemyType enemyType;
	int v;//敌机移动速度
	int life;//敌机生命值
	int enemyDownCnt;//爆炸状态计数器，用于累加，减缓切换状态速度
	int status;//敌机状态
	int lastStatusBeforeDestroy;//销毁前的最后一个状态
};
void enemyInit(struct enemy*);
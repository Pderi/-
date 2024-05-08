#include <stdio.h>
#include "enemy1.h"
void enemy1Init(struct enemy1* e)
{
	enemyInit((struct enemy*)e);//初始化共性方法
	e->super.destroy = (void(*)(struct enemy*))enemy1Destroy;
	e->super.super.width = 46;
	e->super.super.height = 59;
	e->super.enemyType = enemyType1;//设置为中敌机类型
	e->super.life = 3;
	e->super.lastStatusBeforeDestroy = enemy_down3;
	e->super.imgArrEnemy = (IMAGE**)malloc(sizeof(IMAGE*) * 5);
	e->super.imgArrEnemyMask = (IMAGE**)malloc(sizeof(IMAGE*) * 5);
	for (int i = 0; i < 5; i++)
	{
		e->super.imgArrEnemy[i] = new IMAGE;
		e->super.imgArrEnemyMask[i] = new IMAGE;
	}
	//加载正常状态下的图片和掩码
	loadimage(e->super.imgArrEnemy[0], "img/enemy1/enemy1.png");
	loadimage(e->super.imgArrEnemyMask[0], "img/enemy1/enemy1_mask.png");
	char imgPath[50];
	char imgMaskPath[50];
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(imgPath, "img/enemy1/enemy1_down%d.png", i);
		sprintf_s(imgMaskPath, "img/enemy1/enemy1_down%d_mask.png", i);
		loadimage(e->super.imgArrEnemy[i + 1], imgPath);
		loadimage(e->super.imgArrEnemyMask[i + 1], imgMaskPath);
	}
}
void enemy1Destroy(struct enemy1* e)
{
	for (int i = 0; i < 5; i++)
	{
		delete e->super.imgArrEnemy[i];
		delete e->super.imgArrEnemyMask[i];
	}
	free(e->super.imgArrEnemy);
	free(e->super.imgArrEnemyMask);
}
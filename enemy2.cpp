#include <stdio.h>
#include "enemy2.h"
void enemy2Init(struct enemy2* e)
{
	enemyInit((struct enemy*)e);//初始化共性方法
	e->super.destroy = (void(*)(struct enemy*))enemy2Destroy;
	e->super.super.width = 109;
	e->super.super.height = 162;
	e->super.enemyType = enemyType2;//设置为大敌机类型
	e->super.life = 5;
	e->super.lastStatusBeforeDestroy = enemy_down5;
	e->super.imgArrEnemy = (IMAGE**)malloc(sizeof(IMAGE*) * 7);
	e->super.imgArrEnemyMask = (IMAGE**)malloc(sizeof(IMAGE*) * 7);
	for (int i = 0; i < 7; i++)
	{
		e->super.imgArrEnemy[i] = new IMAGE;
		e->super.imgArrEnemyMask[i] = new IMAGE;
	}
	//加载正常状态下的图片和掩码
	loadimage(e->super.imgArrEnemy[0], "img/enemy2/enemy2.png");
	loadimage(e->super.imgArrEnemyMask[0], "img/enemy2/enemy2_mask.png");
	char imgPath[50];
	char imgMaskPath[50];
	for (int i = 0; i < 6; i++)
	{
		sprintf_s(imgPath, "img/enemy2/enemy2_down%d.png", i);
		sprintf_s(imgMaskPath, "img/enemy2/enemy2_down%d_mask.png", i);
		loadimage(e->super.imgArrEnemy[i + 1], imgPath);
		loadimage(e->super.imgArrEnemyMask[i + 1], imgMaskPath);
	}
}
void enemy2Destroy(struct enemy2* e)
{
	for (int i = 0; i < 7; i++)
	{
		delete e->super.imgArrEnemy[i];
		delete e->super.imgArrEnemyMask[i];
	}
	free(e->super.imgArrEnemy);
	free(e->super.imgArrEnemyMask);
}
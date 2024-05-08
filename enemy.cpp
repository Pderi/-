#include "enemy.h"
#include "image.h"
static enum enemyStatus enemyStatusSequence[8] =
{
	enemy_normal1,
	enemy_down0,
	enemy_down1,
	enemy_down2,
	enemy_down3,
	enemy_down4,
	enemy_down5,
	enemy_destroy
};
void enemyDraw(struct enemy* e)
{
	IMAGE* imgEnemy = e->imgArrEnemy[e->status];
	IMAGE* imgEnemyMask = e->imgArrEnemyMask[e->status];//���ݵл���״̬ѡ���Ӧ��ͼƬ
	putTransparentImage(e->super.x, e->super.y, imgEnemyMask, imgEnemy);
}
void enemyUpdate(struct enemy* e)
{
	e->super.y += e->v;
	if (e->life == 0)
	{
		e->enemyDownCnt++;//�����ۼӣ������л�״̬�ٶ�
		if (e->enemyDownCnt >= 15)
		{
			e->enemyDownCnt = 0;
			if (e->status < e->lastStatusBeforeDestroy)//�жϵ�ǰ״̬�Ƿ�������ǰ�����һ��״̬
				e->status = enemyStatusSequence[e->status + 1];//�л�Ϊ��ǰ״̬�ĺ�һ��״̬
			else
				e->status = enemy_destroy;
		}
	}
}
void enemyHited(struct enemy* e)//���ел�������ֵ�ۼ�
{
	e->life--;
	if (e->life == 0)
		e->status = enemy_down0;
}
void enemyInit(struct enemy* e)
{
	e->super.draw = (void(*)(struct sprite*))enemyDraw;
	e->super.updata = (void(*)(struct sprite*))enemyUpdate;
	e->hited = (void(*)(struct enemy*))enemyHited;
	e->enemyDownCnt = 0;
	e->status = enemy_normal1;
	int m = 1;
	int n = 3;
	e->v = rand() % (n - m + 1) + m;
}
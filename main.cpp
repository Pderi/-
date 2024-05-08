#include "gameloop.h"
#include"mainscene.h"
#include "menuScene.h"
#include <stdio.h>
#include <time.h>
int main(void)
{
	srand(time(0));
	initgraph(422, 750);
	setbkcolor(WHITE);
	cleardevice();
	while (1)
	{
		menuScene menuscene;
		menuSceneInit(&menuscene);
		gameLoop((scene*)&menuscene, 60);
		menuSceneDestroy(&menuscene);
		mainScene mainscene;
		mainSceneInit(&mainscene);
		gameLoop((scene*)&mainscene, 60);
		mainSceneDestroy(&mainscene);
		//显示游戏结束和累计得分
		settextcolor(WHITE);
		settextstyle(100, 0, "微软雅黑");
		const char* pStr = "游戏结束";
		RECT r = { 0,200,422,300 };
		drawtext(pStr, &r, DT_CENTER);
		char buff[10];
		sprintf_s(buff, "得分:%d", mainscene.mark);
		r = { 0,300,422,400 };
		drawtext(buff, &r, DT_CENTER);
		Sleep(3000);
	}
	closegraph();
	return 0;
}
#include "gameloop.h"
#include "sprite.h"
#include <easyx.h>
void gameLoop(scene* s, int fps)
{
	timeBeginPeriod(1);
	LARGE_INTEGER startCount, endCount, F;
	QueryPerformanceFrequency(&F);
	BeginBatchDraw();
	while (1)
	{
		QueryPerformanceCounter(&startCount);
		cleardevice();
		s->draw(s);
		s->update(s);
		if (s->isQuit(s))
			break;
		QueryPerformanceCounter(&endCount);
		long long elapse = (endCount.QuadPart - startCount.QuadPart) * 1000000/ F.QuadPart;
		while (elapse < 1000000 / fps)
		{
			Sleep(1);
			ExMessage msg;
			bool isOk = peekmessage(&msg, EX_MOUSE);
			if (isOk == true)
			{
				s->control(s, &msg);//调用场景对象中的control方法处理鼠标消息
			}
			QueryPerformanceCounter(&endCount);
			elapse= (endCount.QuadPart - startCount.QuadPart)  * 1000000 / F.QuadPart;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	timeEndPeriod(1);
}
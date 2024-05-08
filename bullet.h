#pragma once
#include "sprite.h"
#include <easyx.h>
struct bullet
{
	struct sprite super;
	IMAGE* imgBullet;
	IMAGE* imgBulletMask;
};
void bulletInit(struct bullet*);
void bulletDestroy(struct bullet*);
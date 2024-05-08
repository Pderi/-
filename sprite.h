#pragma once
struct sprite
{
	void (*draw)(sprite*);
	void (*updata)(sprite*);
	int x;
	int y;
	int width;
	int height;
};
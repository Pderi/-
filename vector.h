#pragma once
#define VECTOR_INIT_CAPACITY 1
struct vector
{
	bool (*append)(struct vector* pvec, void* data);//添加数据
	void* (*get)(struct vector* pvec, int index);//获取数据
	void (*clear)(struct vector* pevc);//清除所有数据
	void (*remove)(struct vector* pvec, int index);//删除某个数据
	void** pData;//记录数组的首元素指针
	int size;//为数组盛放的数据的长度
	int capacity;//数组的容量
};
void vectorInit(struct vector* pvec);
void* vectorGet(struct vector* pvec, int index);
bool vectorAppend(struct vector* pvec, void* data);
void vectorClear(struct vector* pvec);
void vectorRemove(struct vector* pvec, int index);
void vectorDestroy(struct vector* pvec);
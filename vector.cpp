#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define VECTOR_INIT_CAPACITY 1
void vectorInit(struct vector* pvec)//vector对象的初始化
{
	pvec->get = vectorGet;
	pvec->append = vectorAppend;
	pvec->remove = vectorRemove;
	pvec->clear = vectorClear;
	pvec->pData = (void**)malloc(sizeof(void*) * VECTOR_INIT_CAPACITY);
	pvec->size = 0;
	pvec->capacity = VECTOR_INIT_CAPACITY;
}
bool vectorAppend(struct vector* pvec, void* data)
{
	if (pvec == NULL || data == NULL)
		return false;
	if (pvec->size >= pvec->capacity)//检查数组是否被装满
	{
		void** newData = (void**)realloc(pvec->pData, pvec->capacity * sizeof(void*) * 2);//使用realloc增长为原来的两倍
		if (newData == NULL)
		{
			return false;
		}
		pvec->pData = newData;
		pvec->capacity = 2 * pvec->capacity;
	}
	pvec->pData[pvec->size] = data;
	pvec->size++;
	return true;
}
void* vectorGet(struct vector* pvec, int index)
{
	if (index >= pvec->size)
		return NULL;
	return pvec->pData[index];
}
void vectorRemove(struct vector* pvec, int index)
{
	for (int i = index; i < pvec->size - 1; i++)
		pvec->pData[i] = pvec->pData[i + 1];
	pvec->size -= 1;
}
void vectorClear(struct vector* pvec)
{
	if (pvec->pData != NULL)
		free(pvec->pData);
	pvec->pData = (void**)malloc(sizeof(void*) * VECTOR_INIT_CAPACITY);
	pvec->size = 0;
	pvec->capacity = VECTOR_INIT_CAPACITY;
}
void vectorDestroy(struct vector* pvec)//销毁数组
{
	if (pvec->pData == NULL)
		return;
	free(pvec->pData);
	pvec->pData = NULL;
	pvec->size = 0;
	pvec->capacity = 0;
}
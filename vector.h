#pragma once
#define VECTOR_INIT_CAPACITY 1
struct vector
{
	bool (*append)(struct vector* pvec, void* data);//�������
	void* (*get)(struct vector* pvec, int index);//��ȡ����
	void (*clear)(struct vector* pevc);//�����������
	void (*remove)(struct vector* pvec, int index);//ɾ��ĳ������
	void** pData;//��¼�������Ԫ��ָ��
	int size;//Ϊ����ʢ�ŵ����ݵĳ���
	int capacity;//���������
};
void vectorInit(struct vector* pvec);
void* vectorGet(struct vector* pvec, int index);
bool vectorAppend(struct vector* pvec, void* data);
void vectorClear(struct vector* pvec);
void vectorRemove(struct vector* pvec, int index);
void vectorDestroy(struct vector* pvec);
#pragma once
#include "rawdecode.h"

typedef IMUdata Elemtype;

typedef struct Node
{
	Elemtype imudata;
	struct Node *next;          // ��ʽ�����н��Ԫ�ص�ָ��
} QNode, *QueuePtr;

typedef struct                   //�۲�ֵ����
{
	QueuePtr front;             // ����ͷָ��
	QueuePtr rear;              // ����βָ��
} LinkQueue;

bool InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
bool QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
bool GetHead(LinkQueue Q, Elemtype *e);
void QueueTraverse(LinkQueue QO, void(*fp)(Elemtype));
void ClearQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, Elemtype e);
bool DeQueue(LinkQueue *Q, Elemtype *e);
#include <stdlib.h>
#include "queue.h"

//��ʼ������
bool InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (Q->front == NULL)
		return false;
	Q->front->next = NULL;
	return true;
}

//���ٶ���
void DestroyQueue(LinkQueue *Q)
{
	//	assert(QO != NULL);
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

//��ն���
bool QueueEmpty(LinkQueue Q)
{
	//	assert(QO.front != NULL && QO.rear != NULL);
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

//��ö��г���
int QueueLength(LinkQueue Q)
{
	//	assert(QO.front != NULL);
	QueuePtr p = Q.front;
	int Length = 0;
	while (p != Q.rear)
	{
		Length++;
		p = p->next;
	}
	return Length;
}

//��ȡ������Ԫ��
bool GetHead(LinkQueue Q, Elemtype *e)
{
	//	assert(QO.front != NULL);
	if (QueueEmpty(Q))
		return false;
	else
	{
		*e = Q.front->next->imudata;
		return true;
	}

}

//��������
void QueueTraverse(LinkQueue QO, void(*fp)(Elemtype))
{
	//	assert(QO.front != NULL);
	QueuePtr p = QO.front->next;
	while (p)
	{
		(*fp)(p->imudata);
		p = p->next;
	}
}

//��ն���
void ClearQueue(LinkQueue *Q)
{
	//	assert(QO->front != NULL);
	QueuePtr p = Q->front->next;
	while (p)
	{
		Q->front->next = p->next;
		free(p);
		p = Q->front->next;
	}
}

//�ڶ���ĩ����Ԫ��
bool EnQueue(LinkQueue *Q, Elemtype e)
{
	QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
	if (!temp)
		return false;
	temp->imudata = e;
	temp->next = NULL;
	Q->rear->next = temp;
	Q->rear = temp;
	return true;
}

//ɾ������ͷ�ڵ�
bool DeQueue(LinkQueue *Q, Elemtype *e)
{
	if (Q->front == Q->rear)
		return false;
	QueuePtr temp = Q->front->next;
	*e = temp->imudata;
	Q->front->next = temp->next;
	if (Q->rear == temp)
		Q->rear = Q->front;
	free(temp);
	return true;
}
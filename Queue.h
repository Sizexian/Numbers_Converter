#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED



#endif // QUEUE_H_INCLUDED

typedef struct QNode
{
    int data;
    int last;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue *q)//创建队列
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!q->front)
    {
        printf("Init Malloc ERROR!\n");
        exit(-1);
    }
    q->front->next=NULL;
//    printf("Init Malloc Success!\n");
}

void EnQueue(LinkQueue *q,int i,int last)//元素入队
{
    QNode *p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)
    {
        printf("EnQueue Malloc ERROR!\n");
        exit(-1);
    }
    p->data=i;
    p->last=last;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
//    printf("\"%d\"EnQueue Success! %d\n",i,q->rear->last);
}

void DeQueue(LinkQueue *q,int *i,int *last)//元素出队
{
    if(q->front==q->rear)
    {
        printf("Empty Queue!\n");
        exit(-1);
    }
    QNode *p;
    p=q->front->next;
    *i=p->data;
    *last=p->last;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
//    printf("\"%d\"DeQueue Success!\n",*i);
}

void DelZero(LinkQueue *q)
{
    int i,last;
    while(q->front->next->data==0&&q->front->next->next!=NULL)
    {
        DeQueue(q,&i,&last);
    }
}

/*void ReadQueue(LinkQueue *q)//读取队列
{
    QNode *p;
    p=q->front->next;
    while(p->last!=1)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}*/

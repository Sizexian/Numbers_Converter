#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED



#endif // STACK_H_INCLUDED

typedef struct LinkStack
{
    char data;
    struct LinkStack *next;
}LinkStack;

void InitStack(LinkStack *s)//初始化栈
{
    s=(LinkStack*)malloc(sizeof(LinkStack));
    if(!s)
    {
        printf("Stack Malloc Error!\n");
        exit(-1);
    }
    s->next=NULL;
//    printf("Stack Malloc Success!\n");
}

void Push(LinkStack *s,char c)//元素入栈
{
    LinkStack *p;
    p=(LinkStack*)malloc(sizeof(LinkStack));
    if(!p)
    {
        printf("Malloc ERROR!\n");
        exit(-1);
    }
    p->data=c;
    p->next=s->next;
    s->next=p;
}

void Pop(LinkStack *s,char c)//元素出栈
{
    LinkStack *p;
    if(s->next==NULL)
    {
        printf("Empty Stack!\n");
        exit(-1);
    }
    p=s->next;
    s->next=p->next;
    c=p->data;
    free(p);
}

void ReadStack(LinkStack *s)//读取栈元素
{
    LinkStack *p;
    p=s->next;
    while(p->next!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("%c",p->data);
}

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED



#endif // LIST_H_INCLUDED

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
    char* data;
    int length;
    int listsize;
}SqList;

void InitList(SqList *l)//初始化顺序表
{
    l->data=(char*)malloc(sizeof(char)*LIST_INIT_SIZE);
    if(!l->data)
    {
        printf("Malloc ERROR!\n");
        exit(-1);
    }
    l->length=0;
    l->listsize=LIST_INIT_SIZE;
//    printf("Init Success!\n");
}

void ListInsert(SqList *l,char c)//顺序表插入
{
    if(l->length>=l->listsize)
    {
        char *newbase;
        newbase=(char*)realloc(l->data,(l->listsize+LISTINCREMENT)*sizeof(char));
        if(!newbase)
        {
            printf("Realloc ERROR!\n");
            exit(-1);
        }
        l->data=newbase;
        l->listsize+=LISTINCREMENT;
    }
    char* p;
    p=&(l->data[l->length]);
    *p=c;
    l->length++;
//    printf("%c into List!",c);
}

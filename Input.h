#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED

void InputData(SqList *l)
{
    char c;
    InitList(l);
    c=getchar();
    while(c!=10)
    {
        if(c>'9'||c<'0')
        {
            printf("Illegal input!\n");
            exit(-1);
        }
        ListInsert(l,c);
        c=getchar();
    }
    ListInsert(l,'\0');
}

int End(char c)
{
   if(c=='\0')
    return 1;
   else
    return 0;
}

void DatatoQueue(SqList *l,LinkQueue *q)
{
    int i;
    for(i=0;l->data[i]!='\0';i++)
    {
        EnQueue(q,l->data[i]-'0',End(l->data[i+1]));
    }
}

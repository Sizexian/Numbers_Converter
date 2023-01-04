#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Input.h"

char* base="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";//进制数62位

int main()
{
    printf("program running!\n");
    printf("Input data:");
    SqList l;
    InputData(&l);
    int conv,num,last,temp,inQueue,remain=0;//转换为conv进制，num为队列新取出数，last负责判断数值是否处理完，temp负责处理余数并将最后一位入栈，inQueue是要放入队列的数据，remain负责记录上一次运算的余数
//    char* testData="10000000000000000001";//测试用数据
    LinkQueue q;
    InitQueue(&q);
    LinkStack s;
    InitStack(&s);
    DatatoQueue(&l,&q);
/*    for(int i=0;i<20;i++)
    {
        EnQueue(&q,testData[i]-'0',End(testData[i+1]));
    }*/
    printf("Convert to (2-62):");
    scanf(" %d",&conv);//转换为conv进制
    if(conv>62||conv<2)
    {
        printf("Invaild Number!\n");
        exit(-1);
    }
    while(q.front->next->data!=0||q.front->next->next!=NULL)//在链表仅剩一块且该块值为零时结束
    {
        remain=0;
        while(q.front->next->last!=1)//判断数值是否处理完
        {
            DeQueue(&q,&num,&last);
            temp=(num+remain)%conv;
            inQueue=(num+remain)/conv;
            EnQueue(&q,inQueue,last);
            if(temp!=0)
            {
                remain=temp*10;
            }
            else
            {
                remain=0;
            }
        }
        DeQueue(&q,&num,&last);
        temp=(num+remain)%conv;
        inQueue=(num+remain)/conv;
        EnQueue(&q,inQueue,last);
        Push(&s,base[temp]);
        DelZero(&q);
//        ReadQueue(&q);//Test
    }
    printf("Output data:");
    ReadStack(&s);//Test
    return 0;
}

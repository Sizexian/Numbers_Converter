#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Input.h"

char* base="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";//������62λ

int main()
{
    printf("program running!\n");
    printf("Input data:");
    SqList l;
    InputData(&l);
    int conv,num,last,temp,inQueue,remain=0;//ת��Ϊconv���ƣ�numΪ������ȡ������last�����ж���ֵ�Ƿ����꣬temp�����������������һλ��ջ��inQueue��Ҫ������е����ݣ�remain�����¼��һ�����������
//    char* testData="10000000000000000001";//����������
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
    scanf(" %d",&conv);//ת��Ϊconv����
    if(conv>62||conv<2)
    {
        printf("Invaild Number!\n");
        exit(-1);
    }
    while(q.front->next->data!=0||q.front->next->next!=NULL)//�������ʣһ���Ҹÿ�ֵΪ��ʱ����
    {
        remain=0;
        while(q.front->next->last!=1)//�ж���ֵ�Ƿ�����
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

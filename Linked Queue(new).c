#include<stdio.h>
#include<stdlib.h>

#define ElemType int
#define OK 1
#define FALSE 0

struct Queue
{
    ElemType SN;
    struct Queue *next;
};

typedef struct Queue Q;

typedef struct
{
    Q *front;
    Q *rear;
} LinkQueue;

typedef LinkQueue LQ;

int InitQueue(LQ *L)      //传入结构体指针，构造空队列，头结点置空
{
    L->front=(Q *)malloc(sizeof(Q));
    L->rear=L->front;
    if(L->front==NULL) return FALSE;
    L->front->next=NULL;     //头结点的指针域置空
    return OK;
}

void PrintQueue(LQ L)
{
    Q *p;
    for(p=L.front;p!=L.rear;p=p->next)
        printf("%d",p->SN);
    printf("\n");
}

int main()
{
    int i=1;
    char c;
    LQ L;
    LQ *l=&L;
    printf("%d\n",InitQueue(l));
    PrintQueue(L);
    /* do
    {
        PrintQueue(L);
        printf("a.增加任务\te.结束任务\to.退出\n");
        printf("请选择：#");
        c=getchar();
        switch(c)
        {
            case 'a':
                InsertQueue(L,i);
                i++;
                break;
            case 'e':
                if(DeQueue(L)) printf("出队成功！\n");
                else printf("失败！\n");
                break;
            case 'o':
                break;
            default:
                break;
        }
    }while(c=='o'); */
    system("pause");
    return 0;
}
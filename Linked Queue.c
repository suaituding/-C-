#include<stdio.h>
#include<stdlib.h>

#define ElemType int
#define FALSE 0
#define OK 1

struct Queue
{
    ElemType SN;        //任务编号
    struct Queue *next;
};

typedef struct Queue Q;

typedef struct
{
    struct Queue *front;
    struct Queue *rear;
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

void InsertQueue(LQ *L,ElemType data)      //入队
{
    Q *p;
    p=(Q *)malloc(sizeof(Q));
    p->SN=data;
    p->next=NULL;
    L->rear->next=p;
    L->rear=p;
}

int DeQueue(LQ *L)      //出队
{
    if(L->front==L->rear) return FALSE;
    Q *p;
    p=L->front->next;
    L->front->next=p->next;
    free(p);
    return OK;
}

void PrintQueue(LQ L)
{
    Q *p=L.front;
    for(p=p->next;p!=L.rear->next&&p!=NULL;p=p->next)
        printf("\t%d\n",p->SN);
    printf("\n");
}

int main()
{
    int i=1;
    char c;
    LQ L;
    LQ *l=&L;
    printf("%d\n",InitQueue(l));
    do
    {
        PrintQueue(L);
        printf("a.增加任务\te.结束任务\to.退出\n");
        printf("请选择：#");
        c=getchar();
        getchar();
        switch(c)
        {
            case 'a':
                InsertQueue(l,i);
                i++;
                break;
            case 'e':
                if(DeQueue(l)) printf("出队成功！\n");
                else printf("失败！\n");
                break;
            case 'o':
                break;
            default:
                break;
        }
    }while(c!='o');
    return 0;
}
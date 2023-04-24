#include<stdio.h>
#include<stdlib.h>

#define Elemtype int
#define FALSE 0
#define OK 1
#define maxsize 5

typedef struct
{
    int conter;     //计数器
    Elemtype *base; //基地址
    int front;      //头指针
    int reat;       //尾指针
} Queue;

typedef Queue Q;

int InitQueue(Q *q)     //初始化
{
    q->base=(Elemtype *)malloc(sizeof(Elemtype)*maxsize);
    if(q->base==NULL) return FALSE;
    q->front=q->reat=q->conter=0;
    return OK;
}

void ClearQueue(Q *q)        //清空队列
{
    q->front=q->reat=q->conter=0;
}

void InsertQueue(Q *q)      //入队列
{
    char i;
    printf("请输入（最多%d个数）：",maxsize-1);
    while(i!='\n')    //浪费一个空间解决空满二义性
    {
        scanf("%d",&q->base[q->reat]);
        if((q->reat+1)%maxsize==q->front)
        break;
        q->reat=(q->reat+1)%maxsize;
        i=getchar();
    }
    /* while(i!='\n')         //计数器解决空满二义性
    {
        scanf("%d",q->base[q->reat]);
        q->reat=(q->reat+1)%maxsize;
        if(q->conter==maxsize)
        break;
        q->conter++;
        i=getchar();
    } */
}

void PushQueue(Q *q)        //出队列
{
    char i;
    while(q->reat!=q->front||q->conter!=0)
    {
        i=getchar();
        printf("元素%d已出队",q->base[q->front]);
        q->front=(q->front+1)%maxsize;
        // q->conter--;
        printf("是否继续\ty.是\tn.否\t#");
        i=getchar();
        if(i=='n') break;
    }
}

void Destrony(Q *q)     //销毁队列
{
    free(q->base);
}

void PrintQueue(Q *q)
{
    int i;
    for(i=q->front;i!=q->reat;i=(i+1)%maxsize)
    printf("%d\t",q->base[i]);
    printf("\n");
}

int main()
{
    char i;
    Q q;
    printf("%d\n",InitQueue(&q));
    do
    {
        star:
        PrintQueue(&q);
        printf("i.入队\tp.出队\tc.清空\td.删除\to.退出\n");
        printf("请选择：#");
        i=getchar();
        switch(i)
        {
            case 'i':
                InsertQueue(&q);
                goto star;
            case 'p':
                PushQueue(&q);
                break;
            case 'c':
                ClearQueue(&q);
                break;
            case 'd':
                Destrony(&q);
                break;
            case 'o':
                break;
            default:
                break;
        }
        while(getchar()!='\n')
        {;}
    }while(i!='o');
    return 0;
}
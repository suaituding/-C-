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

int InitQueue(LQ *L)      //����ṹ��ָ�룬����ն��У�ͷ����ÿ�
{
    L->front=(Q *)malloc(sizeof(Q));
    L->rear=L->front;
    if(L->front==NULL) return FALSE;
    L->front->next=NULL;     //ͷ����ָ�����ÿ�
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
        printf("a.��������\te.��������\to.�˳�\n");
        printf("��ѡ��#");
        c=getchar();
        switch(c)
        {
            case 'a':
                InsertQueue(L,i);
                i++;
                break;
            case 'e':
                if(DeQueue(L)) printf("���ӳɹ���\n");
                else printf("ʧ�ܣ�\n");
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
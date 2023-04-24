#include<stdio.h>
#include<stdlib.h>

#define Elemtype int
#define FALSE 0
#define OK 1
#define maxsize 5

typedef struct
{
    int conter;     //������
    Elemtype *base; //����ַ
    int front;      //ͷָ��
    int reat;       //βָ��
} Queue;

typedef Queue Q;

int InitQueue(Q *q)     //��ʼ��
{
    q->base=(Elemtype *)malloc(sizeof(Elemtype)*maxsize);
    if(q->base==NULL) return FALSE;
    q->front=q->reat=q->conter=0;
    return OK;
}

void ClearQueue(Q *q)        //��ն���
{
    q->front=q->reat=q->conter=0;
}

void InsertQueue(Q *q)      //�����
{
    char i;
    printf("�����루���%d��������",maxsize-1);
    while(i!='\n')    //�˷�һ���ռ�������������
    {
        scanf("%d",&q->base[q->reat]);
        if((q->reat+1)%maxsize==q->front)
        break;
        q->reat=(q->reat+1)%maxsize;
        i=getchar();
    }
    /* while(i!='\n')         //�������������������
    {
        scanf("%d",q->base[q->reat]);
        q->reat=(q->reat+1)%maxsize;
        if(q->conter==maxsize)
        break;
        q->conter++;
        i=getchar();
    } */
}

void PushQueue(Q *q)        //������
{
    char i;
    while(q->reat!=q->front||q->conter!=0)
    {
        i=getchar();
        printf("Ԫ��%d�ѳ���",q->base[q->front]);
        q->front=(q->front+1)%maxsize;
        // q->conter--;
        printf("�Ƿ����\ty.��\tn.��\t#");
        i=getchar();
        if(i=='n') break;
    }
}

void Destrony(Q *q)     //���ٶ���
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
        printf("i.���\tp.����\tc.���\td.ɾ��\to.�˳�\n");
        printf("��ѡ��#");
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
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define FALSE 0
#define ElemType int

typedef struct //����˳���
{  
    ElemType *elme;//����ַ
    int capacity;//�������
    int length;//��ǰ����
} Sqlist;

// typedef Sqlist l;

int Initlist(Sqlist *l,int max)//��ʼ��
{
    l->elme=(ElemType*)malloc(max*sizeof(ElemType));//��̬����ռ�
    l->length=0;
    l->capacity=max;
    if(!l->elme) return FALSE;
    else return OK;
}

void input(Sqlist *l)//��������
{
    int i;
    char s;
    printf("���������ݣ�");
    do
    {
        scanf("%d",&l->elme[l->length]);
        l->length++;
        s=getchar();
    }while(s!='\n');
}

void output(Sqlist *l)//�������
{
    int i;
    for(i=0;i<l->length;i++)
        printf("%d\t",l->elme[i]);
    printf("\n");
}

void ListInsert(Sqlist *l)//��������
{
    int i,j,t;
    star:
    printf("����λ�ã�");
    scanf("%d",&i);
    printf("�������ݣ�");
    scanf("%d",&j);
    if(i>0&&i-1<l->length&&(l->length)<(l->capacity))//ͷ�����룬�м����
    {
        
        for(t=l->length;t>i-1;t--)
            l->elme[t]=l->elme[t-1];
        l->elme[i-1]=j;
        l->length++;
        /* l->length++;
        for(i=l->length;i>0;i--)
            l->elme[i]=l->elme[i-1];
        l->elme[0]=j; */
    }
    else if(i-1==l->length)//β������
    {
        l->elme[l->length]=j;
        l->length++;
    }
    else goto star;//��Ч����
}

void ListDelete(Sqlist *l)//ɾ������
{
    int i,t;
    star:
    printf("ɾ��λ�ã�");
    scanf("%d",&i);
    if(i-1==l->length)//β��ɾ��
        l->length--;
    else if(i-1>l->length)//��Чɾ��
        goto star;
    else
    {
        for(t=i-1;t<l->length;t++)
            l->elme[t]=l->elme[t+1];
        l->length--;
    }
}

void ClearList(Sqlist *l)
{
    free(l->elme);
    l->capacity=0;
    l->elme=NULL;
    l->length=0;
}

int Memu(Sqlist *L)
{
    output(L);
    int i;
    choice:
    printf("1.����\t2.ɾ��\t3.���4.�˳�\n");
    printf("��ѡ���ܣ�");
    scanf("%d",&i);
    switch(i)
    {
        case 1:ListInsert(L);break;
        case 2:ListDelete(L);break;
        case 3:ClearList(L);break;
        case 4:break;
        default:printf("����\n");goto choice;
    }
    if(i==4) return 0;
    else return 1;
}

int main()
{
    int i,max;
    Sqlist L;
    printf("������󳤶ȣ�");
    scanf("%d",&max);
    printf("%d\n",Initlist(&L,max));
    input(&L);
    while(Memu(&L));
    // output(&L);
    return 0;
}
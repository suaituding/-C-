#include<stdio.h>
#include<stdlib.h>

#define maxsize 5       //��ʼ��������������ռ�
#define ElemType int    //�Զ���洢��������
#define OK 1
#define FALSE 0

typedef struct 
{
    ElemType *base;         //����ַ
    int capacity;           //���鳤��
    int length;             //���鵱ǰ����
} collection;

typedef collection C;

int Creat(C *c)     //��ʼ��������ռ�
{
    c->base=(ElemType*)malloc(maxsize*sizeof(ElemType));
    c->capacity=maxsize;
    c->length=0;
    if(c->base==NULL) return FALSE;
    else return OK;
}

int Dropbox(C *c,int size)     //�Զ������ӿռ�
{
    int i;
    ElemType *new;
    new=(ElemType*)malloc((size+c->capacity)*sizeof(ElemType));   //����һ�θ���Ŀռ�
    if(new==NULL) return FALSE;
    for(i=0;i<c->length;i++)        //��ԭ����Ԫ�ظ�������������
        new[i]=c->base[i];
    c->base=new;
    c->capacity+=size;
    free(new);
    return OK;
}

void Input(C *c)        //����Ԫ��
{
    char i;
    printf("������:(���%d����):",c->capacity);
    do
    {
        scanf("%d",&c->base[c->length]);
        c->length++;
        i=getchar();
    } while (i!='\n'&&c->length<=c->capacity);
    /* for(i=0;i<maxsize;i++,c)
        scanf("%d",&c->base[i]); */
}

void Output(C *c)       //���Ԫ��
{
    int i;
    for(i=0;i<c->length;i++)
        printf("%d\t",c->base[i]);
    printf("\n");
}

void Intersection(C *c1,C *c2)      //ȡ���������
{
    int i,j;
    printf("������");
    for(i=0;i<c2->length;i++)
    {
        for(j=0;j<c1->length;j++)
        {
            if(c1->base[i]==c2->base[j])
            printf("%d\t",c1->base[i]);
        }
    }
    printf("\n");
}

void Aggregate(C *c1,C *c2)     //ȡ���������
{
    int i,j;
    C c3;                       //���沢��
    c3.length=0;
    c3.capacity=0;
    if(Dropbox(&c3,c1->length+c2->length))
    {
        for(i=0;i<c1->length;i++)
            c3.base[i]=c1->base[i];
        c3.length=c1->length;
        for(i=0;i<c2->length;i++)
        {
            for(j=0;j<c3.length;j++)
            {
                if(c2->base[i]==c3.base[j])
                break;
            }
            if(j==c3.length)
            {
                c3.base[j]=c2->base[i];
                c3.length++;
            }
        }
        printf("������");
        for(i=0;i<c3.length;i++)
            printf("%d\t",c3.base[i]);
        printf("\n");
        /* if(c1->length>=c2->length)
        {
            for(i=0;i<c1->length;i++)
            {
                for(j=0;j<c1->length;j++)
                {
                    if(c1->base[i]==c2->base[j])
                    printf("%d\t",c1->base[i]);
                    else printf("");
                }
            }
        } */
    }
    else
    printf("ʧ��\n");
}

int main()
{
    C c1,c2;
    if(Creat(&c1)) printf("��ʼ���ɹ�\n");
    else printf("��ʼ��ʧ��\n");
    Input(&c1);
    if(Creat(&c2)) printf("��ʼ���ɹ�\n");
    else printf("��ʼ��ʧ��\n");
    Input(&c2);
    Output(&c1);
    Output(&c2);
    Intersection(&c1,&c2);
    Aggregate(&c1,&c2);
    return 0;
}
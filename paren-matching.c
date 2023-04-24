#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define FALSE 0
#define maxsize 5

typedef struct
{
    char *base;     //����ַ����̬�����׵�ַ
    int top;        //ջ��ָ��
    int sqtacksize; //ջ������
} leftparen;

typedef leftparen L;

int InitSqtack(L *l)    //��ʼ��
{
    l->base=(char *)malloc(maxsize*sizeof(char));
    if(l->base==NULL) return FALSE;
    l->top=-1;
    l->sqtacksize=maxsize;
    return OK;
}

int Expandspace(L *l,int i)    //��չi����С�Ŀռ�
{
    char *p;
    p=(char *)malloc((i+l->sqtacksize)*sizeof(char));
    if(p==NULL) return FALSE;
    l->sqtacksize+=i;
    l->base=p;
    free(p);
    return OK;
}

int judgement(L *l)
{
    int count;      //��������ʾȱʧ���ŵ�����
    printf("���������Ÿ�����");
    scanf("%d",&count);
    if(count>5) printf("%d",Expandspace(l,count-4));
    printf("�����룺");
    scanf("%s",l->base);
    while(*l->base!='\0')
    {
        if(*l->base!='('&&*l->base!=')')    return FALSE;
        if(*l->base=='(')    l->top++;
        else    l->top--;
        l->base++;
    }
    if(l->top==-1)
        printf("������ȫ��ƥ��\n");
    else if(l->top>-1)
        printf("ȱ��%d��������\n",(l->top)+1);
    else
        printf("ȱ��%d��������\n",-1-l->top);
    return OK;
}

int main()
{
    L l;
    printf("%d\n",InitSqtack(&l));
    printf("%d\n",judgement(&l));
    // system("pause");
    return 0;
}
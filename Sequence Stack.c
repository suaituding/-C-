#include<stdio.h>
#include<stdlib.h>

#define maxsize 100
#define SElemType int
#define OK 1
#define FALSE 0

typedef struct
{
    SElemType *base;    //ջ��ָ��
    SElemType *top;     //ջ��ָ��
    SElemType stacksize;        //ջ��ʣ������
} Sqtack;

int InitStack(Sqtack *S)        //��ʼ��������maxsize�Ŀռ�
{
    S->base=(SElemType*)malloc(maxsize*sizeof(SElemType));
    S->stacksize=maxsize;
    S->top=S->base;
    if(S->base==NULL) return FALSE;     //��ʼ�����󣬷���FALSE
    else return OK;
}

int StackPush(Sqtack *S)     //��ջ
{
    char i;
    printf("���������ݣ����س��������룩");
    do
    {
        if(S->stacksize==0) return FALSE;     //ջ��ʱ��������
        scanf("%d",S->top);
        i=getchar();
        S->top++;
        S->stacksize--;
    } while (i!='\n');
    return OK;
}

int StackPop(Sqtack *S)     //��ջ
{
    if(S->stacksize==maxsize) return FALSE;     //��ջʱ����FALSE
    else
    {
        S->top--;
        S->stacksize++;
        return OK;
    }
}

void StackDestroy(Sqtack *S)        //�ͷſռ䣬����ջ
{
    S->stacksize=maxsize;
    free(S->base);
}

void StackPrint(Sqtack *S)      //���ջ������Ԫ��
{
    SElemType *p=S->top;
    int i;
    printf("ջԪ��Ϊ��\n");
    for(i=maxsize-S->stacksize,p--;i>0;p--,i--)
        printf("\t%d\n",*p);
    /* while(p!=S->base)
    {
        p--;
        printf("\t%d\n",*p);
    } */
    printf("ջ��ʣ������Ϊ:%d",S->stacksize);
    printf("\n");
}

int main()
{
    Sqtack *S;
    char s,i;
    if(InitStack(S)) printf("��ʼ���ɹ�\n");
    else printf("��ʼ��ʧ��\n");
    do
    {
        StackPrint(S);
        printf("p.��ջ\to.��ջ\td.����ջ\te.�˳�\t�����룺");
        s=getchar();
        switch (s)
        {
            case 'p':
                if(StackPush(S)) printf("�ɹ�\n");
                else printf("ʧ�ܣ�ջ������\n");
                break;
            case 'o':
                if (StackPop(S)) printf("ջ��Ԫ��%d�ѳ�ջ\n",*S->top);
                else
                {
                    printf("ʧ�ܣ�ջΪ�գ�\n");
                    i=getchar();
                }
                break;
            case 'd':
                StackDestroy(S);
                printf("������\n");
                i=getchar();
                break;
            case 'e':
                s='e';
                break;
            default:
                printf("��������������\n");
                break;
        }
    } while (s!='e');
    return 0;
}
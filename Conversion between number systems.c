/*����ջ����ʮ�������������Ƶ�ת��
2����ʮ�����������õ�һ���̺�����������2ȥ���̣��ֻ�õ�һ���̺�������
����ظ���ֱ����ΪС��1ʱΪֹ��Ȼ����ȵõ�������Ϊ���������ĵ�λ��Чλ����õ���������Ϊ���������ĸ�λ
��Чλ���Դ�������������ʮ����100ת��Ϊ������Ϊ����
100/2=50��0��50/2=25��0��25/2=12��1��12/2=6��0��6/2=3��0��3/2=1��1���Դ�����ʮ���Ƶ�100ת���ɶ������ǣ�1100100��*/

#include<stdio.h>
#include<stdlib.h>

#define maxsize 10
#define OK 1
#define FALSE 0

typedef struct
{
    int *base;          //ջ��ָ��,���ٶ�̬������׵�ַ
    int top;            //ջ��ָ��
    int sqtacksize;      //ջ������
} Sqtack;

typedef Sqtack S;

int InitStack(S *s)             //��ʼ��
{
    s->base=(int*)malloc(maxsize*sizeof(int));
    s->top=-1;                      //ջ��ָ���ʾ��ǰջ��Ԫ���±꣬��ʱΪ-1
    s->sqtacksize=maxsize;
    if(s->base==NULL) return FALSE;
    return OK;
}

int Expandspace(S *s,int newsize)       //����ջ�Ŀռ�,newsizeΪ����Ŀռ�
{
    int *p;
    int i;
    p=(int*)malloc(newsize*sizeof(int));
    if(p==NULL) return FALSE;
    for(i=0;i<=s->top;i++)
        p[i]=s->base[i];
    s->base=p;
    s->sqtacksize+=newsize;
    free(p);
    return OK;
}

int Transform(S *s,int i,int ns)         //ʮ����ת��Ϊ�����ˣ�ʮ�����ƣ�iΪʮ��������nsΪת���Ľ���
{
    if(i<ns)
    {
        s->top++;
        s->base[s->top]=i;
    }
    else
    {
        while(i>ns)
        {
            if(s->top==s->sqtacksize) 
                if(!Expandspace(s,maxsize))    //ջ�ռ���������ռ�
                    return FALSE;               //�����¿ռ�ʧ�ܣ�����FALSE
            s->top++;
            s->base[s->top]=i%ns;               //ȡ������ջ
            i/=ns;                              //i�Գ�
        }
        s->top++;
        s->base[s->top]=i;              //����������
    }
    return OK;
}

void Printf(S *s)
{
    int i;
    for(i=s->top;i>=0;i--)      //��ջ��10~15��A~E���棬����ʮ������
    {
        if(s->base[i]<10)
            printf("%d",s->base[i]);
        else
            printf("%c",s->base[i]+55);     //����ASCII�������Ӧ�ַ�
        /* switch(s->base[i])       //������
        {
            case 10:printf("A");break;
            case 11:printf("B");break;
            case 12:printf("C");break;
            case 13:printf("D");break;
            case 14:printf("E");break;
            case 15:printf("F");break;
            default:printf("%d",s->base[i]);break;
        } */
    }
    printf("\n");
}

int main()
{
    int m,n;
    char c;
    S s;
    if(!InitStack(&s)) printf("��ʼ��ʧ�ܣ�\n");
    do
    {
        printf("������һ��ʮ��������");
        scanf("%d",&m);
        printf("ʮ����ת��Ϊ����\n");
        printf("b.�����ơ�\to.�˽���\th.ʮ������\te.�˳�\n");
        printf("��ѡ��");
        c=getchar();
        scanf("%c",&c);
        switch(c)
        {
            case 'b':n=2;break;
            case 'o':n=8;break;
            case 'h':n=16;break;
            case 'e':c='e';break;
            default:break;
        }
        if(!Transform(&s,m,n)) printf("ʧ�ܣ�\n");
        Printf(&s);
    } while (c!='e');
    return 0;
}
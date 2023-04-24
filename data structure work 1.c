#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define FALSE 0
#define ElemType int

typedef struct //定义顺序表
{  
    ElemType *elme;//基地址
    int capacity;//表的容量
    int length;//表当前长度
} Sqlist;

// typedef Sqlist l;

int Initlist(Sqlist *l,int max)//初始化
{
    l->elme=(ElemType*)malloc(max*sizeof(ElemType));//动态分配空间
    l->length=0;
    l->capacity=max;
    if(!l->elme) return FALSE;
    else return OK;
}

void input(Sqlist *l)//输入数据
{
    int i;
    char s;
    printf("请输入数据：");
    do
    {
        scanf("%d",&l->elme[l->length]);
        l->length++;
        s=getchar();
    }while(s!='\n');
}

void output(Sqlist *l)//输出数据
{
    int i;
    for(i=0;i<l->length;i++)
        printf("%d\t",l->elme[i]);
    printf("\n");
}

void ListInsert(Sqlist *l)//插入数据
{
    int i,j,t;
    star:
    printf("插入位置：");
    scanf("%d",&i);
    printf("插入数据：");
    scanf("%d",&j);
    if(i>0&&i-1<l->length&&(l->length)<(l->capacity))//头部插入，中间插入
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
    else if(i-1==l->length)//尾部插入
    {
        l->elme[l->length]=j;
        l->length++;
    }
    else goto star;//无效插入
}

void ListDelete(Sqlist *l)//删除数据
{
    int i,t;
    star:
    printf("删除位置：");
    scanf("%d",&i);
    if(i-1==l->length)//尾部删除
        l->length--;
    else if(i-1>l->length)//无效删除
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
    printf("1.插入\t2.删除\t3.清空4.退出\n");
    printf("请选择功能：");
    scanf("%d",&i);
    switch(i)
    {
        case 1:ListInsert(L);break;
        case 2:ListDelete(L);break;
        case 3:ClearList(L);break;
        case 4:break;
        default:printf("错误！\n");goto choice;
    }
    if(i==4) return 0;
    else return 1;
}

int main()
{
    int i,max;
    Sqlist L;
    printf("输入最大长度：");
    scanf("%d",&max);
    printf("%d\n",Initlist(&L,max));
    input(&L);
    while(Memu(&L));
    // output(&L);
    return 0;
}
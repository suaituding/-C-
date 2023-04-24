#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define FALSE 0
#define maxsize 5

typedef struct
{
    char *base;     //基地址，动态数组首地址
    int top;        //栈顶指针
    int sqtacksize; //栈的容量
} leftparen;

typedef leftparen L;

int InitSqtack(L *l)    //初始化
{
    l->base=(char *)malloc(maxsize*sizeof(char));
    if(l->base==NULL) return FALSE;
    l->top=-1;
    l->sqtacksize=maxsize;
    return OK;
}

int Expandspace(L *l,int i)    //扩展i个大小的空间
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
    int count;      //计数，表示缺失括号的数量
    printf("请输入括号个数：");
    scanf("%d",&count);
    if(count>5) printf("%d",Expandspace(l,count-4));
    printf("请输入：");
    scanf("%s",l->base);
    while(*l->base!='\0')
    {
        if(*l->base!='('&&*l->base!=')')    return FALSE;
        if(*l->base=='(')    l->top++;
        else    l->top--;
        l->base++;
    }
    if(l->top==-1)
        printf("括号已全部匹配\n");
    else if(l->top>-1)
        printf("缺少%d个右括号\n",(l->top)+1);
    else
        printf("缺少%d个左括号\n",-1-l->top);
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
#include<stdio.h>
#include<stdlib.h>

#define maxsize 100
#define SElemType int
#define OK 1
#define FALSE 0

typedef struct
{
    SElemType *base;    //栈底指针
    SElemType *top;     //栈顶指针
    SElemType stacksize;        //栈的剩余容量
} Sqtack;

int InitStack(Sqtack *S)        //初始化，分配maxsize的空间
{
    S->base=(SElemType*)malloc(maxsize*sizeof(SElemType));
    S->stacksize=maxsize;
    S->top=S->base;
    if(S->base==NULL) return FALSE;     //初始化错误，返回FALSE
    else return OK;
}

int StackPush(Sqtack *S)     //入栈
{
    char i;
    printf("请输入数据：（回车结束输入）");
    do
    {
        if(S->stacksize==0) return FALSE;     //栈满时结束输入
        scanf("%d",S->top);
        i=getchar();
        S->top++;
        S->stacksize--;
    } while (i!='\n');
    return OK;
}

int StackPop(Sqtack *S)     //出栈
{
    if(S->stacksize==maxsize) return FALSE;     //空栈时返回FALSE
    else
    {
        S->top--;
        S->stacksize++;
        return OK;
    }
}

void StackDestroy(Sqtack *S)        //释放空间，销毁栈
{
    S->stacksize=maxsize;
    free(S->base);
}

void StackPrint(Sqtack *S)      //输出栈中所有元素
{
    SElemType *p=S->top;
    int i;
    printf("栈元素为：\n");
    for(i=maxsize-S->stacksize,p--;i>0;p--,i--)
        printf("\t%d\n",*p);
    /* while(p!=S->base)
    {
        p--;
        printf("\t%d\n",*p);
    } */
    printf("栈中剩余容量为:%d",S->stacksize);
    printf("\n");
}

int main()
{
    Sqtack *S;
    char s,i;
    if(InitStack(S)) printf("初始化成功\n");
    else printf("初始化失败\n");
    do
    {
        StackPrint(S);
        printf("p.入栈\to.出栈\td.销毁栈\te.退出\t请输入：");
        s=getchar();
        switch (s)
        {
            case 'p':
                if(StackPush(S)) printf("成功\n");
                else printf("失败，栈已满！\n");
                break;
            case 'o':
                if (StackPop(S)) printf("栈顶元素%d已出栈\n",*S->top);
                else
                {
                    printf("失败，栈为空！\n");
                    i=getchar();
                }
                break;
            case 'd':
                StackDestroy(S);
                printf("已销毁\n");
                i=getchar();
                break;
            case 'e':
                s='e';
                break;
            default:
                printf("错误！请重新输入\n");
                break;
        }
    } while (s!='e');
    return 0;
}
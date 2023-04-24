/*利用栈进行十进制与其他进制的转换
2整除十进制整数，得到一个商和余数；再用2去除商，又会得到一个商和余数，
如此重复，直到商为小于1时为止，然后把先得到余数作为二进制数的低位有效位，后得到的余数作为二进制数的高位
有效位，以此排列起来。以十进制100转换为二进制为例：
100/2=50余0；50/2=25余0；25/2=12余1；12/2=6余0；6/2=3余0；3/2=1余1。以此排列十进制的100转换成二进制是：1100100。*/

#include<stdio.h>
#include<stdlib.h>

#define maxsize 10
#define OK 1
#define FALSE 0

typedef struct
{
    int *base;          //栈底指针,开辟动态数组的首地址
    int top;            //栈顶指针
    int sqtacksize;      //栈的容量
} Sqtack;

typedef Sqtack S;

int InitStack(S *s)             //初始化
{
    s->base=(int*)malloc(maxsize*sizeof(int));
    s->top=-1;                      //栈顶指针表示当前栈顶元素下标，空时为-1
    s->sqtacksize=maxsize;
    if(s->base==NULL) return FALSE;
    return OK;
}

int Expandspace(S *s,int newsize)       //扩大栈的空间,newsize为扩大的空间
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

int Transform(S *s,int i,int ns)         //十进制转换为二，八，十六进制，i为十进制数，ns为转换的进制
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
                if(!Expandspace(s,maxsize))    //栈空间满，扩大空间
                    return FALSE;               //开辟新空间失败，返回FALSE
            s->top++;
            s->base[s->top]=i%ns;               //取余结果入栈
            i/=ns;                              //i自除
        }
        s->top++;
        s->base[s->top]=i;              //加上最后的商
    }
    return OK;
}

void Printf(S *s)
{
    int i;
    for(i=s->top;i>=0;i--)      //出栈，10~15用A~E代替，用于十六进制
    {
        if(s->base[i]<10)
            printf("%d",s->base[i]);
        else
            printf("%c",s->base[i]+55);     //利用ASCII表输出相应字符
        /* switch(s->base[i])       //已弃用
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
    if(!InitStack(&s)) printf("初始化失败！\n");
    do
    {
        printf("请输入一个十进制数：");
        scanf("%d",&m);
        printf("十进制转化为：？\n");
        printf("b.二进制、\to.八进制\th.十六进制\te.退出\n");
        printf("请选择：");
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
        if(!Transform(&s,m,n)) printf("失败！\n");
        Printf(&s);
    } while (c!='e');
    return 0;
}
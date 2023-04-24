#include<stdio.h>
#include<stdlib.h>

#define maxsize 5       //初始化定义数组的最大空间
#define ElemType int    //自定义存储数据类型
#define OK 1
#define FALSE 0

typedef struct 
{
    ElemType *base;         //基地址
    int capacity;           //数组长度
    int length;             //数组当前长度
} collection;

typedef collection C;

int Creat(C *c)     //初始化，分配空间
{
    c->base=(ElemType*)malloc(maxsize*sizeof(ElemType));
    c->capacity=maxsize;
    c->length=0;
    if(c->base==NULL) return FALSE;
    else return OK;
}

int Dropbox(C *c,int size)     //自定义增加空间
{
    int i;
    ElemType *new;
    new=(ElemType*)malloc((size+c->capacity)*sizeof(ElemType));   //开辟一段更大的空间
    if(new==NULL) return FALSE;
    for(i=0;i<c->length;i++)        //将原数组元素复制至新数组中
        new[i]=c->base[i];
    c->base=new;
    c->capacity+=size;
    free(new);
    return OK;
}

void Input(C *c)        //输入元素
{
    char i;
    printf("请输入:(最多%d个数):",c->capacity);
    do
    {
        scanf("%d",&c->base[c->length]);
        c->length++;
        i=getchar();
    } while (i!='\n'&&c->length<=c->capacity);
    /* for(i=0;i<maxsize;i++,c)
        scanf("%d",&c->base[i]); */
}

void Output(C *c)       //输出元素
{
    int i;
    for(i=0;i<c->length;i++)
        printf("%d\t",c->base[i]);
    printf("\n");
}

void Intersection(C *c1,C *c2)      //取交集并输出
{
    int i,j;
    printf("交集：");
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

void Aggregate(C *c1,C *c2)     //取并集并输出
{
    int i,j;
    C c3;                       //储存并集
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
        printf("并集：");
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
    printf("失败\n");
}

int main()
{
    C c1,c2;
    if(Creat(&c1)) printf("初始化成功\n");
    else printf("初始化失败\n");
    Input(&c1);
    if(Creat(&c2)) printf("初始化成功\n");
    else printf("初始化失败\n");
    Input(&c2);
    Output(&c1);
    Output(&c2);
    Intersection(&c1,&c2);
    Aggregate(&c1,&c2);
    return 0;
}
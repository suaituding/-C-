#include<stdio.h>
#include<stdlib.h>
struct List             //定义链表
{
    int data;
    struct List *next;
};

typedef struct List L;

L *Creat(L*head)        //创建结点
{
    L *p,*q;
    p=(L*)malloc(sizeof(L));
    printf("请输入数据：");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
        q->next=p;
    q=p;
    return head;
}

L *Insert(L *head)          //插入数据
{
    L *p,*q,*l;
    int i,j;
    if(head==NULL) Creat(head);
    for(j=1,p=head;p->next!=NULL;p=p->next)
        j++;
    // printf("j=%d\n",j);
    star:
    printf("请选择插入位置：");
    scanf("%d",&i);
    for(p=head;i>1;i--)
    {
        l=p;
        p=p->next;
    }
    if(i+1>j) goto star;
    q=(L*)malloc(sizeof(L));
    printf("请输入数据：");
    scanf("%d",&q->data);
    if(p==head)                  //头部插入
    {
        q->next=head;
        head=q;
    }
    else if(i-1==j)          //尾部插入
    {
        p->next=q;
        q->next=NULL;
    }
    else                      //中间插入
    {   
        l->next=q;
        q->next=p;
    }
    return head;
}

L *Delete(L *head)              //删除结点
{
    L *p,*q;
    int i,j;
    if(head==NULL) return 0;
    for(j=1,p=head;p->next!=NULL;p=p->next)
        j++;
    star:
    printf("请输入删除位置：");
    scanf("%d",&i);
    if(i>j) goto star;
    for(p=head;i>1;i--)
    {
        q=p;
        p=p->next;
    }    
    if(p==head)
    {
        head=p->next;
    }
    else if(p->next==NULL)
    {
        q->next=NULL;
    }
    else
    {
        q->next=p->next;
    }
    free(p);
    return head;
}

void Print(L*head)      //输出所有数据
{
    L *p;
    if(head==NULL) printf("链表为空！\n");
    else
    {
        printf("data:\n");
        for(p=head;p!=NULL;p=p->next)
            printf("%d\t",p->data);
        printf("\n");
    }
}

int select()        //选择
{
    char i;
    star:
    printf("\t是否继续？ y:是 n:否  #");
    scanf("%c",&i);
    scanf("%c",&i);
    if(i=='y') return 1;
    else if(i=='n') return 0;
    else
    {
      printf("\t错误\n");
      goto star;
    }
}

void Memu(L *head)
{
    int i;
    do
    {
        Print(head);
        printf("\n");
        printf("\t1、创建链表\n\n");
        printf("\t2、插入结点\n\n");
        printf("\t3、删除结点\n\n");
        printf("\t4、退出\n\n");
        printf("请选择：");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            do
            {
                head=Creat(head);
            } while (select());
            break;
            case 2:do
            {
                head=Insert(head);
            } while (select());
            break;
            case 3:
            do
            {
                head=Delete(head);
                Print(head);
            } while (select());
            break;
            case 4:break;
            default:printf("错误！\n");break;
        }
    } while (i!=4);
}

int main()
{
    struct List *head=NULL;     //头指针
    /* do
    {
        head=Creat(head);
    } while (select());
    Print(head);
    do
    {
        head=Insert(head);
        Print(head);
    } while (select());
    do
    {
        head=Delete(head);
        Print(head);
    } while (select()); */
    Memu(head);
    system("pause");
    return 0;
}
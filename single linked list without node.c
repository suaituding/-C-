#include<stdio.h>
#include<stdlib.h>
struct List             //��������
{
    int data;
    struct List *next;
};

typedef struct List L;

L *Creat(L*head)        //�������
{
    L *p,*q;
    p=(L*)malloc(sizeof(L));
    printf("���������ݣ�");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
        q->next=p;
    q=p;
    return head;
}

L *Insert(L *head)          //��������
{
    L *p,*q,*l;
    int i,j;
    if(head==NULL) Creat(head);
    for(j=1,p=head;p->next!=NULL;p=p->next)
        j++;
    // printf("j=%d\n",j);
    star:
    printf("��ѡ�����λ�ã�");
    scanf("%d",&i);
    for(p=head;i>1;i--)
    {
        l=p;
        p=p->next;
    }
    if(i+1>j) goto star;
    q=(L*)malloc(sizeof(L));
    printf("���������ݣ�");
    scanf("%d",&q->data);
    if(p==head)                  //ͷ������
    {
        q->next=head;
        head=q;
    }
    else if(i-1==j)          //β������
    {
        p->next=q;
        q->next=NULL;
    }
    else                      //�м����
    {   
        l->next=q;
        q->next=p;
    }
    return head;
}

L *Delete(L *head)              //ɾ�����
{
    L *p,*q;
    int i,j;
    if(head==NULL) return 0;
    for(j=1,p=head;p->next!=NULL;p=p->next)
        j++;
    star:
    printf("������ɾ��λ�ã�");
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

void Print(L*head)      //�����������
{
    L *p;
    if(head==NULL) printf("����Ϊ�գ�\n");
    else
    {
        printf("data:\n");
        for(p=head;p!=NULL;p=p->next)
            printf("%d\t",p->data);
        printf("\n");
    }
}

int select()        //ѡ��
{
    char i;
    star:
    printf("\t�Ƿ������ y:�� n:��  #");
    scanf("%c",&i);
    scanf("%c",&i);
    if(i=='y') return 1;
    else if(i=='n') return 0;
    else
    {
      printf("\t����\n");
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
        printf("\t1����������\n\n");
        printf("\t2��������\n\n");
        printf("\t3��ɾ�����\n\n");
        printf("\t4���˳�\n\n");
        printf("��ѡ��");
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
            default:printf("����\n");break;
        }
    } while (i!=4);
}

int main()
{
    struct List *head=NULL;     //ͷָ��
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
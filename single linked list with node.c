#include<stdio.h>
#include<stdlib.h>
struct List             //��������
{
    int data;
    struct List *next;
};

typedef struct List L;

L *Creat(L *Fdn) // �������
{
    L *p,*q;
    p=(L*)malloc(sizeof(L));
    printf("���������ݣ�");
    scanf("%d",&p->data);
    if(Fdn==NULL) Fdn=p;
    p->next=NULL;
    q->next=p;
    q=p;
    return Fdn;
}

L *Insert(L *Fdn)          //��������
{
    L *p,*q,*l;
    int i,j;
    if(Fdn==NULL) Creat(Fdn);
    for(j=1,p=Fdn;p->next!=NULL;p=p->next)
        j++;
    // printf("j=%d\n",j);
    star:
    printf("��ѡ�����λ�ã�");
    scanf("%d",&i);
    for(p=Fdn;i>1;i--)
    {
        l=p;
        p=p->next;
    }
    if(i+1>j) goto star;
    q=(L*)malloc(sizeof(L));
    printf("���������ݣ�");
    scanf("%d",&q->data);
    /* if(p==Fdn)                  //ͷ������
    {
        q->next=Fdn;
        Fdn=q;
    }
    else  */
    if(i==j)          //β������
    {
        p->next=q;
        q->next=NULL;
    }
    else                      //�м����
    {   
        l->next=q;
        q->next=p;
    }
    return Fdn;
}

L *Delete(L *Fdn)              //ɾ�����
{
    L *p,*q;
    int i,j;
    if(Fdn==NULL) return 0;
    for(j=1,p=Fdn;p->next!=NULL;p=p->next)
        j++;
    star:
    printf("������ɾ��λ�ã�");
    scanf("%d",&i);
    if(i>j) goto star;
    for(p=Fdn;i>1;i--)
    {
        q=p;
        p=p->next;
    }    
    /* if(p==Fdn)
    {
        Fdn=p->next;
    }
    else  */
    if(p->next==NULL)
    {
        q->next=NULL;
    }
    else
    {
        q->next=p->next;
    }
    free(p);
    return Fdn;
}

void Print(L*Fdn)      //�����������
{
    L *p;
    if(Fdn==NULL) printf("����Ϊ�գ�\n");
    else
    {
        printf("data:\n");
        for(p=Fdn;p!=NULL;p=p->next)
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

void Memu(L *Fdn)
{
    int i;
    do
    {
        Print(Fdn);
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
                Fdn=Creat(Fdn);
            } while (select());
            break;
            case 2:do
            {
                Fdn=Insert(Fdn);
            } while (select());
            break;
            case 3:
            do
            {
                Fdn=Delete(Fdn);
                Print(Fdn);
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
        Fdn=Creat(Fdn);
    } while (select());
    Print(Fdn);
    do
    {
        Fdn=Insert(Fdn);
        Print(Fdn);
    } while (select());
    do
    {
        Fdn=Delete(Fdn);
        Print(Fdn);
    } while (select()); */
    head=(L*)malloc(sizeof(L));
    L *Fdn=head->next=NULL;
    Memu(Fdn);
    system("pause");
    return 0;
}
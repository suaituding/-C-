#include<stdio.h>
#include<stdlib.h>
struct studentinformation
{
  int ID[10]; //ѧ��
  char name[9];//����
  int number[11];//�绰����
  int QQ[20];   //QQ����
  struct studentinformation *next;
};

typedef struct studentinformation SI;

int select()   //ѡ���Ƿ����
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

SI *creat(SI *head)          //���������㡢�����Ϣ
{
  SI *p,*q;
  q=(SI *)malloc(sizeof(SI));
  printf("\t������ѧ�ţ�");
  scanf("%d",&q->ID);
  printf("\t������������");
  scanf("%s",&q->name);
  printf("\t�������ֻ����룺");
  scanf("%d",&q->number);
  printf("\t������QQ���룺");
  scanf("%d",&q->QQ);
  q->next=NULL;
  if(head==NULL)
    head=q;
  else
    p->next=q;
  p=q;
  return head;
}

SI *IDsearch(SI *head,SI *q)//��ѧ�Ų��Ҳ�������Ӧ��ֵַ
{
  int id;
  SI *p=head;
  printf("\t������ѧ�ţ�");
  scanf("%d",&id);
  while(p!=NULL&&*p->ID!=id)
  {
    q=p;
    p=p->next;
  }
  return p;
}

SI *namesearch(SI *head,SI *q)//���������Ҳ�������Ӧ��ֵַ
{
  char name[9];
  SI *p=head;
  printf("\t���������֣�");
  scanf("%8s",name);
  while(p!=NULL&&strcmp(name,p->name)!=0)
  {
    q=p;
    p=p->next;
  }
  return p;
}

SI *numbersearch(SI *head,SI *q)//���绰������Ҳ�������Ӧ��ֵַ
{
  int number;
  SI *p=head;
  printf("\t������绰���룺");
  scanf("%d",&number);
  while(p!=NULL&&*p->number!=number)
  {
    q=p;
    p=p->next;
  }
  return p;
}

void find(SI *head) //����
{
  SI *p;
  int i;
  printf("\t��������ҷ�ʽ��1:ѧ�� 2:���� 3:�绰���� #");
  scanf("%d",&i);
  switch(i)
  {
    case 1:
      p=IDsearch(head,p);
      break;
    case 2:
      p=namesearch(head,p);
      break;
    case 3:
      p=numbersearch(head,p);
      break;
  }
  if(p==NULL) printf("\tδ�ҵ���\n");
  else
  {
    printf("\tѧ��\t����\t�绰����\tQQ\n");
    printf("\t%d\t%s\t%d\t%d\n",*p->ID,p->name,*p->number,*p->QQ);
  }
}

SI *dele(SI *head)//ɾ��
{
  SI *p,*q;
  int i;
  printf("\t��������ҷ�ʽ��1:ѧ�� 2:���� 3:�绰���� #");
  scanf("%d",&i);
  switch(i)
  {
    case 1:
      p=IDsearch(head,q);
      break;
    case 2:
      p=namesearch(head,q);
      break;
    case 3:
      p=numbersearch(head,q);
      break;
  }
  if(p==NULL) printf("\tδ�ҵ���\n");
  else if(p==head)
    head=p->next;
  else q->next=p->next;
  free(p);
  return head;
}

void display(SI *head)  //��ʾ����ѧ����Ϣ
{
  SI *p=head;
  if(p==NULL) printf("\tδ�ҵ��κ�ѧ����Ϣ��\n");
  else
  {
    for(p;p!=NULL;p=p->next)
    {
      printf("\tѧ��\t����\t�绰����\tQQ\n");
      printf("\t%d\t%s\t%d\t%d\n",*p->ID,p->name,*p->number,*p->QQ);
    }
  }
}

void save(SI *head)  //������E��ΪTXT�ļ�
{
  SI *p;
  FILE *fp;
  if((fp=fopen("E:\\data.txt","rt"))==NULL)
    fp=fopen("E:\\data.txt","wt");
  fp=fopen("E:\\data.txt","at");
  for(p=head;p!=NULL;p=p->next)
    fprintf(fp,"%d\t%s\t%d\t%d\n",*p->ID,p->name,*p->number,*p->QQ);
  fclose(fp);
}

int main()
{
  unsigned short int i,j;
  SI *head=NULL;
  while(1)
  {
    printf("\n");
    for(i=0;i<12;i++)
      printf("#");
    printf("ѧ��ͨѶ¼����ϵͳ");
    for(i=0;i<12;i++)
      printf("#");
    printf("\n\n");
    printf("\t1:��ʾѧ��������Ϣ\n\n");
    printf("\t2:���ѧ����Ϣ\n\n");
    printf("\t3:����ѧ����Ϣ\n\n");
    printf("\t4:ɾ��ѧ����Ϣ\n\n");
    printf("\t5:����ѧ����Ϣ��txt�ļ���\n\n");
    printf("\t6:�˳�\n\n");
    printf("\t��ѡ��");
    scanf("%d",&j);
    switch(j)
    {
      case 1:
        display(head);
        break;
      case 2:
        do
        head=creat(head);
        while(select());
        break;
      case 3:
        find(head);
        break;
      case 4:
        head=dele(head);
      case 5:
        save(head);
      case 6:
        break;
      default:
        printf("\t��������������\n");
        break;
    }
    if(j==6) break;
    system("pause");
    system("cls");
  }
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct studentinformation
{
  int ID[10]; //学号
  char name[9];//姓名
  int number[11];//电话号码
  int QQ[20];   //QQ号码
  struct studentinformation *next;
};

typedef struct studentinformation SI;

int select()   //选择是否继续
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

SI *creat(SI *head)          //创建链表结点、添加信息
{
  SI *p,*q;
  q=(SI *)malloc(sizeof(SI));
  printf("\t请输入学号：");
  scanf("%d",&q->ID);
  printf("\t请输入姓名：");
  scanf("%s",&q->name);
  printf("\t请输入手机号码：");
  scanf("%d",&q->number);
  printf("\t请输入QQ号码：");
  scanf("%d",&q->QQ);
  q->next=NULL;
  if(head==NULL)
    head=q;
  else
    p->next=q;
  p=q;
  return head;
}

SI *IDsearch(SI *head,SI *q)//按学号查找并返回相应地址值
{
  int id;
  SI *p=head;
  printf("\t请输入学号：");
  scanf("%d",&id);
  while(p!=NULL&&*p->ID!=id)
  {
    q=p;
    p=p->next;
  }
  return p;
}

SI *namesearch(SI *head,SI *q)//按姓名查找并返回相应地址值
{
  char name[9];
  SI *p=head;
  printf("\t请输入名字：");
  scanf("%8s",name);
  while(p!=NULL&&strcmp(name,p->name)!=0)
  {
    q=p;
    p=p->next;
  }
  return p;
}

SI *numbersearch(SI *head,SI *q)//按电话号码查找并返回相应地址值
{
  int number;
  SI *p=head;
  printf("\t请输入电话号码：");
  scanf("%d",&number);
  while(p!=NULL&&*p->number!=number)
  {
    q=p;
    p=p->next;
  }
  return p;
}

void find(SI *head) //查找
{
  SI *p;
  int i;
  printf("\t请输入查找方式：1:学号 2:姓名 3:电话号码 #");
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
  if(p==NULL) printf("\t未找到！\n");
  else
  {
    printf("\t学号\t姓名\t电话号码\tQQ\n");
    printf("\t%d\t%s\t%d\t%d\n",*p->ID,p->name,*p->number,*p->QQ);
  }
}

SI *dele(SI *head)//删除
{
  SI *p,*q;
  int i;
  printf("\t请输入查找方式：1:学号 2:姓名 3:电话号码 #");
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
  if(p==NULL) printf("\t未找到！\n");
  else if(p==head)
    head=p->next;
  else q->next=p->next;
  free(p);
  return head;
}

void display(SI *head)  //显示所有学生信息
{
  SI *p=head;
  if(p==NULL) printf("\t未找到任何学生信息！\n");
  else
  {
    for(p;p!=NULL;p=p->next)
    {
      printf("\t学号\t姓名\t电话号码\tQQ\n");
      printf("\t%d\t%s\t%d\t%d\n",*p->ID,p->name,*p->number,*p->QQ);
    }
  }
}

void save(SI *head)  //保存至E盘为TXT文件
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
    printf("学生通讯录管理系统");
    for(i=0;i<12;i++)
      printf("#");
    printf("\n\n");
    printf("\t1:显示学生基本信息\n\n");
    printf("\t2:添加学生信息\n\n");
    printf("\t3:查找学生信息\n\n");
    printf("\t4:删除学生信息\n\n");
    printf("\t5:保存学生信息至txt文件中\n\n");
    printf("\t6:退出\n\n");
    printf("\t请选择：");
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
        printf("\t错误！请重新输入\n");
        break;
    }
    if(j==6) break;
    system("pause");
    system("cls");
  }
  return 0;
}

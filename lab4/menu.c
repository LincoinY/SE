#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linkable.h"

void add();
void minus();
void mult();
void Div();
void max();
void min();
void quit();
void hello();
void Help();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

/*static tDataNode head[]=
{
    {"add","give the sum of two numbers",add,&head[1]},
    {"minus","subtract b from a",minus,&head[2]},
    {"mult","a multiplied by b",mult,&head[3]},
    {"Div","a divded by b",Div,&head[4]},
    {"max","give the bigger number of a and b",max,&head[5]},
    {"min","give the smaller number of a and b",min,&head[6]},
    {"quit","close the program",quit,&head[7]},
    {"hello","print hello to user",hello,&head[8]},
    {"help","instruct how to use progarm",Help,&head[9]},
};
*/
typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;//指令名
    char* desc;//指令描述
    int   (*handler)();//函数句柄
    struct DataNode *next;
}tDataNode;//定义命令结构体


tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
     while(pNode != NULL)
    {
    if(strcmp(pNode->cmd,cmd) == 0)
    {
        return pNode;
    }
    pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}   //从链表头寻找命令
int ShowAllCmd(tLinkTable* head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode !=NULL)
    {
    printf("%s - %s\n",pNode->cmd,pNode->desc);
    pNode =(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}  //显示所有命令

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="instruct how to use progarm";
    pNode->handler=Help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="close the program";
    pNode->handler=quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="add";
    pNode->desc="give the sum of two numbers!";
    pNode->handler=add;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="minus";
    pNode->desc="subtract b from a!";
    pNode->handler=minus;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0;
}//命令数据填充
tLinkTable* head=NULL;

int main()
{
    InitMenuData(&head);//取头节点指针，初始化链表
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please Input Command :\n");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
             printf("Wrong Command,please try again.\n");
             continue;
         }
         printf("%s \t %s\n",p->cmd,p->desc);
         if(p -> handler != NULL)
        {
            p -> handler();
        }
     }
}


void add()
{
    int a,b,add;
    printf("Please input two intergers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    add=a+b;
    printf("the sum of %d and %d is %d\n",a,b,add);
}

void minus()
{
    int a,b,minus;
    printf("Please input two intergers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    minus=a-b;
    printf("%d minus %d is %d\n",a,b,minus);
}

void mult()
{
    int a;
    int b;
    int mult;
    printf("Please input two intergers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    mult=a*b;
    printf(" %d multiplied by %d is %d\n",a,b,mult);
}

void Div()
{
    float a,b;
    float Div;
    printf("Please input two numbers:\n");
    scanf("%f",&a);
    scanf("%f",&b);
    Div=a/b;
    printf("%f divded by %f is %f\n", a,b,Div);
}

void max()
{
    int a,b,max;
    printf("Please input two intergers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a<b)
    {
        max=b;
    }
    else
    {
        max=a;
    }
    printf("The max of %d and %d is %d\n",a,b,max);
}

void min()
{
    int a,b,min;
    printf("Please input two intergers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a>b)
    {
        min=b;
    }
    else
    {
        min=a;
    }
    printf("The min of %d and %d is %d\n",a,b,min);
}

void quit()
{
    exit(0);
}

void hello()
{
    char name[100];
    printf("Please enter your name:\n");
    scanf("%s",name);
    printf("Hello ,%s\n",name);
}

void Help()
{
    ShowAllCmd(head);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linklist.h"

void add();
void minus();
void mult();
void Div();
void max();
void min();
void quit();
void hello();
void Help();

#define MAX_LEN 100
#define SIZE 10
static tDataNode head[]=
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

int main()
{
    while(1)
    {
        char cmd[MAX_LEN];
        tDataNode *p;
        printf("Please input the cmd\n");
        scanf("%s",cmd);
        p = FindCmd(head,cmd);
        if(p == NULL)
        {
            printf("Wrong cmd!");
            continue;
        }
        if(p->hander != NULL)
        {
            p -> hander();
        }
    }
    return 0;
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

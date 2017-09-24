#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

int main()
{
    char cmd[100];
    while(1)
    {
        printf("Please input the command:\n");
        scanf("%s",cmd);
        if(strcmp(cmd,"add") == 0)
        {
            add();
        }
        else if(strcmp(cmd,"minus") == 0)
        {
            minus();
        }
        else if(strcmp(cmd,"mult") == 0)
        {
            mult();
        }
        else if(strcmp(cmd,"div") == 0)
        {
            Div();
        }
        else if(strcmp(cmd,"max") == 0)
        {
            max();
        }
        else if(strcmp(cmd,"min") == 0)
        {
            min();
        }
        else if(strcmp(cmd,"quit") == 0)
        {
            quit();
        }
        else if(strcmp(cmd,"hello") == 0)
        {
            hello();
        }
        else
        {
            printf("Error command!\n");
        }
    }
} 

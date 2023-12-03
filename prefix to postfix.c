#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
char stack[10];
int top= -1;
int isfull()
{
    if(top == 5)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(char temp)
{
    stack[++top] = temp;
}
char pop()
{
    char val = stack[top];
    stack[top]=0;
    top--;
    return val;
}
int preced(char temp)
{
    if(temp == '(')
        return 0;
    else if(temp == '+' || temp == '-')
        return 1;
    else if(temp == '*' || temp == '/')
        return 2;
}
void main()
{
    char exp[20];
    printf("enter the expression : ");
    scanf("%s",exp);
    int i=0;
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            char m ;
            while(m = pop())
            {
                if(m == '(')
                    break;
                printf("%c",m);
            }
        }
        else
        {
            if(preced(stack[top]) >= preced(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++;
    }
    while(top!=-1)
        printf("%c",pop());
}

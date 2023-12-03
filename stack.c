#include<stdio.h>
int stack[5];
int top = -1;
int isfull()
{
    if(top == 4)
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
void push(int temp)
{
    if(isfull())
        printf("Stack is full");
    else
    {
        stack[++top]=temp;
    }
}
void pop()
{
    if(isempty())
        printf("Stack is empty");
    else
    {
        stack[top]=0;
        top--;
    }
}
void peek()
{
    printf("%d\n",stack[top]);
}
void display()
{
    if(isempty())
    {
        printf("Stack is empty");
    }
    else
        for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
        }
        printf("\n");
}
int main()
{
    int option;
    int input;
    while(1)
    {
        printf("\n1.Push \n");
        printf("2.Pop \n");
        printf("3.peek \n");
        printf("4.display \n");
        printf("exit \n");
        printf("Enter the option :");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the number :");
            scanf("%d",&input);
            push(input);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}

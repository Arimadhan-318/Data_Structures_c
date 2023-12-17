#include<stdio.h>
struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;
struct node* temp;
void push(int n)
{
    if(top == NULL)
    {
        top = (struct node*)malloc(sizeof(struct node));
        top->data = n;
        top->link = NULL;
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->link = top;
        top = temp;
    }
}
void pop()
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("%d",top->data);
        top = top->link;
    }
}
void peek()
{
    if(top == NULL)
        printf("Stack is empty");
    else
    {
        printf("%d",top->data);
    }
}
void display()
{
    if(top == NULL)
        printf("Stack is empty");
    else
    {
        struct node* current;
        current = top;
        while(current != NULL)
        {
            printf("%d",current->data);
            current = current->link;
        }
    }
}
int main()
{
    int option;
    int n;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter the number to push");
            scanf("%d",&n);
            push(n);
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
}

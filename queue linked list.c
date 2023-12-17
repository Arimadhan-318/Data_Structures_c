#include<stdio.h>
struct node
{
    int data;
    struct node* link;
};
struct node* rear = NULL;
struct node* front = NULL;
struct node* temp;
void enqueue(int n)
{
    if(rear == NULL)
    {
        rear = (struct node*)malloc(sizeof(struct node));
        rear->data = n;
        rear->link = NULL;
        front = rear;
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->link = NULL;
        rear->link = temp;
        rear = temp;
    }
}
void dequeue()
{
    if(front == NULL)
        printf("Queue is empty");
    else
    {
        printf("%d",front->data);
        front = front->link;
        if(front == NULL)
            rear = NULL;
    }
}
void display()
{
    if(front == NULL)
        printf("Queue is empty");
    else
    {
        struct node* current;
        current = front;
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
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.display\n");
        printf("4.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}

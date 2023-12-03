#include<stdio.h>
#include<conio.h>
int front = -1,rear = -1;
int size = 3;
int arr[3];
void enqueue(int temp)
{
    if(rear == size-1)
    {
        printf("Queue is full");
    }
    else if(front && rear == -1)
    {
        front++;rear++;
        arr[front] = temp;
    }
    else
    {
        rear++;
        arr[rear] = temp;
    }
}
void dequeue()
{
    if(front && rear == -1)
        printf("Queue is empty");
    else if(front == rear)
    {
        front = -1;rear = -1;
        arr[front] = 0;
    }
    else
    {
        printf("%d",arr[front]);
        arr[front] = 0;
        front++;
    }

}
void display()
{
    if(front && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i = front;i<=rear;i++)
        {
            printf("%d",arr[i]);
        }
    }
}
int main()
{
    int option ;
    int in;
    while(1)
    {
        printf("\n1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the number : ");
            scanf("%d",&in);
            enqueue(in);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            return 0;
        }
    }
}

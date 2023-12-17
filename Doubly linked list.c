#include<stdio.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head,* temp,* current;
void create_list()
{
    if(head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&head->data);
        head->prev = '\0';
        head->next = '\0';
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        current = head;
        while(current->next != NULL)
            current = current->next;
        printf("Enter the data : ");
        scanf("%d",&temp->data);
        temp->prev = '\0';
        temp->next = '\0';
        current->next = temp;
        temp->prev = current;
    }
}
void delete_val(int n)
{
    if(head == NULL)
        printf("Empty");
    else if(head->data == n)
    {
        head = head->next;
        if(current->next == NULL)
            {}
        else
            head->prev = '\0';
    }
    else
    {
        current = head;
        while(current->next->data != n && current != NULL)
            current = current->next;
        if(current == NULL)
            printf("Not Found");
        else
        {
            current->next = current->next->next;
            if(current->next == NULL)
            {}
            else
                current->next->prev = current;
        }
    }
}
void display()
{
    if(head == NULL)
        printf("NO value to display");
    else
    {
        current = head;
        printf("Forward display\n");
        while(current->next != NULL)
        {
            printf("%d",current->data);
            current = current->next;
        }
        printf("%d ",current->data);
    }
}
void insert_head()
{
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->prev = '\0';
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void delete_back()
{
    if(head == NULL)
        printf("No value to delete");
    else if(head->next == NULL)
    {
        printf("One only node");
    }
    else
    {
        current = head;
        while(current->next->next != NULL)
        {
            current = current->next;
        }
        current->next = NULL;
    }
}
int main()
{
    int option ;
    int n;
    while(1)
    {
        printf("\n1.Create list\n");
        printf("2.Delete value\n");
        printf("3.Insert at front\n");
        printf("4.Delete back\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            create_list();
            break;
        case 2:
            printf("Enter the value : ");
            scanf("%d",&n);
            delete_val(n);
            break;
        case 3:
            insert_head();
            break;
        case 4:
            delete_back();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        }
    }
}

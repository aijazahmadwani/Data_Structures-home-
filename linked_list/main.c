/* Author: Aijaz Ahmad Wani
email :aijazahmad9864@gmail.com
IMCA (SEM-2)
Subject : DATA STRUCTURES*/
//Different operations on Single Linked List
#include <stdio.h>
#include <stdlib.h>
void display();
void create_list();
int length();
void add_at_begin();
void insert_node_after(int);
void delete();
int menu();
struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;

int main()
{
    while(1)
    {
    system("cls");
    int choice,count=0,data,del,d1,d2;
    choice=menu();
    switch(choice)
    {
        case 1:
            create_list();
            printf("\nNode Created");
            break;
        case 2:
            add_at_begin();
            printf("Data inserted successfully");
            break;
        case 3:
            display();
            printf("\nEnter data after you want to insert new element : ");
            scanf("%d",&data);
            insert_node_after(data);
            printf("\nNode inserted ");
            break;
        case 4:
            display();
            printf("\nEnter data you want to delete : ");
            scanf("%d",&del);
            delete(del);
            break;

        case 5:
            display();
            break;
        case 6:
            count=length();
            printf("Length of linked list = %d ", count);

            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid input ......Try again");
    }
    getch();
    }
    getch();
}

int menu()
{
    int choice;
    printf("\n1.create list\n");
    printf("2.Add Node at beginning\n");
    printf("3.Insert data after a node\n");
    printf("4.Delete a node\n");
    printf("5.Display\n");
    printf("6.Length of Linked list\n");
    printf("7.Exit\n");
    printf("\n\n\nEnter your choice : ");
    scanf("%d",&choice);
    return (choice);
}

void create_list()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    else
    {
        struct node* t;
        t=root;
        while(t->link!=NULL)
        {
          t=t->link;
        }
        t->link=temp;
    }

}

void display()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("NO nodes");
        return ;
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}

int length()
{
    int count=0;
    struct node* temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void add_at_begin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data :");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
    root=temp;
    }

    else
    {
        temp->link=root;
        root=temp;
    }
}

void insert_node_after(int data)
{

    struct node* temp;
    struct node* f;
    temp =(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    f=root;
    while(f->data!=data)
    {
        f=f->link;
    }
    temp->link=f->link;
    f->link=temp;
}

void delete(int del)
{
    struct node*temp1,*temp2;
    temp1=root;
    if(del==temp1->data)
    {
        root=temp1->link;
        printf("first node deleted successfully ");
        return ;
    }
    else
    {
            while(temp1->link!=NULL)
            {
                if(temp1->data==del)
                {
                    break;
                }
                temp2=temp1;
                temp1=temp1->link;
            }
             temp2->link=temp1->link;
            printf("%d deleted successfully",del);

    }

}


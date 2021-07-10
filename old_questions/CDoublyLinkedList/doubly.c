#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"doubly.h"

void create_list(node **head, node **tail)
{
    *head=NULL;
    *tail=NULL;
}

void insert_beg(node **head, node **tail, int element)
{
    node *new=(node *)malloc(sizeof(node));
    new->data=element;
    new->prev=NULL;
    new->next=*head;
    if(*head!=NULL)
    (*head)->prev=new;
    *head=new;
    if(*tail==NULL)
    *tail=new;
}


void insert_end(node **head, node **tail, int element)
{
    if(*head==NULL)
    {
        insert_beg(head, tail, element);
        return;
    }
    node *new=(node *)malloc(sizeof(node));
    new->data=element;
    new->next=NULL;
    node *crt=*head;
    while(crt->next!=NULL)
        crt=crt->next;
    crt->next=new;
    new->prev=crt;
    *tail=new;
}

void insert_after_node(node **head, node **tail, int key, int element)
{
    if(*head==NULL)
    {
        insert_beg(head, tail, element);
        return;
    }
    if((*tail)->data==key)
    {
        insert_end(head, tail, element);
        return;
    }
    node *crt=*head;
    while(crt!=NULL && crt->data!=key)
        crt=crt->next;
    if(crt==NULL)
    {
        printf("Given Search key is not present in the list");
        return;
    }
    node *new=(node *)malloc(sizeof(node));
    new->data=element;
    node *temp=crt->next;
    crt->next=new;
    new->prev=crt;
    new->next=temp;
    temp->prev=new;
}

void insert_before_node(node **head, node **tail, int key, int element)
{
    if(*head==NULL)
    {
        insert_beg(head, tail, element);
        return;
    }
    if((*head)->data==key)
    {
        insert_beg(head, tail, element);
        return;
    }
    node *crt=*head;
    while(crt!=NULL && crt->data!=key)
        crt=crt->next;
    if(crt==NULL)
    {
        printf("Given Search key is not present in the list");
        return;
    }
    node *new=(node *)malloc(sizeof(node));
    new->data=element;
    node *temp=crt->prev;
    temp->next=new;
    new->prev=temp;
    new->next=crt;
    crt->prev=new;
}

void del_beg(node **head, node **tail)
{
    if(!Is_Empty(head))
    {
        if(*head==*tail)
        {
            free(*head);
            *head=NULL;
            *tail=NULL;
            printf("Element Deleted Successfully\n");
            return;
        }
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
        printf("Element Deleted Successfully\n");
    }
    else
        printf("List is Empty");
}

void del_end(node **head, node **tail)
{
    if(!Is_Empty(head))
    {
        if(*head==*tail)
        {
            free(*head);
            *head=NULL;
            *tail=NULL;
            printf("Element Deleted Successfully\n");
            return;
        }
        *tail=(*tail)->prev;
        free((*tail)->next);
        (*tail)->next=NULL;
        printf("Element Deleted Successfully\n");
    }
    else
        printf("List is Empty");
}

void del_search_key(node **head, node **tail, int element)
{
    if(!Is_Empty(head))
    {
        printf("Enter an element to delete\n");
        scanf("%d",&element);
        if((*head)->data==element)
        {
            del_beg(head, tail);
            return;
        }
        if((*tail)->data==element)
        {
            del_end(head, tail);
            return;
        }
        node *crt=*head;
        while(crt->next!=NULL && crt->next->data!=element)
            crt=crt->next;
        if(crt==*tail || crt->next==*tail)
        {
            printf("Element not present in the list\n");
            return;
        }
        node *temp=crt->next;
        temp->next->prev=crt;
        crt->next=temp->next;
        free(temp);
        printf("Element Deleted Successfully\n");
    }
    else
        printf("List is Empty");
}

void display(node *h)
{
    if(h==NULL)
        printf("List is Empty\n");
    else
    {
        while(h!=NULL)
        {
            printf("%d->",h->data);
            h=h->next;
        }
    }
}

bool Is_Empty(node **h)
{
    if(*h==NULL)
        return 1;
    else
        return 0;
}
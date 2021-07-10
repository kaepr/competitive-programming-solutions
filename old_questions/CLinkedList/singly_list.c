#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include"singly_list.h"

node *create_list()
{
    node *head=NULL;
    return head;
}
void insert_beg(node **h, int element)
{
    node *tmp=(node *)malloc(sizeof(node *));
    if(tmp==NULL)
    {
        printf("Memory not Allocated");
        exit(0);
    }
    tmp->data=element;
    tmp->next=*h;
    *h=tmp;
}

void insert_end(node **h, int element)
{
    node *tmp=(node *)malloc(sizeof(node *));
    if(tmp==NULL)
    {
        printf("Memory not Allocated");
        exit(0);
    }
    tmp->data=element;
    if(*h==NULL)
    {
        insert_beg(h, element);
        return;
    }
    node *crt=*h;
    while(crt->next!=NULL)
        crt=crt->next;
    crt->next=tmp;
    tmp->next=NULL;
}

void insert_after_node(node **h, int search_key, int element)
{
    node *tmp=(node *)malloc(sizeof(node *));
    if(tmp==NULL)
    {
        printf("Memory not Allocated");
        exit(0);
    }
    tmp->data=element;
    node *crt=*h;
    while(crt!=NULL && crt->data!=search_key)
        crt=crt->next;
    if(crt==NULL)
        printf("Search Key does not exist in the list\n");
    else
    {
        tmp->next=crt->next;
        crt->next=tmp;
    }
}

void del_beg(node **h)
{
    if(!Is_Empty(h))
    {
        node *tmp=*h;
        *h=(*h)->next;
        free(tmp);
    }
}

void del_end(node **h)
{
    node *crt = *h;
	if(!Is_Empty(h))
	{
			if((*h)->next==NULL)
			{
				*h = NULL;
				free(crt);
			}
			else
			{
				while(crt->next ->next != NULL)
					crt = crt->next;
				free(crt->next);
				crt->next = NULL;
            }
	}
}

void del_search_key(node **h, int key)
{
    node *crt=*h;
	if((*h)->data==key)
		del_beg(h);
	else
	{
		while(crt->next->data != key)
			crt = crt->next;
		node *tmp = crt->next;
		crt->next =tmp->next;
		free(tmp);
	}
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

void del_list(node **h)
{
    node *crt, *ptr;
	if(!Is_Empty(h))
	{
		node *crt=*h;
		while(crt!=NULL)
		{
			ptr=crt->next;
			free(crt);
			crt=ptr;
		}
		*h=NULL;
	}
}
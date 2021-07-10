#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"doubly.h"

void main()
{
    int choice, element, element1;
    node *head, *tail;
    create_list(&head, &tail);
    while(1)
    {
        printf("\n1. Insert in the beginning of the list\n");
        printf("2. Insert at the end of the list\n");
        printf("3. Insert after an element in the list\n");
        printf("4. Insert before an element in the list\n");
        printf("5. Delete from the beginning of the list\n");
        printf("6. Delete from the end of the list\n");
        printf("7. Delete a particular element from the list\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                insert_beg(&head, &tail, element);
                break;

            case 2:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                insert_end(&head, &tail, element);
                break;

            case 3:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                printf("Enter an element after which you want to insert\n");
                scanf("%d",&element1);
                insert_after_node(&head, &tail, element1, element);
                break;

            case 4:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                printf("Enter an element before which you want to insert\n");
                scanf("%d",&element1);
                insert_before_node(&head, &tail, element1, element);
                break;

            case 5:
                del_beg(&head,&tail);
                break;

            case 6:
                del_end(&head,&tail);
                break;

            case 7:
                del_search_key(&head, &tail,element);
                break;

            case 8:
                display(head);
                break;

            case 9:
                exit(0);
        }
    }

}
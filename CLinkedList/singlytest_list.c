#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include"singly_list.h"
void main()
{
    int choice, element;
    node *head=create_list();
    while(1)
    {
        printf("\n1. Insert in the beginning of the list\n");
        printf("2. Insert at the end of the list\n");
        printf("3. Insert after an element in the list\n");
        printf("4. Delete from the beginning of the list\n");
        printf("5. Delete from the end of the list\n");
        printf("6. Delete a particular element from the list\n");
        printf("7. Display\n");
        printf("8. Delete the entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                insert_beg(&head, element);
                break;

            case 2:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                insert_end(&head, element);
                break;

            case 3:
                printf("Enter an element to insert\n");
                scanf("%d",&element);
                printf("Enter an element after which you want to insert\n");
                int element1;
                scanf("%d",&element1);
                insert_after_node(&head, element1, element);
                break;

            case 4:
                del_beg(&head);
                printf("Element Deleted Successfully\n");
                break;

            case 5:
                del_end(&head);
                printf("Element Deleted Successfully\n");
                break;

            case 6:
                printf("Enter an element to delete\n");
                scanf("%d",&element);
                del_search_key(&head, element);
                printf("Element Deleted Successfully\n");
                break;

            case 7:
                display(head);
                break;

            case 8:
                del_list(&head);
                printf("List Deleted Successfully\n");
                break;

            case 9:
                exit(0);
        }
    }

}
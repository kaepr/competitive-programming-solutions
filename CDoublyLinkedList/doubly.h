typedef struct node{
int data;
struct node *prev;
struct node *next;
}node;

void create_list(node **head, node **tail);
void insert_beg(node **head, node **tail, int);
void insert_end(node **head, node **tail, int);
void insert_after_node(node **head, node **tail, int, int);
void insert_before_node(node **head, node **tail, int, int);
void del_beg(node **head, node **tail);
void del_end(node **head, node **tail);
void del_search_key(node **head, node **tail, int);
bool Is_Empty(node **);
void display(node *head);
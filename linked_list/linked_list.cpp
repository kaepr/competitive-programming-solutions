#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

class node {
public:
	int data;
	node* next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* n = new node(data);
	n->next = head;
	head = n;
}


void printLinkedList(node* head) {
	while (head != NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
	cout << "\n";
}

void insertInMiddle(node* &head, int data, int pos) {
	if (pos == 0) {
		insertAtHead(head, data);
	} else {
		node* tmp = head;
		for (int jump = 1; jump <= pos - 1; jump += 1) {
			tmp = tmp ->next;
		}
		node* new_node = new node(data);
		new_node->next = tmp -> next;
		tmp->next = new_node;
	}
}

void insertInMiddleSafe(node* &head, int data, int pos) {
	if (pos == 0) {
		insertAtHead(head, data);
		return;
	}

	node* tmp = head;
	for (int jump = 1; jump <= pos - 1; jump += 1) {
		if (tmp->next == NULL) {
			break;
		}
		tmp = tmp->next;
	}

	// inserting at last position
	if (tmp->next == NULL) {
		tmp -> next = new node(data);
		return;
	}

	node* new_node = new node(data);
	new_node->next = tmp->next;
	tmp->next = new_node;
}

node* recReverse(node *head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	node* sHead = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return sHead;
}

void iterativeReverse(node* &head) {
	node* prev = NULL;
	node* cur = head;
	node* tmp;

	while (cur != NULL) {
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}

	head = prev;
}

node* reverseKNodes(node* &head, int k) {
	if (head == NULL) {
		return NULL;
	}

	node* prev = NULL;
	node* cur = head;
	node* tmp;
	int cnt = 1;
	while (cur != NULL and cnt <= k) {
		// store next
		tmp = cur->next;
		// update current
		cur->next = prev;

		// prev and current moving them forward
		prev = cur;
		cur = tmp;
		cnt++;
	}

	if (tmp != NULL) {
		head -> next = reverseKNodes(tmp, k);
	}
	return prev;
}

node* mergeTwoSortedLL(node* a, node* b) {
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	node* c;

	if (a->data < b->data) {
		c = a;
		c -> next = mergeTwoSortedLL(a->next, b);
	} else {
		c = b;
		c -> next = mergeTwoSortedLL(a, b->next);
	}
	return c;
}

node* midPoint(node* head) {
	node* slow = head;
	node* fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergeSortLL(node* head) {
	// base case
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// rec case
	node* mid = midPoint(head);

	// break at the mid
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	// recrusive sort
	a = mergeSortLL(a);
	b = mergeSortLL(b);

	// merge
	return mergeTwoSortedLL(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	node* head = NULL;

	insertAtHead(head, 10);
	printLinkedList(head);

	return 0;
}














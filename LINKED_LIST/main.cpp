#include <bits/stdc++.h>
using namespace std;

// template<typename T>
// class Node {
// 	T data;
// 	Node<T> *next;
// public:
// 	Node(T data) {
// 		this->data = data;
// 		next = NULL;
// 	}
// };

// ---------------------

class node {
public:
	int data;
	node* next;

	node(int data) {
		this->data = data;
		next = NULL;
	}
};

// --------------------

bool isPresent(node* head, int key) {
	//Complete this function

	node* tmp = head;
	while (tmp != NULL) {
		if (tmp->data == key) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}


void insertAtHead(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node* new_node = new node(data);
	new_node->next = head;
	head = new_node;
}

void printLinkedList(node* head) {
	if (head == NULL) {
		cout << "Empty List";
	}
	while (head != NULL) {
		cout << head->data << "->";
		head = head -> next;
	}
	cout << "\n";
}

void deleteNode(node* &head, int key) {
	// key found at head position
	if (head->data == key) {
		node* tmp = head;
		head = tmp->next;
		delete tmp;
		return;
	}

	// else find previous ptr to the key
	node* prev = head;
	bool f = false;
	while (prev->next != NULL) {
		node* tmp = prev->next;
		if (tmp ->data == key) {
			f = true;
			break;
		}
		prev = tmp;
	}

	if (!f) {
		return;
	}

	// prev holds the element, whose next element is the one to
	// be deleted
	node* tmp = prev->next;
	prev->next = tmp->next;
	delete tmp;
}

void insertInMiddle(node* &head, int data, int pos) {
	if (pos == 0) {
		insertAtHead(head, data);
		return;
	}

	node* tmp = head;
	for (int jump = 1; jump <= pos - 1; jump++) {
		if (tmp->next == NULL) {
			break;
		}

		tmp = tmp->next;
	}

	// Insert at last position
	if (tmp->next == NULL) {
		tmp->next = new node(data);
		return;
	}


	node* new_node = new node(data);
	new_node->next = tmp->next;
	tmp->next = new_node;
}

void basicOperations() {
	node* head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);

	printLinkedList(head);

	insertAtHead(head, 5);
	printLinkedList(head);

	deleteNode(head, 6);
	printLinkedList(head);

	if (isPresent(head, 1)) {
		cout << "node was found\n";
	} else {
		cout << "node not found\n";
	}

	deleteNode(head, 1);
	printLinkedList(head);


	if (isPresent(head, 1)) {
		cout << "node was found\n";
	} else {
		cout << "node not found\n";
	}

	deleteNode(head, 5);
	printLinkedList(head);

	deleteNode(head, 3);
	printLinkedList(head);

	insertInMiddle(head, 98, 1);
	printLinkedList(head);

	deleteNode(head, 2);
	printLinkedList(head);

	deleteNode(head, 4);
	printLinkedList(head);
}


node* recReverse(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	node* sHead = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return sHead;
}

node* iterativeReverse(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	node* prev = NULL;
	node* cur = head;
	node* tmp;

	while (cur != NULL) {
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}

	return prev;
}

node* kReverse(node* head, int k) {
	if (head == NULL) {
		return NULL;
	}

	node* prev = NULL;
	node* cur = head;
	node* tmp;
	int cnt = 1;

	while (cur != NULL and cnt <= k) {
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
		cnt++;
	}

	if (tmp != NULL) {
		head -> next = kReverse(tmp, k);
	}

	return prev;
}

node* merge(node* a, node* b) {

	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	node* c;

	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	} else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

void solve() {
	// basicOperations();

	node* head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 5);


	printLinkedList(head);
	// head = recReverse(head);
	// head = iterativeReverse(head);
	head = kReverse(head, 3);
	printLinkedList(head);

}

int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();


	return 0;
}


// Find middle element
// class Solution {
// public:
// 	ListNode* middleNode(ListNode* head) {
// 		if (head == NULL) {
// 			return head;
// 		}
// 		ListNode* slow = head;
// 		ListNode* fast = head;
// 		while (slow != NULL && fast != NULL && fast->next != NULL ) {
// 			slow = slow->next;
// 			fast = fast->next->next;
// 		}
// 		return slow;
// 	}
// };

// Remove Nth Node From End of List
// class Solution {
// public:
// 	ListNode* removeNthFromEnd(ListNode* head, int n) {
// 		if (head == NULL) {
// 			return head;
// 		}

// 		ListNode* start = new ListNode();
// 		start->next = head;
// 		ListNode* fast = start;
// 		ListNode* slow = start;

// 		for (int i = 1; i <= n; i++) {
// 			fast = fast->next;
// 		}

// 		while (fast->next != NULL) {
// 			fast = fast->next;
// 			slow = slow->next;
// 		}

// 		slow->next = slow->next->next;
// 		return start->next;
// 	}
// };

// sort linked list
// class Solution {
// public:
//     ListNode* midPoint(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast != NULL and fast->next != NULL and fast->next->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }

//     ListNode* merge(ListNode* h1, ListNode* h2){
//         if(h1==NULL){
//             return h2;
//         }

//         if(h2==NULL){
//             return h1;
//         }

//         ListNode* h;
//         if(h1->val <= h2->val){
//             h = h1;
//             h->next = merge(h1->next, h2);
//         }else{
//             h = h2;
//             h->next = merge(h1, h2->next);
//         }
//         return h;
//     }

//     ListNode* sortList(ListNode* head) {
//         if(head==NULL or head->next == NULL){
//             return head;
//         }

//         ListNode* mid = midPoint(head);
//         ListNode* h1 = head;
//         ListNode* h2 = mid->next;
//         mid->next = NULL;

//         h1 = sortList(h1);
//         h2 = sortList(h2);
//         return merge(h1,h2);
//     }
// };

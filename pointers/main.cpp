#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
} node;

node *head = NULL;

int main() {
	// (*head).data = 5;
	head->data = 5;
	cout << head->data << "\n";
	// cout << head << "\n";
	cout << "Hello\n";
	// int x = 2;
	// cout << x << "\n";
	// cout << &x << "\n";
	// int *p_x = &x;
	// cout << p_x << "\n";
	// cout << *p_x << "\n";
	// cout << &p_x << "\n";
	// int **q_x = &p_x;

	// int a[3] = {12, 1, 2};
	// cout << a << "\n";
	// cout << &a[0] << "\n";
	// cout << *a << "\n";

	return 0;
}
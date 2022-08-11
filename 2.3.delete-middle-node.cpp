#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node() {}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

void deleteNode(Node* node) {
	if (!node || !node -> next)
		return;

	Node* d = node -> next;
	node -> val = d -> val;
	node -> next = d -> next;
	delete d;
}

void printList(Node* head) {
	if (head) {
		cout << " " << head -> val;
		printList(head -> next);
	}
}

void deleteList(Node* head) {
	if (head) {
		deleteList(head -> next);
		delete head;
	}
}

int main() {
	int n;
	if (cin >> n && n > 0) {
		Node list;
		Node *head = &list;
		while (n--) {
			int val;
			cin >> val;
			head = head -> next = new Node(val);
		}
		head = list.next;

		int nn;
		cout << "Enter node number to delete: ";
		cin >> nn;
		Node* t = head;
		while (nn--)
			t = t -> next;

		deleteNode(t);
		printList(head);
		cout << endl;

		deleteList(head);
	} else {
		cerr << "Positive sizes only." << endl;
	}
}

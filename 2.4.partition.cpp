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

Node* partitionList(Node* head, int& k) {
	Node l, r;
	Node *lp = &l, *rp = &r;
	while (head) {
		if (head -> val < k)
			lp = lp -> next = head;
		else
			rp = rp -> next = head;
		
		head = head -> next;
	}
	lp -> next = r.next;
	rp -> next = nullptr;
	return l.next;
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
	int n, k;
	if (cin >> n >> k && n > 0) {
		Node list;
		Node *head = &list;
		while (n--) {
			int val;
			cin >> val;
			head = head -> next = new Node(val);
		}
		head = list.next;
		Node* pList = partitionList(head, k);
		printList(pList);
		cout << endl;
		deleteList(pList);
	} else {
		cerr << "Invalid size." << endl;
	}
}

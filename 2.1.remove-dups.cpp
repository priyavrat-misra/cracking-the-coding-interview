#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node() {}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

Node* removeDups(Node* head) {
	Node *newHead = new Node(head -> val), *t = newHead;
	unordered_set<int> set;
	set.insert(head -> val);
	head = head -> next;
	while (head) {
		if (!set.count(head -> val)) {
			set.insert(head -> val);
			t -> next = new Node(head -> val);
			t = t -> next;
		}
		head = head -> next;
	}
	return newHead;
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
		Node* head = &list;
		while (n--) {
			int val;
			cin >> val;
			head = head -> next = new Node(val);
		}
		head = list.next;
		Node* newHead = removeDups(head);
		printList(newHead);
		cout << endl;

		deleteList(head);
		deleteList(newHead);
	} else {
		cerr << "Positive sizes only." << endl;
	}
}

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

void reverseList(Node* t, Node** head) {
	if (!t -> next) {
		*head = t;
		return;
	}
	reverseList(t -> next, head);
	t -> next -> next = t;
	t -> next = nullptr;
}

void deleteList(Node* head) {
	if (head) {
		deleteList(head -> next);
		delete head;
	}
}

bool isPalindrome(Node* head) {
	Node *i = head, *j = head;
	while (j && j -> next) {
		i = i -> next;
		j = j -> next -> next;
	}
	j = head;
	while (j -> next != i)
		j = j -> next;

	j -> next = nullptr;
	j = head;

	reverseList(i, &i);
	Node* t = i;
	while (j) {
		if (j -> val != i -> val) {
			deleteList(t);
			return false;
		}
		j = j -> next;
		i = i -> next;
	}
	deleteList(t);
	return true;
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

		cout << isPalindrome(head) << endl;

		deleteList(head);
	} else {
		cerr << "Positive sizes only." << endl;
	}
}

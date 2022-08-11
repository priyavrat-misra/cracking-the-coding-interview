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

Node* kthFromEnd(Node* head, int& i, int& k) {
	if (!head)
		return nullptr;
	Node* res = kthFromEnd(head -> next, i, k);
	++i;
	if (i == k)
		return head;

	return res;
}

void deleteList(Node* head) {
	if (head) {
		deleteList(head -> next);
		delete head;
	}
}

int main() {
	int n, k;
	if (cin >> n >> k && n > 0 && k > 0 && k <= n) {
		Node list;
		Node *head = &list;
		while (n--) {
			int val;
			cin >> val;
			head = head -> next = new Node(val);
		}
		head = list.next;
		int i = 0;
		cout << kthFromEnd(head, i, k) -> val << endl;

		deleteList(head);
	} else {
		cerr << "Invalid size or k." << endl;
	}
}

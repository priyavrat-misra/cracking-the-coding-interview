#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node() {}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

Node* addLists(Node* head1, Node* head2) {
	stack<int> s1, s2;
	while (head1) {
		s1.push(head1 -> val);
		head1 = head1 -> next;
	}
	while (head2) {
		s2.push(head2 -> val);
		head2 = head2 -> next;
	}

	Node* res = nullptr;
	int carry = 0;
	while (!(s1.empty() && s2.empty())) {
		if (!s1.empty()) {
			carry += s1.top();
			s1.pop();
		}
		if (!s2.empty()) {
			carry += s2.top();
			s2.pop();
		}
		res = new Node(carry % 10, res);
		carry /= 10;
	}
	if (carry)
		res = new Node(carry, res);

	return res;
}

Node* revAddLists(Node* head1, Node* head2) {
	Node list;
	Node* res = &list;
	int carry = 0;
	while (head1 || head2) {
		if (head1) {
			carry += head1 -> val;
			head1 = head1 -> next;
		}
		if (head2) {
			carry += head2 -> val;
			head2 = head2 -> next;
		}
		res = res -> next = new Node(carry % 10);
		carry /= 10;
	}
	if (carry)
		res = res -> next = new Node(carry);

	return list.next;
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
	int m, n;
	if (cin >> m >> n && m > 0 && n > 0) {
		Node list1;
		Node* head1 = &list1;
		while (m--) {
			int val;
			cin >> val;
			head1 = head1 -> next = new Node(val);
		}
		head1 = list1.next;

		Node list2;
		Node* head2 = &list2;
		while (n--) {
			int val;
			cin >> val;
			head2 = head2 -> next = new Node(val);
		}
		head2 = list2.next;

		Node* sum1 = addLists(head1, head2);
		Node* sum2 = revAddLists(head1, head2);

		printList(sum1);
		cout << endl;
		printList(sum2);
		cout << endl;

		deleteList(head1);
		deleteList(head2);
		deleteList(sum1);
		deleteList(sum2);
	} else {
		cerr << "Positive sizes only." << endl;
	}
}

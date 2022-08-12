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

bool intersect(Node* head1, Node* head2) {
	unordered_set<Node*> m;
	while (head1) {
		m.insert(head1);
		head1 = head1 -> next;
	}
	while (head2) {
		if (m.count(head2))
			return true;

		m.insert(head2);
		head2 = head2 -> next;
	}
	return false;
}

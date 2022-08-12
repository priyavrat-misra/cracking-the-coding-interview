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

Node* loop(Node* head) {
	unordered_set<Node*> m;
	while (head) {
		if (m.count(head))
			return head;

		m.insert(head);
		head = head -> next;
	}
	return nullptr;
}

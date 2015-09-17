#include "CircleList.h"

void CircleList::push(int value) {
	Node *n = new Node;
	n -> value = value;
	n -> next = NULL;

	if (tail == NULL) {
		head = tail = cur = pre = n;
		n -> next = n;
	} else {
		n -> next = tail -> next;
		tail -> next = n;
		tail = n;
	}

	length++;
}

int CircleList::remove() {
	int value = 0;
	if (cur != NULL) {
		if (cur == pre && length == 1) {
			value = cur -> value;
			delete cur;
			head = tail = cur = pre = NULL;
		} else {
			pre -> next = cur -> next;
			value = cur -> value;
			delete cur;
			cur = pre;
		}
		length -- ;
	}
	return value;
}

Node * CircleList::next() {
	if (cur != NULL) {
		pre = cur;
		cur = cur -> next;
		return cur;
	}
	return NULL;
}
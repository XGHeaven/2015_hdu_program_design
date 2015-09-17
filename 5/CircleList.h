#ifndef CIRCLELIST
#define CIRCLELIST
#include <iostream>

struct Node {
	int value;
	Node * next;
};

class CircleList {
private:
	Node *head, *tail, *cur, *pre;
public:
	CircleList():head(NULL),tail(NULL),cur(NULL),pre(NULL),length(0){};
	void push(int);
	int remove();
	Node * next();
	int length;
};

#endif
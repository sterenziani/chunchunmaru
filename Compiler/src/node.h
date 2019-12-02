#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum types {TYPE_EMPTY, TYPE_LITERAL, TYPE_TEXT, TYPE_NUM, TYPE_NOTE} type;

typedef struct Node {
	type type;
	char * value;

	struct Node * parent;
	struct Node * children;
	struct Node * next;
} Node;

Node * newNode(type type, char * value);
void append(Node * parent, Node * node);
void printInorder(Node * node);
void freeTree(Node * node);

#endif

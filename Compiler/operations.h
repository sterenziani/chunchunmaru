#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "node.h"

Node* expSum(Node* n1, Node* n2);
Node* expSub(Node* n1, Node* n2);
Node* expMult(Node* n1, Node* n2);
Node* expDiv(Node* n1, Node* n2);

int addVar(char* name, int type, char constant);
int getType(char* varName);
int isConst(char* varName);

#endif

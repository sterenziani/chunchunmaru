#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "node.h"

Node * expSum(Node * n1, Node * n2);
Node * expSub(Node * n1, Node * n2);
Node * expMult(Node * n1, Node * n2);
Node * expDiv(Node * n1, Node * n2);

int addVar(char * name, int type);
int getType(char * varName);
void openScope();
void closeScope();
int isInCurrentScope(char * varName);

#endif

#include "operations.h"
#include <string.h>

#define MAX_VAR 100

typedef enum operations {SUM, SUB, MULT, DIV} operation;

typedef struct var {
    char* name;
    int type;
    int scope;
} var;

var varTable[MAX_VAR];
int varTableIndex = 0;
int currScope = 0;
int vars = 0;

Node * intOperation(Node* n1, Node* n2, operation op);
extern void yyerror(char* s);

Node* expSum(Node* n1, Node* n2)
{
    Node* ret;
    if (n1->type == TYPE_NUM && n2->type == TYPE_NUM)
        ret = intOperation(n1, n2, SUM);
    else if (n1->type == TYPE_TEXT && n2->type == TYPE_TEXT)
    {
        ret = newNode(TYPE_TEXT, NULL);
        append(ret, newNode(TYPE_LITERAL, "_strconcat("));
        append(ret, n1);
        append(ret, newNode(TYPE_LITERAL, ", "));
        append(ret, n2);
        append(ret, newNode(TYPE_LITERAL, ")"));
    }
    else if ((n1->type == TYPE_TEXT && n2->type == TYPE_NUM) || (n1->type == TYPE_NUM && n2->type == TYPE_TEXT))
    {
        char * sort = ", 1)";
        if (n1->type == TYPE_NUM)
        {
            Node * aux = n1;
            n1 = n2;
            n2 = aux;
            sort = ", -1)";
        }
        ret = newNode(TYPE_TEXT, NULL);
        append(ret, newNode(TYPE_LITERAL, "_strintconcat("));
        append(ret, n1);
        append(ret, newNode(TYPE_LITERAL, ", "));
        append(ret, n2);
        append(ret, newNode(TYPE_LITERAL, sort));
    }
    else
        yyerror("Sum between incompatible types.\n");
    return ret;
}

Node* expSub(Node * n1, Node * n2)
{
    Node* ret;
    if (n1->type == TYPE_NUM && n2->type == TYPE_NUM)
        ret = intOperation(n1, n2, SUB);
    else
        yyerror("Substraction between incompatible types.\n");
    return ret;
}

Node* expMult(Node * n1, Node * n2)
{
    Node * ret;
    if (n1->type == TYPE_NUM && n2->type == TYPE_NUM)
        ret = intOperation(n1, n2, MULT);
    else if ((n1->type == TYPE_NUM && n2->type == TYPE_TEXT) || (n1->type == TYPE_TEXT && n2->type == TYPE_NUM))
    {
        if (n1->type == TYPE_NUM)
        {
            Node * aux = n1;
            n1 = n2;
            n2 = aux;
        }
        ret = newNode(TYPE_TEXT, NULL);
        append(ret, newNode(TYPE_LITERAL, "_strintmult("));
        append(ret, n1);
        append(ret, newNode(TYPE_LITERAL, ", "));
        append(ret, n2);
        append(ret, newNode(TYPE_LITERAL, ")"));
    }
    else
        yyerror("Multiplication between incompatible types.\n");
    return ret;
}

Node * expDiv(Node * n1, Node * n2)
{
    Node * ret;
    if (n1->type == TYPE_NUM && n2->type == TYPE_NUM)
        ret = intOperation(n1, n2, DIV);
    else
        yyerror("Division between incompatible types.\n");
    return ret;
}

Node * intOperation(Node * n1, Node * n2, operation op)
{
    Node * ret;
    ret = newNode(TYPE_NUM, NULL);
    append(ret, n1);
    char * opStr;
    switch(op) {
        case SUM:
            opStr = " + ";
            break;
        case SUB:
            opStr = " - ";
            break;
        case MULT:
            opStr = " * ";
            break;
        case DIV:
            opStr = " / ";
            break;
    }
    append(ret, newNode(TYPE_LITERAL, opStr));
    append(ret, n2);
    return ret;
}

int addVar(char * name, int type)
{
    if (varTableIndex == MAX_VAR)
      return -1;
    varTable[varTableIndex].name = name;
    varTable[varTableIndex].type = type;
    varTable[varTableIndex].scope = currScope;
    varTableIndex++;
    return 1;
}

int isInCurrentScope(char * varName)
{
    for (int i = varTableIndex - 1; i >= 0 && varTable[i].scope == currScope; i--)
    {
        if (strcmp(varName, varTable[i].name) == 0)
            return 1;
    }
    return 0;
}

int getType(char * varName)
{
    for (int i = varTableIndex - 1; i >= 0; i--)
    {
        if (strcmp(varName, varTable[i].name) == 0)
            return varTable[i].type;
    }
    return -1;
}

void openScope()
{
    currScope++;
}

void closeScope()
{
    currScope--;
    while(varTableIndex > 0 && varTable[varTableIndex - 1].scope > currScope)
        varTableIndex--;
}

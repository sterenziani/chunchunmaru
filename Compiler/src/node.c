#include "node.h"
#include "compiler.h"
#include "music.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

extern FILE * tmpFile;

Node * newNode(type type, char * value)
{
	Node * node = malloc(sizeof(Node));
	node->type = type;
	node->value = value;
  node->parent = NULL;
  node->children = NULL;
  node->next = NULL;
	return node;
}

void append(Node * parent, Node * node) {
    if (parent == NULL || node == NULL)
        return;

    if (parent->children != NULL){
     	Node * aux = parent->children;
      	while (aux->next != NULL) {
            aux = aux->next;
        }
      	aux->next = node;
    } else
      	parent->children = node;

    node->parent = parent;
}

void freeTree(Node * node) {
	if(node->children == NULL && node->next == NULL){
		free(node);
		return;
	}
	if(node->children != NULL){
		freeTree(node->children);
	}
	if(node->next != NULL){
		freeTree(node->next);
	}
	free(node);
}

void printInorder(Node * node) {
		if(node->type == TYPE_NOTE && node->value != NULL && strcmp(node->value, "note ") != 0)
		{
			char length = node->value[0];
			switch(length)
			{
				case '1': length = CORCHEA; break;
				case '2': length = NEGRA; break;
				case '3': length = BLANCA; break;
				case '4': length = REDONDA; break;
			};
			char octave = node->value[1] + 3;
			char key = node->value[2];
			char sharp = (node->value[3] == '#');
			if(toupper(key) == 'R')
				fprintf(tmpFile, "createNote(REST, %d)", length);
			else if(sharp)
				fprintf(tmpFile, "createNote(%c%c_sharp, %d)", toupper(key), octave, length);
			else
				fprintf(tmpFile, "createNote(%c%c, %d)", toupper(key), octave, length);
		}
    else if (node->type != TYPE_EMPTY && node->value != NULL)
        fprintf(tmpFile, "%s", node->value);
    else {
        Node * aux = node->children;
        while(aux != NULL) {
            printInorder(aux);
            aux = aux->next;
        }
    }
}

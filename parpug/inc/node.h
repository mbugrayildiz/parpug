#ifndef PP_NODE_H
#define PP_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* node class */
typedef struct pp_Node pp_Node;
struct pp_Node {
	char *tag;
	pp_Node *val;
	size_t ns_len, ns_cap;
	pp_Node **ns;
};

/* constructor & destructor */
pp_Node *pp_Node_new();
void pp_Node_free(pp_Node *self);

/* methods */
void pp_Node_push(pp_Node *self, pp_Node *child);
pp_Node *pp_Node_pop(pp_Node *self);
void pp_Node_print(pp_Node *self);

#endif

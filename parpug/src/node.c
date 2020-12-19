#include "node.h"

#define PP_NODE_NS_DEFAULT_CAP 20

pp_Node *pp_Node_new()
{
	pp_Node *self = malloc(sizeof(pp_Node));
	*self = (pp_Node){
		.tag = NULL,
		.val = NULL,

		.ns_len = 0,
		.ns_cap = PP_NODE_NS_DEFAULT_CAP,
		.ns = calloc(PP_NODE_NS_DEFAULT_CAP, sizeof(pp_Node*)),
	};
	return self;
}

void pp_Node_free(pp_Node *self)
{
	size_t i;
	for (i = 0; i < self->ns_len; i++)
		pp_Node_free(self->ns[i]);

	if (self->tag)
		free(self->tag);
	free(self);
}

void pp_Node_push(pp_Node *self, pp_Node *child)
{
	if (self->ns_cap / 2 > self->ns_len) {
		self->ns_cap *= 2;
		self->ns = realloc(self->ns, self->ns_cap * sizeof(pp_Node*));
	}
	self->ns[self->ns_len++] = child;
}

pp_Node *pp_Node_pop(pp_Node *self)
{
	if (self->ns_len == 0)
		return NULL;
	return self->ns[--self->ns_len];
}

void pp_Node_print(pp_Node *self)
{
	static size_t indent = 0;
	size_t i;

	i = 0;
	while (i++ < indent)
		putchar('\t');
	printf("<%s", self->tag);

	if (self->val != NULL)
		printf(" val='%s'", self->val->tag);
	printf(">\n");

	indent++;
	for (i = 0; i < self->ns_len; i++)
		pp_Node_print(self->ns[i]);
	indent--;

	i = 0;
	while (i++ < indent)
		putchar('\t');
	printf("</%s>\n", self->tag);
}

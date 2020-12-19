#include "parser-state.h"

pp_ParserState *pp_ParserState_new(char *src)
{
	pp_ParserState *self = malloc(sizeof(pp_ParserState));
	*self = (pp_ParserState){
		.src = src,
		.i = 0,
		.i_dep = 0,
		.i_len = 0,
		.val = malloc(strlen(src))
	};
	self->val[0] = '\0';
	return self;
}

void pp_ParserState_free(pp_ParserState *self)
{
	free(self->src);
	free(self->val);
	free(self);
}

char pp_ParserState_curr(pp_ParserState *self)
{
	return self->src[self->i];
}

char pp_ParserState_next(pp_ParserState *self)
{
	if (self->src[self->i] != '\0')
		return self->src[self->i++];
	return '\0';
}

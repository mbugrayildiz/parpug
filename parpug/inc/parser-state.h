#ifndef PP_PARSERSTATE_H
#define PP_PARSERSTATE_H

#include <stdlib.h>
#include <string.h>

/* parser state class */
typedef struct {
	char *src;
	size_t i;
	size_t i_dep, i_len;

	char *val;
} pp_ParserState;

/* constructor & destructor */
pp_ParserState *pp_ParserState_new(char *src);
void pp_ParserState_free(pp_ParserState *self);

/* methods */
char pp_ParserState_curr(pp_ParserState *self);
char pp_ParserState_next(pp_ParserState *self);

#endif

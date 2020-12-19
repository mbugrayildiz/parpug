#include "parser.h"

pp_Node *pp_parse_stmt(pp_ParserState *ps)
{
	return pp_parse_tag(ps);
}

pp_Node *pp_parse_tag(pp_ParserState *ps)
{
	while (isspace(pp_ParserState_curr(ps)))
		pp_ParserState_next(ps);

	char *it = ps->val;
	while (isalpha(pp_ParserState_curr(ps)))
		*it++ = pp_ParserState_next(ps);

	if (it == ps->val)
		return NULL;
	*it = '\0';

	pp_Node *tag = pp_Node_new();
	tag->tag = strcpy(malloc(strlen(ps->val)), ps->val);

	if (pp_ParserState_curr(ps) == ' ') {
		pp_ParserState_next(ps);
		tag->val = pp_parse_tillnewline(ps);
	}

	return tag;
}

pp_Node *pp_parse_tillnewline(pp_ParserState *ps)
{
	char *it = ps->val;
	while (pp_ParserState_curr(ps) != '\n' && pp_ParserState_curr(ps) != '\0')
		*it++ = pp_ParserState_next(ps);

	if (it == ps->val)
		return NULL;
	*it = '\0';

	pp_Node *tag = pp_Node_new();
	tag->tag = strcpy(malloc(strlen(ps->val)), ps->val);
	return tag;
}

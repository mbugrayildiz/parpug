#ifndef PP_PARSER_H
#define PP_PARSER_H

#include <ctype.h>
#include "node.h"
#include "parser-state.h"

/* grammar */
pp_Node *pp_parse_stmt(pp_ParserState *ps);

/* primitives */
pp_Node *pp_parse_tag(pp_ParserState *ps);
pp_Node *pp_parse_tillnewline(pp_ParserState *ps);
pp_Node *pp_parse_eq(pp_ParserState *ps);
pp_Node *pp_parse_str(pp_ParserState *ps);

#endif

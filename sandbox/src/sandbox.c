#include "parpug.h"
#include <unistd.h>

extern char* optarg;
extern int getopt(int, char**, char*);

void read_file(char *fpath)
{
	char *src = pp_ftos(fpath);
	if (src == NULL) {
		fprintf(stderr, "failed to open file");
		return;
	}

	puts(src);
	free(src);
}

void parse_file(char *fpath)
{
	char *src = pp_ftos(fpath);
	if (src == NULL) {
		fprintf(stderr, "failed to open file");
		return;
	}

	pp_ParserState *ps = pp_ParserState_new(src);

	pp_Node *ast = pp_parse_stmt(ps);
	pp_Node_print(ast);

	pp_Node_free(ast);
	pp_ParserState_free(ps);
}

int main(int argc, char **argv)
{
	int opt;

	while ((opt = getopt(argc, argv, "r:p:")) != -1) {
		switch (opt) {

		case 'r':
			read_file(optarg);
			break;

		case 'p':
			parse_file(optarg);
			break;

		default:
			break;

		}
	}
}

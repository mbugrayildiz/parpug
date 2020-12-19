#include "parpug.h"

char *pp_ftos(char *fpath)
{
	FILE *fp = fopen(fpath, "r");
	if (fp == NULL)
		return NULL;

	fseek(fp, 0, SEEK_END);
	const size_t size = ftell(fp);
	rewind(fp);

	char *buf = malloc(size + 1);
	fread(buf, 1, size, fp);

	fclose(fp);
	return buf;
}

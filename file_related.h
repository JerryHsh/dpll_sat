#ifndef FILE_RELATED_H
#define FILE_RELATED_H

#include "definition.h"

void get_filename(char *name);
status read_cnf_file(cnf_node &node, char *filename);
status show_cnf_file(cnf_node my_node);
status store_result(char *filename, double time);

#endif // !FILE_RELATED_H

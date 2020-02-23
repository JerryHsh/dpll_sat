#ifndef FILE_RELATED_H
#define FILE_RELATED_H

#include "definition.h"

void get_filename(char *name);
status read_cnf_file(cnf_node &node, char *filename);
status show_cnf_node(cnf_node &my_node);
status store_time(char *filename, double time);
status store_result(char *filename, cnf_node &node,int search_node);

#endif // !FILE_RELATED_H

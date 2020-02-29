#ifndef FILE_RELATED_H
#define FILE_RELATED_H

#include "definition.h"

void get_filename(char *name);
status read_cnf_file(cnf_node &node, char *filename);
status show_cnf_node(cnf_node &my_node);
status store_time(char *filename, double time);
status store_result(char *filename, cnf_node &node, int search_node);
status initialize_related_info(cnf_node &current_node);
void intialize_dict_according_to_three_digit(cnf_node &node, int size, int three_digit);
void initialize_dict_info(cnf_node &mynode, int size);
void initialize_weight_dict(cnf_node &node,int number);
void initialize_dict_by_number(cnf_node &node,int number);
void show_dict(cnf_node mynode);

#endif // !FILE_RELATED_H

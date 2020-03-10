#ifndef GENERATE_SODOKU_HEAD
#define GENERATE_SODOKU_HEAD

#include "definition.h"
#include"dpll_solution.h"

typedef int unique_status;
const unique_status unique = 1;
const unique_status common = 0;
const unique_status dug = -1;

unique_status position_unique(cnf_node default_node, puzzel_node &current_node, int position);
int reverse_to_cr(int num, int size); //return the number in row and column form
void copy_puzzel_node(puzzel_node src_node, puzzel_node &des_node);

#endif // !GENERATE_SODOKU_HEAD

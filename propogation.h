#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "generate_sodoku.h"
puzzel_node swap_row(puzzel_node &current_node, int row_1, int row_2);
puzzel_node swap_column(puzzel_node &current_node, int column_1, int column_2);
void random_generate(puzzel_node &current_node);
void swap_value(int &x, int &y);

#endif // !PROPAGATION_H

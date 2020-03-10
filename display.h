#ifndef DISPLAY

#include "dpll_solution.h"

bool display_choice(); //display the choice
void print_space(int num);
status show_puzzel_desk(puzzel_node puzzel_node); //print the chess desk on the screen
status read_sodoku_result(puzzel_node &node, char *filename);

status initialize_puzzel_node(puzzel_node &node, int size);

#endif // !DISPLAY
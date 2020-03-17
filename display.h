#ifndef DISPLAY

#include "dpll_solution.h"
#include"generate_sodoku.h"
#include"propogation.h"

int display_choice(); //display the choice
void print_space(int num);
status show_puzzel_desk(puzzel_node current_node); //print the chess desk on the screen
status read_sodoku_result(puzzel_node &node, char *filename);
status initialize_puzzel_node(puzzel_node &node, int size);
void free_puzzel_node(puzzel_node &node);
status show_answer(puzzel_node current_node);
status dpll_branch();//operate the dpll option in main function
status sodoku_branch();
status play_sodoku(puzzel_node &p_node);
status check_win(puzzel_node p_node);



#endif // !DISPLAY
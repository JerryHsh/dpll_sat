#ifndef GENERATE_SODOKU_HEAD
#define GENERATE_SODOKU_HEAD

#include "definition.h"
#include "dpll_solution.h"
#include "random.h"
#include "display.h"

typedef int unique_status;
const unique_status unique = 1;
const unique_status common = 0;
const unique_status dug = -1;
typedef struct
{
    int mode;              //1 easy 2 medium 3 hard
    int line_lower_bound;  //lower bound of the given cell in a line
    int total_lower_bound; //lower bound of the total given cell in a line
} level_regulation;

status generalize_easy_mode(cnf_node default_node, puzzel_node &current_node); //generalize the easy mode of sodoku using randomizing
status generalize_medium_mode(cnf_node default_node, puzzel_node &current_node);
status generalize_evil_mode(cnf_node default_node, puzzel_node &current_node);

unique_status position_unique(cnf_node default_node, puzzel_node &current_node, int position);
int reverse_to_cr(int num, int size); //return the number in row and column form
void copy_puzzel_node(puzzel_node &src_node, puzzel_node &des_node);
status check_violate_regulation(puzzel_node node, level_regulation mode);
void initialize_mode(level_regulation &mode, int size, int level);
//status check_status(level_regulation mode, puzzel_node current_node, puzzel_node &info_node); //check if the situation meet the requirment

status check_row(level_regulation mode, puzzel_node current_node, int begin, puzzel_node &info_node);    //check the current row
status check_column(level_regulation mode, puzzel_node current_node, int begin, puzzel_node &info_node); //check the current column
status check_row_column(level_regulation mode, puzzel_node current_node, puzzel_node &info_node);
status check_total(level_regulation mode, puzzel_node current_node); //check the total empty space
status check_info_node(puzzel_node &info_node);

#endif // !GENERATE_SODOKU_HEAD

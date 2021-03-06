#ifndef DPLL_SOLUTION_H
#define DPLL_SOLUTION_H

#include "file_related.h"
#include "optimize.h"
#include "clause_related.h"
#include "my_debug.h"
#include "generate_clauses.h"

status solver(char *filename,cnf_node &node);                                                           //dpll problem solver
solution_status dpll_algorithm(cnf_node current_node, char *filename, int &search_node); //the main function

#endif // !DPLL_SOLUTION_H
#ifndef UNIT_CLAUSE_H
#define UNIT_CLAUSE_H

#include "definition.h"

solution_status check_matrix(cnf_node &current_node);//check the unit and empty clauses and do the solution
status find_unit_clause(cnf_node current_node,int &num);//if find the unit clause then return the position of the clause
status update_by_unit(cnf_node &current_node, int literal);
status check_empty_clause(cnf_node current_node);//if find the empty clause return 1 otherwise return 0


#endif // !UNIT_CLAUSE_H
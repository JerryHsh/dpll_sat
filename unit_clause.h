#ifndef UNIT_CLAUSE_H
#define UNIT_CLAUSE_H

#include "definition.h"

clause_status check_clause(cnf_node current_node, int num); //num means the number of clauses
solution_status check_matrix(cnf_node &current_node);//check the unit and empty clauses and do the solution
status update_by_unit(cnf_node &current_node, int literal);

#endif // !UNIT_CLAUSE_H
#ifndef UNIT_CLAUSE_H
#define UNIT_CLAUSE_H

#include "definition.h"
status initialize_related_info(cnf_node &current_node);
int find_unit_literal(cnf_node &current_node);                  //if find the unit clause then return the literal
status update_by_unit(cnf_node &current_node, int literal);     //update the current node by given unit
int check_empty_matrix(cnf_node &current_node);                 //check if the matrix contains empty clause
int check_literal_clause(vector<int> v, int literal);           //check if the clause contain given literal
status remove_literal_from_clause(vector<int> &v, int literal); //remove the certain literal from the clause
void assigned_literal(cnf_node &current_node, int literal);
cnf_node add_unit_clause(cnf_node current_node,int literal);//add new unit clauses into the cnf clauses set


#endif // !UNIT_CLAUSE_H
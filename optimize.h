#ifndef OPTIMIZE_H
#define OPTIMIZE_H

#include "definition.h"
#include "clause_related.h"
#include "math.h"

void calculate_literal_weight(cnf_node &current_node, int literal); //return the weight of one literal
status calculate_weight(cnf_node &current_node);                    //calculate all the literal weight in the node
int select_unit_literal(cnf_node &current_node);                    //return the selected literal
int render_new_unit(cnf_node &current_node); //select a new literal to be true or false
float optimize_value(int literal);                                  //retuen the optimize value of the literal
float compare_value(float x,float y);


#endif // !OPTIMIZE_H

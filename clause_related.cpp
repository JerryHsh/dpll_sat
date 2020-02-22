#include "unit_clause.h"

status find_unit_clause(cnf_node current_node, int &num) //if find the unit clause then return the position of the clause
{
    int i;
    for (i = 0; i < current_node.matrix.size(); i++)
        if (current_node.matrix[i].size() == 1)
            return i;
    return -1; //if we didn't find it then return -1
}

status check_empty_clause(cnf_node current_node) //if find the empty clause return 1 otherwise return 0
{
    int i;
    for (i = 0; i < current_node.matrix.size(); i++)
        if (current_node.matrix[i].size() == 0)
            return 1;
        else
            return 0;
}

status update_by_unit(cnf_node &current_node, int literal)
{
}

solution_status check_matrix(cnf_node &current_node) //check the unit and empty clauses and do the solution
{
    /*
    int i, j;
    clause_status flag;
    if (current_node.matrix.size() == 0)
        return satisfied;
    for (i = 0; i < current_node.matrix.size(); i++)
    {
        flag = check_clause(current_node, i);
        if (flag == unit_c)
            update_by_unit(current_node, current_node.matrix[i][0]);
        else if (flag == empty_c)
            return unsatisfied;
    }
    */
}

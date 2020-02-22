#include "unit_clause.h"

clause_status check_clause(cnf_node current_node, int num) //num means the number of clauses
{
    int var_num = current_node.matrix[num].size();
    if (var_num == 1)
        return unit_c;
    else if (var_num == 0)
        return empty_c; //the clause is empty means two unit become contradict
    else
        return normal_c;
}

solution_status check_matrix(cnf_node &current_node) //check the unit and empty clauses and do the solution
{
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
}
status update_by_unit(cnf_node &current_node, int literal)
{
}

#include "unit_clause.h"

clause_status check_clause(cnf_node current_node, int num) //num means the number of clauses
{
    int var_num = current_node.matrix[num].size();
    if (var_num == 1)
        return unit;
    else if (var_num == 0)
        return empty;//the clause is empty means two unit become contradict
    else
        return normal;
}

solution_status check_matrix(cnf_node &current_node)//check the unit and empty clauses and do the solution
{
    int i, j;
    clause_status flag;
    for (i = 0; i < current_node.matrix.size(); i++)
    {
        flag = check_clause(current_node, i);
        if (flag == unit)
            update_by_unit(current_node, current_node.matrix[i][0]);
        else if(flag==empty)
            return unsatisfied; 
    }
}
status update_by_unit(cnf_node &current_node, int literal);

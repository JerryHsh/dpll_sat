#include "dpll_solution.h"


solution_status dpll_algorithm(cnf_node current_node,char *filename,int &search_node) //the main function
{
    search_node++;
    cout<<"total search node: "<<search_node<<endl;
    int unit_literal = 0;
    while ((unit_literal = find_unit_literal(current_node)) != 0)
    {
        update_by_unit(current_node, unit_literal);
        if (current_node.matrix.size() == 0)
            return satisfied;
        else if (check_empty_matrix(current_node) == 1)
            return unsatisfied;
    }
    //give the unit literal a new value generate by branching function
    calculate_weight(current_node);
    unit_literal = render_new_unit(current_node);
    if (dpll_algorithm(add_unit_clause(current_node, unit_literal),search_node) == satisfied)
        return satisfied;
    else
        return dpll_algorithm(add_unit_clause(current_node, unit_literal * -1),search_node);
}


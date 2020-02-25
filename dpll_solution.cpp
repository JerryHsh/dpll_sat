#include "dpll_solution.h"

status solver()
{
    //do preparation
    char filename[81];
    int search_node = 0;
    double processing_time;
    time_t start, end;
    start = clock();
    get_filename(filename);
    cnf_node node;
    //test the function
    //end test
    //solution begin
    if (read_cnf_file(node, filename) == ok)
    {
        if (dpll_algorithm(node, filename, search_node) == satisfied)
            cout << "has running this function" << endl;
    }
    else
    {
        return wrong;
    }
    //end solution
    end = clock();
    processing_time = (double)(end - start) / CLOCKS_PER_SEC;
    store_time(filename, processing_time);
    return ok;
}

solution_status dpll_algorithm(cnf_node current_node, char *filename, int &search_node) //the main function
{
    search_node++;
    //if (search_node % 1 == 0)
    //getchar(), getchar();
    //cout << "\n\ntotal search node: " << search_node << " matrix size: " << current_node.matrix.size() << "**************************************************************************************************************" << endl; //debug
    //show_cnf_node(current_node);                                                                                                                                                                                                    //debug
    int unit_literal = 0;
    while ((unit_literal = find_unit_literal(current_node)) != 0)
    {
        //cout << "the new found unit literal: " << unit_literal << endl;
        update_by_unit(current_node, unit_literal);
        //  show_cnf_node(current_node);
        if (current_node.matrix.size() == 0)
        {
            store_result(filename, current_node, search_node);
            cout << "satisfied*******************************************************" << endl;
            return satisfied;
        }
        else if (check_empty_matrix(current_node) == 1)
            return unsatisfied;
    }
    //give the unit literal a new value generate by branching function
    calculate_weight(current_node);
    unit_literal = render_new_unit(current_node);
    //cout << "selected literal: " << unit_literal << endl;
    if (dpll_algorithm(add_unit_clause(current_node, unit_literal), filename, search_node) == satisfied)
        return satisfied;
    else
    {
        //cout << "unsatisfied________________________________________________________________" << endl;
        return dpll_algorithm(add_unit_clause(current_node, unit_literal * -1), filename, search_node);
    }
}

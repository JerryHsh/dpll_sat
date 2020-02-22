#include "clause_related.h"

int find_unit_literal(cnf_node &current_node) //if find the unit clause then return the literal
{
    int i;
    for (i = 0; i < current_node.matrix.size(); i++)
        if (current_node.matrix[i].size() == 1)
            return current_node.matrix[i][0];
    return 0; //if we didn't find it then return 0
}

int check_empty_matrix(cnf_node &current_node) //check if the matrix contains empty clause
{
    int i;
    for (i = 0; i < current_node.matrix.size(); i++)
        if (current_node.matrix[i].size() == 0)
            return 1; //if it contains then return 1
    return 0;
}

int check_literal_clause(vector<int> v, int literal) //check if the clause contain given literal
{
    for (auto i = v.begin(); i != v.end(); i++)
        if (*i == literal)
            return 1; //return 1 if it contains the given literal
    return 0;
}

status remove_literal_from_clause(vector<int> &v, int literal) //remove the certain literal from the clause
{
    while (v.back() == literal)
        v.pop_back();
    for (auto i = v.begin(); i != v.end(); i++)
        if (*i == literal)
        {
            v.erase(i); //maybe it contain the same literal
            i = v.begin();
        }
    v.shrink_to_fit();
    return ok;
}

status update_by_unit(cnf_node &current_node, int literal) //update the current node by given unit
{
    int oppo_literal = literal * (-1);
    while (check_literal_clause(current_node.matrix.back(), literal) == 1)
        current_node.matrix.pop_back();
    for (auto i = current_node.matrix.begin(); i != current_node.matrix.end(); i++)
    {
        if (check_literal_clause(*i, literal) == 1)
        {
            current_node.matrix.erase(i); //delete the whole clause
            i=current_node.matrix.begin();
        }
        else if (check_literal_clause(*i, oppo_literal) == 1)
        {
            remove_literal_from_clause(*i, oppo_literal); //remove the -literal from the clause cause it's false
        }
    }
    current_node.matrix.shrink_to_fit();
    current_node.clauses_num = current_node.matrix.size();
    return ok;
}
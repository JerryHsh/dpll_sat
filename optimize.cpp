#include "optimize.h"

void calculate_literal_weight(cnf_node &current_node, int literal) //calculate the positive and negative value,the literal is always posive
{
    float positive_weight, negative_weight;
    int i;
    for (i = 0, positive_weight = 0, negative_weight = 0; i < current_node.clauses_num; i++)
        if (check_literal_clause(current_node.matrix[i], literal) == 1)
            positive_weight += optimize_value(current_node.matrix[i].size());
        else if (check_literal_clause(current_node.matrix[i], literal * (-1)) == 1)
            negative_weight += optimize_value(current_node.matrix[i].size());
    current_node.weight_dict[literal][positive] = positive_weight;
    current_node.weight_dict[literal][negative] = negative_weight;
}

status calculate_weight(cnf_node &current_node) //calculate all the literal weight in the node
{
    int i;
    for (auto i=current_node.result_dict.begin();i!=current_node.result_dict.end();i++)
        if (current_node.result_dict[i->first] == unassigned)
            calculate_literal_weight(current_node, i->first);
        else
        {
            current_node.weight_dict[i->first][positive] = -1;
            current_node.weight_dict[i->first][negative] = -1;
        }
    return ok;
}

float optimize_value(int length) //retuen the optimize value of the literal
{
    return pow(2, length * -1);
}

float compare_value(float x, float y)
{
    return x + y;
}

int render_new_unit(cnf_node &current_node) //select a new literal to be true or false
{
    int selected_literal = 0;                               //selected literal is always >0
    float max_compare_value = 0, current_compare_value = 0; //means x+y
    for (auto i = current_node.result_dict.begin(); i != current_node.result_dict.end(); i++)
    {
        if (i->second == unassigned)
        {
            current_compare_value = compare_value(current_node.weight_dict[i->first][positive], current_node.weight_dict[i->first][negative]);
            if (current_compare_value > max_compare_value)
            {
                selected_literal = i->first;
                max_compare_value = current_compare_value;
            }
        }
    }
    if (current_node.weight_dict[selected_literal][positive] >= current_node.weight_dict[selected_literal][negative])
        return selected_literal;
    else
        return selected_literal * -1;
}
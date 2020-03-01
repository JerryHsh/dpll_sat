#include "my_debug.h"

void print_weight(cnf_node &node)
{
    for (auto iterator = node.weight_dict.begin(); iterator != node.weight_dict.end(); iterator++)
    {
        cout << iterator->first << ": positive: " << iterator->second[positive] << " negative: " << iterator->second[negative] << endl;
    }
}

void print_result(cnf_node &node)
{
    for (auto i = node.result_dict.begin(); i != node.result_dict.end(); i++)
    {
        cout << "literal: " << i->first << ": ";
        if (i->second == True)
            cout << "true";
        else if (i->second == False)
            cout << "false";
        else
            cout << "unassigned";
        cout << endl;
    }
}
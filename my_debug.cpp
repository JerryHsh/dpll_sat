#include "my_debug.h"

void print_weight(cnf_node &node)
{
    int i;
    for (i = 0; i <= node.literals_num; i++)
    {
        cout << i << ": positive: " << node.weight[i][positive] << " negative: " << node.weight[i][negative] << endl;
    }
}

void print_result(cnf_node &node)
{
    int i;
    for (i = 0; i <= node.literals_num; i++)
    {
        cout << "literal: " << i << ": ";
        if (node.result[i] == 1)
            cout << "true";
        else if (node.result[i] == 0)
            cout << "false";
        else
            cout << "unassigned";
        cout << endl;
    }
}
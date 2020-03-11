#include "generate_sodoku.h"

//check if the given position can be dug postion is a continuous sequence
//if it's unique return unique else return common if it had been dug return dug
//use default_node to store the rule of binary sodoku
unique_status position_unique(cnf_node default_node, puzzel_node &current_node, int position)
{
    puzzel_node node;
    copy_puzzel_node(current_node, node);//all the change happened in copy one
    if (node.puzzel_desk[position] == unassigned)
        return dug;
    else if (node.puzzel_desk[position] == True)
        node.puzzel_desk[position] = False;
    else
        node.puzzel_desk[position] = True;
    int i;
    for (i = 0; i < node.size; i++)
    {
        if (node.puzzel_desk[i] == True)
            update_by_unit(default_node, reverse_to_cr(i, node.size));
        else if (node.puzzel_desk[i] == False)
            update_by_unit(default_node, reverse_to_cr(i, node.size) * -1);
    }
    int search_node = 0;
    if (dpll_algorithm(default_node, NULL, search_node) == satisfied)
        return common;
    else
        return unique;
}

int reverse_to_cr(int num, int size) //return the number in row and column form
{
    //num is a sequence begin with 0
    return (num / size + 1) * 10 + num % size + 1;
}

void copy_puzzel_node(puzzel_node src_node, puzzel_node &des_node)
{
    des_node.size = src_node.size;
    des_node.puzzel_desk = (value *)malloc(des_node.size * des_node.size * sizeof(value));
    for (int i = 0; i < des_node.size; i++)
        des_node.puzzel_desk[i] = src_node.puzzel_desk[i];
}

void initialize_mode(level_regulation &mode, int size)
{
    cout << "input the level: easy 1\tmedium 2\thard 3" << endl;
input:
    cin >> mode.mode;
    if (mode.mode == 1)
    {
        mode.line_lower_bound = size / 2 + 1;
        mode.total_lower_bound = size * size * 5 / 8;
    }
    else if (mode.mode == 2)
    {
        mode.line_lower_bound = size / 3;
        mode.total_lower_bound = size * size * 3 / 8;
    }
    else if (mode.mode == 3)
    {
        mode.line_lower_bound = 0;
        mode.total_lower_bound = size * size * 3 / 10;
    }
    else
    {
        cout << "wrong input" << endl;
        goto input;
    }
}
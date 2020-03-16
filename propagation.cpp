#include "propogation.h"

void swap_value(int &x, int &y)
{
    int swap = x;
    x = y;
    y = swap;
}

puzzel_node swap_row(puzzel_node &current_node, int row_1, int row_2)
{
    int row1_begin = (row_1 - 1) * current_node.size;
    int row2_begin = (row_2 - 1) * current_node.size;
    for (int i = 0; i < current_node.size; i++)
    {
        swap_value(current_node.puzzel_desk[row1_begin + i], current_node.puzzel_desk[row2_begin + i]);
        swap_value(current_node.answer[row1_begin + i], current_node.answer[row2_begin + i]);
    }
    return current_node;
}

puzzel_node swap_column(puzzel_node &current_node, int column_1, int column_2)
{
    int column1_begin = column_1 - 1;
    int column2_begin = column_2 - 1;
    for (int i = 0; i < current_node.size; i++)
    {
        swap_value(current_node.puzzel_desk[column1_begin + i * current_node.size], current_node.puzzel_desk[column2_begin + i * current_node.size]);
        swap_value(current_node.answer[column1_begin + i * current_node.size], current_node.answer[column2_begin + i * current_node.size]);
    }
    return current_node;
}

void random_generate(puzzel_node &current_node)
{
    int iteration_time = 0;
    iteration_time = rand() % 5 + 3;
    for (int i = 0; i < iteration_time; i++)
    {
        int line_1, line_2;
        line_1 = rand() % current_node.size + 1;
        line_2 = (line_1 + (rand() % (current_node.size - 1) + 1)) % current_node.size;
        if (line_2 == 0)
            line_2 = current_node.size;
        swap_column(current_node, line_1, line_2);
        swap_row(current_node, line_1, line_2);
    }
}
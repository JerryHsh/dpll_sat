#include "propogation.h"

puzzel_node swap_row(puzzel_node original_node, int row_1, int row_2)
{
    puzzel_node new_puzzel_node;
    copy_puzzel_node(original_node, new_puzzel_node);
    int swap;
    int row1_begin = (row_1 - 1) * new_puzzel_node.size;
    int row2_begin = (row_2 - 1) * new_puzzel_node.size;
    for (int i = 0; i < new_puzzel_node.size; i++)
    {
        swap = new_puzzel_node.puzzel_desk[row1_begin + i];
        new_puzzel_node.puzzel_desk[row1_begin + i] = new_puzzel_node.puzzel_desk[row2_begin + i];
        new_puzzel_node.puzzel_desk[row2_begin + i] = swap;
    }
    return new_puzzel_node;
}

puzzel_node swap_column(puzzel_node original_node, int column_1, int column_2)
{
    puzzel_node new_puzzel_node;
    copy_puzzel_node(original_node, new_puzzel_node);
    int swap;
    int column1_begin = column_1 - 1;
    int column2_begin = column_2 - 1;
    for (int i = 0; i < new_puzzel_node.size; i++)
    {
        swap = new_puzzel_node.puzzel_desk[column1_begin + i * new_puzzel_node.size];
        new_puzzel_node.puzzel_desk[column1_begin + i * new_puzzel_node.size] = new_puzzel_node.puzzel_desk[column2_begin + i * new_puzzel_node.size];
        new_puzzel_node.puzzel_desk[column2_begin + i * new_puzzel_node.size] = swap;
    }
    return new_puzzel_node;
}

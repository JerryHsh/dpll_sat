#include "display.h"

int display_choice()
{
    int choice;
    system("clear");
    cout << "dpll or soduku 1/2" << endl;
    cout << "if you want to exit enter 0" << endl;
    cin >> choice;
    return choice;
}

void print_space(int num)
{
    for (int i = 0; i < num; i++)
        cout << ' ';
}

status show_answer(puzzel_node current_node)
{
    int i, j;
    for (i = 0; i < current_node.size + 1; i++)
    {
        if (i == 0)
        {
            int m;
            for (m = 0; m < 1 + current_node.size; m++)
            {
                if (m == 0)
                    print_space(2);
                else
                {
                    print_space(1);
                    cout << m;
                }
            }
            cout << endl
                 << endl;
        }
        else
        {
            for (j = 0; j < current_node.size + 1; j++)
            {
                if (j == 0)
                {
                    cout << i;
                    print_space(1);
                }
                else
                {
                    print_space(1);
                    if (current_node.answer[(i - 1) * current_node.size + j - 1] != unassigned)
                        cout << current_node.answer[(i - 1) * current_node.size + j - 1];
                    else
                        cout << ' ';
                }
            }
            cout << endl;
        }
    }
    return ok;
}

status show_puzzel_desk(puzzel_node current_node) //print the chess desk on the screen
{
    int i, j;
    for (i = 0; i < current_node.size + 1; i++)
    {
        if (i == 0)
        {
            int m;
            for (m = 0; m < 1 + current_node.size; m++)
            {
                if (m == 0)
                    print_space(2);
                else
                {
                    print_space(1);
                    cout << m;
                }
            }
            cout << endl
                 << endl;
        }
        else
        {
            for (j = 0; j < current_node.size + 1; j++)
            {
                if (j == 0)
                {
                    cout << i;
                    print_space(1);
                }
                else
                {
                    print_space(1);
                    if (current_node.puzzel_desk[(i - 1) * current_node.size + j - 1] != unassigned)
                        cout << current_node.puzzel_desk[(i - 1) * current_node.size + j - 1];
                    else
                        cout << ' ';
                }
            }
            cout << endl;
        }
    }
    return ok;
}

status read_sodoku_result(puzzel_node &node, char *filename)
{
    char filename_open[81];
    strcpy(filename_open, filename);
    strcat(filename_open, ".sod");
    FILE *fp;
    fp = fopen(filename_open, "r");
    if (fp == NULL)
    {
        cout << "no such file" << endl;
        return wrong;
    }
    int temp_order_store;
    for (int i = 0; i < node.size * node.size; i++)
    {
        fscanf(fp, "%d", &temp_order_store);
        fscanf(fp, "%d", &node.puzzel_desk[temp_order_store - 1]);
        node.answer[temp_order_store - 1] = node.puzzel_desk[temp_order_store - 1];
    }
    fclose(fp);
    return ok;
}

status initialize_puzzel_node(puzzel_node &node, int size)
{
    node.size = size;
    node.puzzel_desk = (value *)malloc((size * size) * sizeof(value));
    node.answer = (value *)malloc(sizeof(value) * size * size);
    if (node.puzzel_desk == NULL || node.answer == NULL)
        exit(overflow);
    for (int i = 0; i < size * size; i++)
    {
        node.puzzel_desk[i] = unassigned;
        node.answer[i] = unassigned;
    }
    return ok;
}

void free_puzzel_node(puzzel_node &node)
{
    free(node.puzzel_desk);
    free(node.answer);
}

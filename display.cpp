#include "display.h"

bool display_choice()
{
    bool choice;
    system("clear");
    cout << "dpll or soduku 0/1" << endl;
    cin >> choice;
    return choice;
}

void print_space(int num)
{
    for (int i = 0; i < num; i++)
        cout << ' ';
}

status show_puzzel_desk(puzzel_node puzzel_node) //print the chess desk on the screen
{
    int i, j;
    for (i = 0; i < puzzel_node.size + 1; i++)
    {
        if (i == 0)
        {
            int m;
            for (m = 0; m < 1 + puzzel_node.size; m++)
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
            for (j = 0; j < puzzel_node.size + 1; j++)
            {
                if (j == 0)
                {
                    cout << i;
                    print_space(1);
                }
                else
                {
                    print_space(1);
                    if (puzzel_node.puzzel_desk[(i - 1) * puzzel_node.size + j - 1] != unassigned)
                        cout << puzzel_node.puzzel_desk[(i - 1) * puzzel_node.size + j - 1];
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
    }
    fclose(fp);
    return ok;
}

status initialize_puzzel_node(puzzel_node &node, int size)
{
    node.size = size;
    node.puzzel_desk = (value *)malloc((size * size) * sizeof(value));
    if (node.puzzel_desk == NULL)
        exit(overflow);
    for (int i = 0; i < size * size; i++)
    {
        node.puzzel_desk[i] = unassigned;
    }
    return ok;
}

void free_puzzel_node(puzzel_node &node)
{
    free(node.puzzel_desk);
}

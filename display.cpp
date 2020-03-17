#include "display.h"

status dpll_branch(void)
{
    int choice;
    char filename[81]; //store the filename
    while (1)
    {
        system("clear");
        strcpy(filename, "");
        get_filename(filename);
        cnf_node node;
        read_cnf_file(node, filename);
        solver(filename, node);
        getchar();
        getchar();
        system("clear");
        cout << "do you have another dpll problem 0/1" << endl;
        cin >> choice;
        if (choice == 0)
            break;
    }
    return ok;
}

status sodoku_branch()
{
    int choice;
    int size;
    puzzel_node p_node;
    while (1)
    {
        system("clear");
        cnf_node node;
        char filename[81] = "sodoku"; //store the filename
        cout << "enter the size of the binary sodoku\n"
             << "enter 0 to exit" << endl;
        cin >> size;
        if (size == 0)
            break;
        else if (size % 2)
        {
            cout << "wrong input" << endl;
            continue;
        }
        //generate related clauses
        initialize_dict_info(node, size);
        generate_clauses(filename, size);
        read_sodoku_cnf(node, filename, size);
        solver(filename, node);
        //generate sodoku
        initialize_puzzel_node(p_node, size);
        read_sodoku_result(p_node, filename);
        system("clear");
        cout << "how hard do you want?\n"
             << "easy: 1\tmedium: 2\tevil: 3" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            generalize_easy_mode(node, p_node);
            //random_generate(p_node);
            play_sodoku(p_node);
            break;
        case 2:
            generalize_medium_mode(node, p_node);
            //random_generate(p_node);
            play_sodoku(p_node);
            break;
        case 3:
            generalize_evil_mode(node, p_node);
            //random_generate(p_node);
            play_sodoku(p_node);

            break;

        default:
            cout << "wrong input" << endl;
            break;
        }
        getchar();
        getchar();
        free_puzzel_node(p_node);
        //
    }
    return ok;
}

status check_win(puzzel_node p_node)
{
    for (int i = 0; i < p_node.size * p_node.size; i++)
        if (p_node.puzzel_desk[i] != p_node.answer[i])
            return wrong;
    return ok;
}

status correct_node(puzzel_node &p_node) //check if the current node have wrong cell
{
    int flag = 0;
    for (int i = 0; i < p_node.size * p_node.size; i++)
        if ((p_node.puzzel_desk[i] != p_node.answer[i]) && (p_node.puzzel_desk[i] != unassigned))
        {
            p_node.puzzel_desk[i] = unassigned;
            flag = 1;
        }
    if (flag)
        return wrong;
    else
        return ok;
}

status play_sodoku(puzzel_node &p_node)
{
    bool choice;
    puzzel_node player_node;
    copy_puzzel_node(p_node, player_node);
    int row, column;
    system("clear");
    show_puzzel_desk(player_node);
    do
    {
        system("clear");
        show_puzzel_desk(player_node);
        cout << "which position do you want to fill\nrow:\tcolumn:" << endl;
        cin >> row;
        cin >> column;
        if (p_node.puzzel_desk[(row - 1) * player_node.size + (column - 1)] != unassigned)
        {
            cout << "wrong input" << endl;
            getchar();
            getchar();
            continue;
        }
        system("clear");
        player_node.puzzel_desk[(row - 1) * player_node.size + (column - 1)] = selected;
        show_puzzel_desk(player_node);
        cout << "enter value" << endl;
        cin >> player_node.puzzel_desk[(row - 1) * player_node.size + (column - 1)];
        system("clear");
        show_puzzel_desk(player_node);
        cout << "do you want to check your answer?0/1" << endl;
        cin >> choice;
        if (choice)
        {
            if (correct_node(player_node) == ok)
                cout << "the current situation is right" << endl;
            else
                cout << "the node has been correct" << endl;
        }
    } while (check_win(player_node) == wrong);
    system("clear");
    show_puzzel_desk(player_node);
    cout << "you win" << endl;
    free_puzzel_node(player_node);
    getchar();
    getchar();
    return ok;
}

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
                    if ((current_node.puzzel_desk[(i - 1) * current_node.size + j - 1] == True) || (current_node.puzzel_desk[(i - 1) * current_node.size + j - 1] == False))
                        cout << current_node.puzzel_desk[(i - 1) * current_node.size + j - 1];
                    else if (current_node.puzzel_desk[(i - 1) * current_node.size + j - 1] == selected)
                        cout << '_';
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

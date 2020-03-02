#include "file_related.h"
void get_filename(char *filename)
{
    cout << "Input the file name please(no need to enter '.cnf')" << endl;
    cin >> filename;
}

status read_sodoku_cnf(cnf_node &node, char *filename, int size)
{
    FILE *fp;
    node.size = size;
    char filename_open[81];
    strcpy(filename_open, filename);
    strcat(filename_open, ".cnf");
    cout << filename << endl;
    if ((fp = fopen(filename_open, "r")) == NULL)
    {
        printf("The sodoku file doesn't exist\n");
        return wrong;
    }
    node.clauses_num = 4 * size * (size - 2) + 4 * Combination_count(size, size / 2 + 1) * size + 2 * Combination_count(size, 2) * (10 * size + 1);
    cout << node.clauses_num << endl;
    node.literals_num = size ^ 2 + 2 * Combination_count(size, 2) * (1 + 3 * size);
    int literal;
    vector<int> clause_store;
    for (int i = 0; i < node.clauses_num; i++)
    {
        while (1)
        {
            fscanf(fp, "%d", &literal);
            if (literal == 0)
            {
                node.matrix.push_back(clause_store);
                clause_store.clear();
                break;
            }
            clause_store.push_back(literal);
        }
    }
    fclose(fp);
    return ok;
}

status read_cnf_file(cnf_node &node, char *filename)
{
    FILE *fp;
    node.size = 0;
    char filename_open[81];
    strcpy(filename_open, filename);
    strcat(filename_open, ".cnf");
    if ((fp = fopen(filename_open, "r")) == NULL)
    {
        printf("The file doesn't exist\n");
        return wrong;
    }
    char flag;
    while (true)
    {
        flag = fgetc(fp);
        if (flag == 'p')
        {
            fscanf(fp, "%*s%d%d", &node.literals_num, &node.clauses_num);
            break;
        }
    }
    initialize_related_info(node);
    int literal;
    vector<int> clause_store;
    for (int i = 0; i < node.clauses_num; i++)
    {
        while (1)
        {
            fscanf(fp, "%d", &literal);
            if (literal == 0)
            {
                node.matrix.push_back(clause_store);
                clause_store.clear();
                break;
            }
            clause_store.push_back(literal);
        }
    }
    fclose(fp);
    return ok;
}

status show_cnf_node(cnf_node &my_node)
{
    int i, j;
    if (my_node.clauses_num == 0)
    {
        cout << "Input error" << endl;
        return wrong;
    }
    printf("clause num: %d literal num: %d*********************************************************\n", my_node.clauses_num, my_node.literals_num);
    for (i = 0; i < my_node.matrix.size(); i++)
    {
        for (j = 0; j < my_node.matrix[i].size(); j++)
        {
            cout << my_node.matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "print each node's weight*********************************************************" << endl;
    //print_weight(my_node);
    cout << "print each node's result*********************************************************" << endl;
    //print_result(my_node);
    return ok;
}

status store_time(char *filename, double time)
{
    FILE *fp;
    char store_file[81];
    strcpy(store_file, filename);
    strcat(store_file, ".res");
    fp = fopen(store_file, "a");
    if (fp == NULL)
        return wrong;
    fprintf(fp, "#t:%.0fms", time * 1000);
    fclose(fp);
    return ok;
}

status store_result(char *filename, cnf_node &node, int search_node)
{
    cout << "******************************enter the store result" << endl;
    FILE *fp;
    char store_file[81];
    strcpy(store_file, filename);
    strcat(store_file, ".res");
    fp = fopen(store_file, "w");
    if (fp == NULL)
        return overflow;
    if (node.size != -100)
    {
        fprintf(fp, "#the total search node is %d\n", search_node);
        fprintf(fp, "#result***********************************************\n");
        for (auto iterator = node.result_dict.begin(); iterator != node.result_dict.end(); iterator++)
        {
            fprintf(fp, "literal: %d\t", iterator->first);
            if (iterator->second == True)
                fprintf(fp, "True\n");
            else if (iterator->second == False)
                fprintf(fp, "False\n");
            else
                fprintf(fp, "Unassigned\n");
        }
    }
    else
    {
        fprintf(fp, "%d\n", node.size);
        for (int i = 1; i <= node.size; i++)
        {
            for (int j = 1; j <= node.size; j++)
                fprintf(fp, "%d\t%d\n", (i - 1) * node.size + j, node.result_dict[i * 10 + j]);
        }
    }
    fclose(fp);
    return ok;
}

status initialize_related_info(cnf_node &current_node)
{
    //new one
    for (int i = 1; i <= current_node.literals_num; i++)
    {
        current_node.result_dict[i] = unassigned;
        current_node.weight_dict[i] = (float *)malloc(2 * sizeof(float));
        current_node.weight_dict[i][positive] = -1;
        current_node.weight_dict[i][negative] = -1;
    }
    return ok;
}

void intialize_dict_according_to_three_digit(cnf_node &node, int size, int three_digit)
{
    int five_digit_p, five_digit_n, four_digit;
    int i;
    for (i = 1; i <= size; i++)
    {
        four_digit = three_digit * 10 + i;
        initialize_dict_by_number(node, four_digit);
        five_digit_p = four_digit * 10 + 1;
        initialize_dict_by_number(node, five_digit_p);
        five_digit_n = four_digit * 10;
        initialize_dict_by_number(node, five_digit_n);
    }
}

void initialize_dict_info(cnf_node &mynode, int size)
{
    //result dict
    int three_digit_row, three_digit_column;
    int i, j;
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            initialize_dict_by_number(mynode, 10 * i + j);
        }
    }
    for (i = 1; i <= size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            three_digit_row = 100 + i * 10 + j;
            three_digit_column = 200 + i * 10 + j;
            //row
            initialize_dict_by_number(mynode, three_digit_row);
            intialize_dict_according_to_three_digit(mynode, size, three_digit_row);
            //column
            initialize_dict_by_number(mynode, three_digit_column);
            intialize_dict_according_to_three_digit(mynode, size, three_digit_column);
        }
    }
    //cout << mynode.result_dict.size() << ' ' << mynode.weight_dict.size() << endl;
}

void initialize_weight_dict(cnf_node &node, int number)
{
    node.weight_dict[number] = (float *)malloc(2 * sizeof(float));
    node.weight_dict[number][positive] = -1;
    node.weight_dict[number][negative] = -1;
}

void initialize_dict_by_number(cnf_node &node, int number)
{
    node.result_dict[number] = unassigned;
    initialize_weight_dict(node, number);
}

void show_dict(cnf_node mynode)
{
    for (auto iterator = mynode.weight_dict.begin(); iterator != mynode.weight_dict.end(); iterator++)
        cout << iterator->first << " positive:" << iterator->second[positive] << " negative:" << iterator->second[negative] << endl;
}
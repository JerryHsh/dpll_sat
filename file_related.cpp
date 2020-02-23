#include "file_related.h"
#include "my_debug.h"
void get_filename(char *filename)
{
    cout << "Input the file name please(no need to enter '.cnf')" << endl;
    cin >> filename;
}

status initialize_related_info(cnf_node &current_node)
{
    //initiate the result list
    current_node.result = (value *)malloc((current_node.literals_num + 1) * sizeof(value));
    //initialize the weight list
    current_node.weight = (float **)malloc((current_node.literals_num + 1) * sizeof(float *));
    if (current_node.result == NULL || current_node.weight == NULL)
        return overflow;
    for (int i = 0; i <= current_node.literals_num; i++)
        current_node.result[i] = unassigned;
    for (int i = 0; i <= current_node.literals_num; i++)
    {
        current_node.weight[i] = (float *)malloc(2 * sizeof(float));
        current_node.weight[i][negative] = -1;
        current_node.weight[i][positive] = -1;
    }
    return ok;
}

status read_cnf_file(cnf_node &node, char *filename)
{
    FILE *fp;
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
    for (i = 0; i < my_node.matrix.size(); i++)
    {
        for (j = 0; j < my_node.matrix[i].size(); j++)
        {
            cout << my_node.matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "print each node's weight*********************************************************" << endl;
    print_weight(my_node);
    cout << "print each node's result*********************************************************" << endl;
    print_result(my_node);
    return ok;
}

status store_result(char *filename, double time)
{
    FILE *fp;
    char store_file[81];
    strcpy(store_file, filename);
    strcat(store_file, ".res");
    fp = fopen(store_file, "a");
    if (fp == NULL)
        return wrong;
    fprintf(fp, "t:%fms", time);
    fclose(fp);
    return ok;
}

status store_result(char *filename, cnf_node &node)
{
    FILE *fp;
    char store_file[81];
    strcpy(store_file, filename);
    strcat(store_file, ".res");
    fp = fopen(store_file, "w");
    if (fp == NULL)
        return overflow;
    int i;
    fprintf(fp, "result***********************************************\n");
    for (i = 1; i <= node.literals_num; i++)
    {
        fprintf(fp, "literal: %d\t", i);
        if (node.result[i] == True)
            fprintf(fp, "value: True\n");
        else if (node.result[i] == False)
            fprintf(fp, "value: False\n");
        else
            fprintf(fp, "value: unassigned\n");
    }
    fclose(fp);
    return ok;
}
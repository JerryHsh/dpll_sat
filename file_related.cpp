#include "file_related.h"

void get_filename(char *filename)
{
    cout << "Input the file name please(no need to enter '.cnf')" << endl;
    cin >> filename;
}

status read_cnf_file(cnf_node &node, char *filename)
{
    FILE *fp;
    char filename_open[81];
    strcpy(filename_open, filename);
    strcat(filename_open, ".cnf");
    if ((fp = fopen(filename_open, "r")) == NULL)
    {
        printf("The file doesn't exist");
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
    node.result = (value *)malloc(node.literals_num * sizeof(value));
    //initiate the result list
    for (int i = 0; i < node.literals_num; i++)
        node.result[i] = unassigned;
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

status show_cnf_file(cnf_node my_node)
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
    return ok;
}

status store_result(char *filename, double time)
{
    FILE *fp;
    strcat(filename, ".res");
    fp = fopen(filename, "w");
    if (fp == NULL)
        return wrong;
    fprintf(fp, "t:%fms", time);
    fclose(fp);
    return ok;
}
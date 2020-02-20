#include "definition.h"

status read_cnf_file(cnf_node &node)
{
    char name[30];
    cout << "Input the file name please" << endl;
    cin >> name;
    if ((fp = fopen(name, "r")) == NULL)
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
    return ok;
}

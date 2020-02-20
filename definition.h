#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef int status;

extern FILE *fp;

const status ok = 1;
const status wrong = 0;
const status overflow = -1;

typedef struct
{
    int literals_num;
    int clauses_num;
    vector<vector<int> > matrix;
} cnf_node;

status read_cnf_file(cnf_node &node);

#endif // !DEFINITION_H

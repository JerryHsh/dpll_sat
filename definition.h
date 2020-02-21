#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef int status;

const status ok = 1;
const status wrong = 0;
const status overflow = -1;

typedef int value;

const value True = 1;
const value False = 0;
const value unassigned = -1;

typedef int clause_status;
const clause_status empty = 0;
const clause_status unit = 1;
const clause_status normal = 2;

typedef int solution_status;
const solution_status satisfied=1;
const solution_status unsatisfied=0;

typedef struct
{
    int literals_num;
    int clauses_num;
    vector<vector<int>> matrix;
    value *result;
} cnf_node;

#endif // !DEFINITION_H

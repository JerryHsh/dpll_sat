#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

typedef int status;

const status ok = 1;
const status wrong = 0;
const status overflow = -1;

typedef int value;

const value True = 1;
const value False = 0;
const value unassigned = -1;

typedef int solution_status;

const solution_status satisfied = 1;
const solution_status unsatisfied = 0;

// 0 means positive 1 means negatice
const int positive = 0;
const int negative = 1;
typedef struct
{
    int literals_num;
    int clauses_num;
    vector<vector<int>> matrix;
    //value *result;               //an array store the current result begin with 1
    map<int, value> result_dict; //subsititute for result
    //float **weight;              //an 2darray store the current literal weight begin with 1
    map<int, float *> weight_dict;
    int size; //normal dpll the size is 0
} cnf_node;


typedef struct 
{
    value *puzzel_desk;
    int size;
}puzzel_node;


#endif // !DEFINITION_H

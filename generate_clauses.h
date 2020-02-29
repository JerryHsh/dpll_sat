#ifndef GENERATE_CLAUSES
#define GENERATE_CLAUSES

#include "file_related.h"
#include "definition.h"
#include <list>

status generate_clauses(char filename[81], int size); //store the clauses in filename file
void generate_by_rule1(FILE *fp, int size);           //generate clauses by rule 1
void generate_by_rule2(FILE *fp, int size);           //generate clauses by rule 2
void generate_by_rule3(FILE *fp, int size);           //generate clauses by rule 3
int reverse(int original, int size);//reverse the sequence number of the literal by size
int Combination_count(int N, int K);
int Combination_All(int Position, int Have_In, list<int> Have_Get, int length, int need_get, FILE *fp, int *Num_list);

#endif // !GENERATE_CLAUSES
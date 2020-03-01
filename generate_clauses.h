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
int Combination_All(int Position, int Have_In, list<int> Have_Get, int length, int need_get, FILE *fp, int *Num_list);
void rule3_gen_clauses(FILE *fp, int row_or_column, int line_a, int line_b, int size); //row is 1 and column is 2
int Combination_count(int n, int k);//count the combination 


#endif // !GENERATE_CLAUSES
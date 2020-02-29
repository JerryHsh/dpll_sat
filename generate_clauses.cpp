#include "generate_clauses.h"

status generate_clauses(char filename[81], int size) //store the clauses in filename file
{
    FILE *fp;
    strcat(filename, ".cnf");
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        cout << "overflow" << endl;
        return overflow;
    }
    generate_by_rule1(fp, size);
    generate_by_rule2(fp, size);
    //generate_by_rule3(fp, size);
    fclose(fp);
    return ok;
}

void generate_by_rule1(FILE *fp, int size) //generate clauses by rule 1
{
    int i, j;
    int first_num; //store the first var of the clause
    //row clauses
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 2; j++)
        {
            first_num = 10 * (i + 1) + (j + 1);
            fprintf(fp, "%d\t%d\t%d\t0\n", first_num, first_num + 1, first_num + 2);
            fprintf(fp, "%d\t%d\t%d\t0\n", first_num * -1, (first_num + 1) * -1, (first_num + 2) * -1);
        }
    }
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size - 2; i++)
        {
            first_num = 10 * (i + 1) + (j + 1);
            fprintf(fp, "%d\t%d\t%d\t0\n", first_num, (first_num + 10), (first_num + 20));
            fprintf(fp, "%d\t%d\t%d\t0\n", first_num * -1, (first_num + 10) * -1, (first_num + 20) * -1);
        }
    }
}

void generate_by_rule2(FILE *fp, int size) //generate clauses by rule 2
{
    int *num_list = (int *)malloc(sizeof(int) * size);
    int i, j;
    for (i = 0; i < size; i++)
    {
        num_list[i] = i + 1;
    }
    list<int> Have_Get;
    Combination_All(0, 0, Have_Get, size, size / 2 + 1, fp, num_list);
}

int Combination_count(int N, int K)
{
    if (K == 1)
        return N;
    else if (N == K || K == 0)
        return 1;
    else
        return Combination_count(N - 1, K - 1) + Combination_count(N - 1, K);
}

int Combination_All(int Position, int Have_In, list<int> Have_Get, int size, int need_get, FILE *fp, int *Num_list)
{
    if (Position > size)
        return 0;
    else if (need_get == Have_In)
    {
        for (int i = 0; i < size; i++) //row
        {
            for (auto iteral = Have_Get.begin(); iteral != Have_Get.end(); iteral++)
            {
                auto original_num = *iteral;
                fprintf(fp, "%d\t", 10 * (i + 1) + original_num);
            }
            fprintf(fp, "0\n");
        }
        for (int i = 0; i < size; i++) //row *-1
        {
            for (auto iteral = Have_Get.begin(); iteral != Have_Get.end(); iteral++)
            {
                auto original_num = *iteral;
                fprintf(fp, "%d\t", (10 * (i + 1) + original_num) * -1);
            }
            fprintf(fp, "0\n");
        }
        for (int j = 0; j < size; j++) //column
        {
            for (auto literal = Have_Get.begin(); literal != Have_Get.end(); literal++)
            {
                auto original_num = *literal;
                fprintf(fp, "%d\t", 10 * original_num + (j + 1));
            }
            fprintf(fp, "0\n");
        }
        for (int j = 0; j < size; j++) //column*-1
        {
            for (auto literal = Have_Get.begin(); literal != Have_Get.end(); literal++)
            {
                auto original_num = *literal;
                fprintf(fp, "%d\t", (10 * original_num + (j + 1)) * -1);
            }
            fprintf(fp, "0\n");
        }
    }
    else
    {
        Have_Get.push_back(Num_list[Position]);
        Combination_All(Position + 1, Have_In + 1, Have_Get, size, need_get, fp, Num_list);
        Have_Get.pop_back();
        Combination_All(Position + 1, Have_In, Have_Get, size, need_get, fp, Num_list);
    }
}

void generate_by_rule3(FILE *fp, int size)           //generate clauses by rule 3
{
    
}

int reverse(int original, int size)
{
    if (original <= 0)
    {
        cout << "wrong input" << endl;
        exit(wrong);
    }
    int i, j;
    i = original / 10;
    j = original % 10;
    return size*(i-1)+j;
}
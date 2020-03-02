#include "generate_clauses.h"

status generate_clauses(char filename[81], int size) //store the clauses in filename file
{
    FILE *fp;
    char filename_open[81];
    strcpy(filename_open, filename);
    strcat(filename_open, ".cnf");
    fp = fopen(filename_open, "w");
    if (fp == NULL)
    {
        cout << "overflow" << endl;
        return overflow;
    }
    generate_by_rule1(fp, size);
    generate_by_rule2(fp, size);
    generate_by_rule3(fp, size);
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

int Combination_count(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    else if (k == 1)
        return n;
    else
        return Combination_count(n - 1, k - 1) + Combination_count(n - 1, k);
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

void generate_by_rule3(FILE *fp, int size) //generate clauses by rule 3
{
    int i, j; // i is line_a j is line_b

    for (i = 1; i <= size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            rule3_gen_clauses(fp, 1, i, j, size); //row
            rule3_gen_clauses(fp, 2, i, j, size); //column
        }
    }
}

void rule3_gen_clauses(FILE *fp, int row_or_column, int line_a, int line_b, int size) //row is 1 and column is 2
{
    int i;
    int five_digit_p, five_digit_n, four_digit, three_digit;
    int line_a_num, line_b_num;
    three_digit = row_or_column * 100 + line_a * 10 + line_b;
    for (i = 1; i <= size; i++)
    {
        if (row_or_column == 1)
        {
            line_a_num = line_a * 10 + i;
            line_b_num = line_b * 10 + i;
        }
        else
        {
            line_a_num = 10 * i + line_a;
            line_b_num = 10 * i + line_b;
        }

        five_digit_p = row_or_column * 10000 + line_a * 1000 + line_b * 100 + i * 10 + 1; //positive one
        fprintf(fp, "%d\t%d\t0\n", line_a_num, five_digit_p * -1);
        fprintf(fp, "%d\t%d\t0\n", line_b_num, five_digit_p * -1);
        fprintf(fp, "%d\t%d\t%d\t0\n", (line_a_num) * -1, (line_b_num) * -1, five_digit_p);

        five_digit_n = row_or_column * 10000 + line_a * 1000 + line_b * 100 + i * 10; //negative one
        fprintf(fp, "%d\t%d\t0\n", (line_a_num) * -1, five_digit_n * -1);
        fprintf(fp, "%d\t%d\t0\n", (line_b_num) * -1, five_digit_n * -1);
        fprintf(fp, "%d\t%d\t%d\t0\n", (line_a_num), (line_b_num), five_digit_n);

        four_digit = row_or_column * 1000 + line_a * 100 + line_b * 10 + i; //four digit var
        fprintf(fp, "%d\t%d\t0\n", five_digit_p * -1, four_digit);
        fprintf(fp, "%d\t%d\t0\n", five_digit_n * -1, four_digit);
        fprintf(fp, "%d\t%d\t%d\t0\n", five_digit_p, five_digit_n, four_digit * -1);

        //three and four digit one
        //fprintf(fp, "%d\t%d\t0\n", four_digit, three_digit);
    }
    //three and four digit one
    //fprintf(fp, "%d\t", three_digit * -1);
    for (i = 1; i <= size; i++)
    {
        four_digit = row_or_column * 1000 + line_a * 100 + line_b * 10 + i;
        fprintf(fp, "%d\t", four_digit * -1);
    }
    fprintf(fp, "0\n");
    //fprintf(fp, "%d\t0\n", three_digit);
}

#include "dpll_solution.h"

int main()
{
    char filename[81]; //store the filename
    get_filename(filename);
    solver(filename);
    //char filename[81]="gen_test";
    //generate_clauses(filename, 4);
    return 0;
}

//#include "dpll_solution.h"
#include "generate_clauses.h"
int main()
{
    //char filename[81]; //store the filename
    //get_filename(filename);
    //solver(filename);
    char filename[81]="gen_test";
    generate_clauses(filename, 8);
    return 0;
}

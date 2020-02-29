#include "dpll_solution.h"

int main()
{
    char filename[81]; //store the filename
    get_filename(filename);
    cnf_node node;
    read_cnf_file(node,filename);
    solver(filename,node);
    //char filename[81]="gen_test";
    //generate_clauses(filename, 4);
    return 0;
}

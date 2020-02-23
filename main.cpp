#include "dpll_solution.h"


int main()
{
    //do preparation
    char filename[81];
    int search_node=0;
    double processing_time;
    time_t start, end;
    start = clock();
    get_filename(filename);
    cnf_node node;
    //test the function
    //end test
    //solution begin
    if (read_cnf_file(node, filename) == ok)
    {
        if (dpll_algorithm(node,filename,search_node)==satisfied)
              cout << "has running this function" << endl;
    }
    //end solution
    end = clock();
    processing_time = (double)(end - start) / CLOCKS_PER_SEC;
    store_time(filename, processing_time);
    return 0;
}

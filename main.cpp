#include"dpll_solution.h"

int main()
{
    //do preparation 
    char filename[81];
    double processing_time;
    time_t start,end;
    start=clock();
    get_filename(filename);
    cnf_node node;
    read_cnf_file(node,filename);
    //test the function
    show_cnf_node(node);
    calculate_weight(node);
    int new_unit_literal=render_new_unit(node);
    //update_by_unit(node,new_unit_literal);
    //show_cnf_node(node);
    //calculate_weight(node);
    //show_cnf_node(node);


    
    //end test
    //solution begin
    //end solution
    end=clock();
    processing_time=(double)(end-start)/CLOCKS_PER_SEC;
    store_result(filename,processing_time);
    return 0;
}

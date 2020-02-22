#include"file_related.h"
#include"clause_related.h"

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
    //show_cnf_file(node);
    //solution begin

    update_by_unit(node,4);
    show_cnf_file(node);
    cout<<node.clauses_num<<endl;
    //end solution
    end=clock();
    processing_time=(double)(end-start)/CLOCKS_PER_SEC;
    store_result(filename,processing_time);
    return 0;
}

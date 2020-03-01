#include "display.h"

int main()
{
    cout<<Combination_count(8,5)<<endl;
    if (display_choice() == False)
    {
        char filename[81]; //store the filename
        get_filename(filename);
        cnf_node node;
        read_cnf_file(node, filename);
        solver(filename, node);
    }
    else
    {
        int size;
        cnf_node node;
        char filename[81]="sodoku"; //store the filename
        cout<<"enter the size of the binary sodoku"<<endl;
        cin>>size;
        initialize_dict_info(node,size);
        generate_clauses(filename,size);
        read_sodoku_cnf(node,filename,size);
        solver(filename, node);
    }
    return 0;
}

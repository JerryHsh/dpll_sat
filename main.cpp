#include "display.h"

int main()
{
    srand((unsigned)time(NULL));
    int choice;
    while (1)
    {
        choice = display_choice();
        if (choice == 1)
        {
            char filename[81]; //store the filename
            while (1)
            {
                strcpy(filename, "");
                get_filename(filename);
                cnf_node node;
                read_cnf_file(node, filename);
                solver(filename, node);
                cout << "do you have another dpll problem 0/1" << endl;
                cin >> choice;
                if (choice == 0)
                    break;
            }
        }
        else if (choice == 2)
        {
            int size;
            puzzel_node p_node;
            while (1)
            {
                cnf_node node;
                char filename[81] = "sodoku"; //store the filename
                cout << "enter the size of the binary sodoku\n"
                     << "enter 0 to exit" << endl;
                cin >> size;
                if (size == 0)
                    break;
                else if (size % 2)
                {
                    cout << "wrong input" << endl;
                    continue;
                }
                //generate related clauses
                initialize_dict_info(node, size);
                generate_clauses(filename, size);
                read_sodoku_cnf(node, filename, size);
                solver(filename, node);
                //generate sodoku
                initialize_puzzel_node(p_node, size);
                read_sodoku_result(p_node, filename);
                cout << "how hard do you want?\n"
                     << "easy: 1\tmedium: 2\tevil: 3" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    generalize_easy_mode(node, p_node);
                    random_generate(p_node);
                    show_puzzel_desk(p_node);
                    break;
                case 2:
                    generalize_medium_mode(node, p_node);
                    random_generate(p_node);
                    show_puzzel_desk(p_node);
                    break;
                case 3:
                    generalize_evil_mode(node, p_node);
                    random_generate(p_node);
                    show_puzzel_desk(p_node);
                    break;

                default:
                    cout << "wrong input" << endl;
                    break;
                }
                free_puzzel_node(p_node);
                //
            }
        }
        else
        {
            break;
        }
    }
    cout << "always welcome" << endl;
    return 0;
}
/*
int main()
{
    srand((unsigned)time(NULL));
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
        char filename[81] = "sodoku"; //store the filename
        cout << "enter the size of the binary sodoku" << endl;
        cin >> size;
        initialize_dict_info(node, size);
        generate_clauses(filename, size);
        read_sodoku_cnf(node, filename, size);
        solver(filename, node);
        puzzel_node p_node;
        initialize_puzzel_node(p_node, size);
        read_sodoku_result(p_node, filename);
        generalize_easy_mode(node, p_node);
        show_puzzel_desk(p_node);
        read_sodoku_result(p_node, filename);
        generalize_medium_mode(node, p_node);
        show_puzzel_desk(p_node);
        read_sodoku_result(p_node, filename);
        generalize_evil_mode(node, p_node);
        show_puzzel_desk(p_node);
        cout << endl;
        random_generate(p_node);
        show_puzzel_desk(p_node);
        cout << endl;
        show_answer(p_node);
    }
    return 0;
}
*/
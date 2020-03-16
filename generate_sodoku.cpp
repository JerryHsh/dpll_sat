#include "generate_sodoku.h"

using namespace std;

status generalize_medium_mode(cnf_node default_node, puzzel_node &current_node)
{
    level_regulation mode;
    initialize_mode(mode, current_node.size, 2);
    cout << "medium mode line lower: " << mode.line_lower_bound << "\tmode total lower: " << mode.total_lower_bound << endl;
    //using randomize sequence to generlize the sodoku
    puzzel_node info_node;                                //this node use to store the information we get when the programme is running
    initialize_puzzel_node(info_node, current_node.size); //unassigned in this term means haven't been search,true means can be dug  false means can't be dug
    for (int current_num = 0; current_num < current_node.size * current_node.size; current_num++)
    {
        check_row_column(mode, current_node, info_node);
        if (info_node.puzzel_desk[current_num] == False)
            continue;
        if (check_info_node(info_node) == wrong)
            break;
        if (position_unique(default_node, current_node, current_num) == common)
        {
            info_node.puzzel_desk[current_num] = False;
        }
        else //the position is unique
        {
            int temp_value = current_node.puzzel_desk[current_num];
            current_node.puzzel_desk[current_num] = unassigned;
            if (check_total(mode, current_node) == wrong)
            {
                current_node.puzzel_desk[current_num] = temp_value;
                break;
            }
            info_node.puzzel_desk[current_num] = True;
        }
    }
    free_puzzel_node(info_node);
    cout << "meet expectation" << endl;
    return ok;
}

status generalize_evil_mode(cnf_node default_node, puzzel_node &current_node)
{
    level_regulation mode;
    initialize_mode(mode, current_node.size, 3);
    cout << "evil mode line lower: " << mode.line_lower_bound << "\tmode total lower: " << mode.total_lower_bound << endl;
    //using randomize sequence to generlize the sodoku
    puzzel_node info_node;                                //this node use to store the information we get when the programme is running
    initialize_puzzel_node(info_node, current_node.size); //unassigned in this term means haven't been search,true means can be dug  false means can't be dug
    for (int current_num = 0; current_num < current_node.size * current_node.size; current_num++)
    {
        check_row_column(mode, current_node, info_node);
        if (info_node.puzzel_desk[current_num] == False)
            continue;
        if (check_info_node(info_node) == wrong)
            break;
        if (position_unique(default_node, current_node, current_num) == common)
        {
            info_node.puzzel_desk[current_num] = False;
        }
        else //the position is unique
        {
            int temp_value = current_node.puzzel_desk[current_num];
            current_node.puzzel_desk[current_num] = unassigned;
            if (check_total(mode, current_node) == wrong)
            {
                current_node.puzzel_desk[current_num] = temp_value;
                break;
            }
            info_node.puzzel_desk[current_num] = True;
        }
    }
    free_puzzel_node(info_node);
    cout << "meet expectation" << endl;
    return ok;
}

status generalize_easy_mode(cnf_node default_node, puzzel_node &current_node) //generalize the easy mode of sodoku using randomizing
{
    level_regulation mode;
    initialize_mode(mode, current_node.size, 1);
    cout << "easy mode line lower: " << mode.line_lower_bound << "\tmode total lower: " << mode.total_lower_bound << endl;
    //using randomize sequence to generlize the sodoku
    puzzel_node info_node;                                //this node use to store the information we get when the programme is running
    initialize_puzzel_node(info_node, current_node.size); //unassigned in this term means haven't been search,true means can be dug  false means can't be dug
    int random_num = generate_random_int(current_node.size);
    while (1)
    {
        check_row_column(mode, current_node, info_node);
        if (check_info_node(info_node) == wrong)
            break;
        while (info_node.puzzel_desk[random_num] != unassigned)
            random_num = generate_random_int(current_node.size * current_node.size);
        if (position_unique(default_node, current_node, random_num) == common)
        {
            info_node.puzzel_desk[random_num] = False;
        }
        else //the position is unique
        {
            int temp_value = current_node.puzzel_desk[random_num];
            current_node.puzzel_desk[random_num] = unassigned;
            if (check_total(mode, current_node) == wrong)
            {
                current_node.puzzel_desk[random_num] = temp_value;
                break;
            }
            info_node.puzzel_desk[random_num] = True;
        }
    }
    free_puzzel_node(info_node);
    cout << "meet expectation" << endl;
    return ok;
}

status check_row_column(level_regulation mode, puzzel_node current_node, puzzel_node &info_node)
{
    int i;
    for (i = 0; i < current_node.size; i++) //check each row
    {
        if (check_column(mode, current_node, i, info_node) == wrong)
        {
            return wrong;
        }
    }
    for (i = 0; i < current_node.size; i++) //ceck each line
    {
        if (check_row(mode, current_node, i * current_node.size, info_node) == wrong)
        {
            return wrong;
        }
    }
    return ok;
}

status check_row(level_regulation mode, puzzel_node current_node, int begin, puzzel_node &info_node) //check the current line
{
    int count = 0; //count the space
    for (int i = 0; i < current_node.size; i++)
        if (current_node.puzzel_desk[i + begin] != unassigned)
            count++;
    //cout << "row count" << count << endl;
    if (count == mode.line_lower_bound)
        for (int i = 0; i < current_node.size; i++)
            if (info_node.puzzel_desk[i + begin] == unassigned) //bug here
                info_node.puzzel_desk[i + begin] = False;
    return ok;
}

status check_column(level_regulation mode, puzzel_node current_node, int begin, puzzel_node &info_node) //check the current row
{
    int count = 0; //count the space
    for (int i = 0; i < current_node.size; i++)
        if (current_node.puzzel_desk[i * current_node.size + begin] != unassigned)
            count++;
    if (count == mode.line_lower_bound)
        for (int i = 0; i < current_node.size; i++)
            if (info_node.puzzel_desk[i * current_node.size + begin] == unassigned)
                info_node.puzzel_desk[i * current_node.size + begin] = False;
    return ok;
}
status check_total(level_regulation mode, puzzel_node current_node) //check the total empty space
{
    //    cout << "enter check total" << endl;
    int count = 0; //count the space
    for (int i = 0; i < current_node.size * current_node.size; i++)
        if (current_node.puzzel_desk[i] != unassigned)
            count++;
    // cout << "the total not unassigned is :" << count << endl;
    if (count < mode.total_lower_bound)
        return wrong;
    else
        return ok;
}
/*
status check_status(level_regulation mode, puzzel_node current_node, puzzel_node &info_node) //check if the situation meet the requirment
{
    int i;
    for (i = 0; i < current_node.size; i++) //check each row
    {
        if (check_line(mode, current_node, i, info_node) == wrong)
        {
            cout << "line end" << endl;
            return wrong;
        }
    }
    for (i = 0; i < current_node.size; i++) //ceck each line
    {
        if (check_line(mode, current_node, i * current_node.size, info_node) == wrong)
        {
            cout << "row end" << endl;
            return wrong;
        }
    }
    if (check_total(mode, current_node) == wrong)
    {
        cout << "total end" << endl;
        return wrong;
    }
    return ok;
}
*/

//check if the given position can be dug postion is a continuous sequence begin with 0
//if it's unique return unique else return common if it had been dug return dug
//use default_node to store the rule of binary sodoku
unique_status position_unique(cnf_node default_node, puzzel_node &current_node, int position)
{
    puzzel_node node;
    copy_puzzel_node(current_node, node); //all the change happened in copy one
    if (node.puzzel_desk[position] == unassigned)
        return dug;
    else if (node.puzzel_desk[position] == True)
        node.puzzel_desk[position] = False;
    else
        node.puzzel_desk[position] = True;
    int i;
    for (i = 0; i < node.size * node.size; i++)
    {
        if (node.puzzel_desk[i] == True)
            update_by_unit(default_node, reverse_to_cr(i, node.size));
        else if (node.puzzel_desk[i] == False)
            update_by_unit(default_node, reverse_to_cr(i, node.size) * -1);
    }
    int search_node = 0;
    if (dpll_algorithm(default_node, NULL, search_node) == satisfied)
        return common;
    else
        return unique;
}

int reverse_to_cr(int num, int size) //return the number in row and column form
{
    //num is a sequence begin with 0
    return (num / size + 1) * 10 + num % size + 1;
}

void copy_puzzel_node(puzzel_node &src_node, puzzel_node &des_node)
{
    des_node.size = src_node.size;
    des_node.puzzel_desk = (value *)malloc(des_node.size * des_node.size * sizeof(value));
    des_node.answer = (value *)malloc(des_node.size * des_node.size * sizeof(value));
    for (int i = 0; i < des_node.size * des_node.size; i++)
    {
        des_node.puzzel_desk[i] = src_node.puzzel_desk[i];
        des_node.answer[i] = src_node.answer[i];
    }
}

void initialize_mode(level_regulation &mode, int size, int level) //store the mode information inside mode
{
    int rand_num = generate_random_int(size / 3 + 1) + 1;
    int i;
    mode.mode = level;
    if (mode.mode == 1) //easy mode
    {
        mode.line_lower_bound = size / 2;
        mode.total_lower_bound = size * size * 5 / 8 + rand_num;
    }
    else if (mode.mode == 2) //medium mode
    {
        mode.line_lower_bound = size / 3;
        mode.total_lower_bound = size * size * 3 / 8 + rand_num;
    }
    else if (mode.mode == 3) //evil mode
    {
        mode.line_lower_bound = 0;
        mode.total_lower_bound = rand_num * 2;
    }
    else
    {
        cout << "wrong input" << endl;
    }
}

status check_info_node(puzzel_node &info_node)
{
    int count = 0;
    int size = info_node.size;
    for (int i = 0; i < size * size; i++)
    {
        if (info_node.puzzel_desk[i] == unassigned)
            count++;
    }
    if (!count)
        return wrong;
    else
        return ok;
}
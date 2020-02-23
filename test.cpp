#include <iostream>
#include <vector>
#include <numeric>
#include<math.h>

using namespace std;

void remove_literal_from_clause(vector<int> &v, int literal) //remove the certain literal from the clause
{
    while (v.back() == literal)
        v.pop_back();
    for (auto i = v.begin(); i != v.end(); i++)
        if (*i == literal)
        {
            v.erase(i); //maybe it contain the same literal
            i = v.begin();
        }
    v.shrink_to_fit();
}

int main()
{

    double m=2;
    cout<<pow(m,-5)<<endl;
    vector<int> v;
    int i;
    for (i = 1; i <= 25; i++)
        v.push_back(i % 6);
    remove_literal_from_clause(v, 1);
    for (i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.shrink_to_fit();
    cout << v.capacity() << endl;
}
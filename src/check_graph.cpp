#include "check_graph.h"

using namespace std;

int check_loop(vector<vector<int>> table_length)
{
    for (int i = 0, n = table_length.size(); i < n; i++)
        if (table_length[i][i] != 0)
            return 1;
    return 0;
}
#include "check_graph.h"

using namespace std;

int check_loop(vector<vector<int>> table_length)
{
    for (int i = 0, n = table_length.size(); i < n; i++)
        if (table_length[i][i] != 0)
            return 1;
    return 0;
}

int connectivity(
        const vector<vector<int>> table_length, int cities, int main_peak)
{
    bool visit_top[cities];
    visit_top[main_peak] = true;
    for (size_t i = 0; i < table_length[main_peak].size(); ++i) {
        int to = table_length[main_peak][i];
        if (!visit_top[to])
            connectivity(table_length, cities, to);
    }
}
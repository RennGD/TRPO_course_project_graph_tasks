#include "check_graph.h"
#include <iostream>

using namespace std;

bool check_loop(vector<vector<int>> table_length)
{
    for (int i = 0, n = table_length.size(); i < n; i++)
        if (table_length[i][i] != 0)
            return true;
    return false;
}

bool connectivity(vector<vector<int>>& table_length, int main_peak)
{
    vector<bool> visit_top;
    visit_top.resize(table_length.size());
    search_connect(table_length, visit_top, main_peak);
    for (int i = 0, m = visit_top.size(); i < m; ++i) {
        if (!visit_top[i]) {
            return false;
        }
    }
    return true;
}

void search_connect(
        vector<vector<int>>& table_length,
        vector<bool>& visit_top,
        int main_peak)
{
    visit_top[main_peak] = true;
    for (int i = 0, m = table_length.size(); i < m; ++i) {
        if ((!visit_top[i]) && (table_length[main_peak][i] > 0))
            search_connect(table_length, visit_top, i);
    }
}
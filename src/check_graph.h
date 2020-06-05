#ifndef CHECK_GRAPH
#define CHECK_GRAPH

#include <vector>

using namespace std;

void search_connect(
        vector<vector<int>>& table_length,
        vector<bool>& visit_top,
        int main_peak);
bool connectivity(vector<vector<int>>& table_length, int main_peak);
bool check_loop(vector<vector<int>> table_length);

#endif
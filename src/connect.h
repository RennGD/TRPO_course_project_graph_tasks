#ifndef CONNECT
#define CONNECT

#include <vector>

using namespace std;

void input(
        int& main_peak, int& secondary_peak, vector<vector<int>>& table_length);
void output(vector<int> min, vector<int> max, int one_vertex, int one_edge);

#endif
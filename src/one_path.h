#ifndef ONE_PATH
#define ONE_PATH

#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int>
dijkstra_min(int cities, int main_peak, vector<vector<int>> table_length);
vector<int>
dijkstra_max(int cities, int main_peak, vector<vector<int>> table_length);

#endif

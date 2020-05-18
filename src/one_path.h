#ifndef ONE_PATH
#define ONE_PATH

#include <vector>
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

vector<int> DijkstraMin(
        int Cities,
        int MainPeak,
        vector<vector<int>> TableLength,
        vector<int> MinDist);
vector<int> DijkstraMax(
        int Cities,
        int MainPeak,
        vector<vector<int>> TableLength,
        vector<int> MaxDist);

#endif

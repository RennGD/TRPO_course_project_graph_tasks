#ifndef ONE_PATH
#define ONE_PATH

#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int>*
DijkstraMin(int Cities, int MainPeak, vector<vector<int>> TableLength);
vector<int>*
DijkstraMax(int Cities, int MainPeak, vector<vector<int>> TableLength);

#endif

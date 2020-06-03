#ifndef IN_OUT
#define IN_OUT

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

string getExePath();
int input(
        int& main_peak, int& secondary_peak, vector<vector<int>>& table_length);
int output(vector<int> min, vector<int> max, int one_vertex, int one_edge);

#endif
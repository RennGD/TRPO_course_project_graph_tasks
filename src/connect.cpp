#include "connect.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void input(
        int& main_peak, int& secondary_peak, vector<vector<int>>& table_length)
{
    int N, k, l;
    ifstream fin;

    fin.open("input.txt");
    fin >> N >> main_peak >> secondary_peak;

    table_length.resize(N);
    for (int i = 0, size = table_length.size(); i < size; i++) {
        table_length[i].resize(N);
    }

    while (fin) {
        fin >> k >> l;
        fin >> table_length[k][l];
        table_length[l][k] = table_length[k][l];
    }

    fin.close();
}

void output(vector<int> min, vector<int> max, int one_vertex, int one_edge)
{
    ofstream fout;

    fout.open("output.txt");

    fout << "Minimal path between given vertices:\n    ";
    for (int i = 0, m = min.size(); i < m; i++) {
        fout << min[i] << "--";
    }

    fout << "\n\nMaximal path between given vertices:\n    ";
    for (int i = 0, m = max.size(); i < m; i++) {
        fout << max[i] << "--";
    }

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "vertices: "
         << one_vertex;

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "edges: "
         << one_edge;

    fout.close();
}
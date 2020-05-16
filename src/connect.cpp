#include "connect.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void input(int& a, int& b, vector<vector<int>>& A)
{
    int N, k, l;
    ifstream fin;

    fin.open("input.txt");
    fin >> N >> a >> b;

    A.resize(N);
    for (int i = 0, size = A.size(); i < size; i++) {
        A[i].resize(N);
    }

    while (fin) {
        fin >> k >> l;
        fin >> A[k][l];
        A[l][k] = A[k][l];
    }

    fin.close();
}

void output(vector<int> Min, vector<int> Max, int one_vertex, int one_edge)
{
    ofstream fout;

    fout.open("output.txt");

    fout << "Minimal path between given vertices:\n    ";
    for (int i = 0, m = Min.size(); i < m; i++) {
        fout << Min[i] << "--";
    }

    fout << "\n\nMaximal path between given vertices:\n    ";
    for (int i = 0, m = Max.size(); i < m; i++) {
        fout << Max[i] << "--";
    }

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "vertices: "
         << one_vertex;

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "edges: "
         << one_edge;

    fout.close();
}
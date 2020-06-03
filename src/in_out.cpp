#include "in_out.h"

using namespace std;

string getExePath()
{
    string path;
    path.resize(1024);

    auto ret = readlink("/proc/self/exe", &path[0], path.size());
    path.resize(ret);
    return path;
}

int input(
        int& main_peak, int& secondary_peak, vector<vector<int>>& table_length)
{
    int N, k, l, x;
    ifstream fin;
    string path;
    path = getExePath();
    path = path.substr(0, path.find_last_of("/"));
    path = path.substr(0, path.find_last_of("/"));
    path += "/resourses/input.txt";

    fin.open(path);
    if (!(fin >> N)) {
        cerr << "Error number of vertices" << endl;
        return 1;
    }
    if (!(fin >> main_peak)) {
        cerr << "Error value of main_peak" << endl;
        return 1;
    }
    if (!(fin >> secondary_peak)) {
        cerr << "Error value of secondary_peak" << endl;
        return 1;
    }

    table_length.resize(N);
    for (int i = 0, size = table_length.size(); i < size; i++) {
        table_length[i].resize(N);
    }

    while (fin >> k >> l >> x) {
        table_length[l][k] = table_length[k][l] = x;
    }

    if (!fin.eof()) {
        cerr << "Error reading edges" << endl;
        return 1;
    }

    fin.close();

    return 0;
}

int output(vector<int> min, vector<int> max, int one_vertex, int one_edge)
{
    ofstream fout;
    string path;
    path = getExePath();
    path = path.substr(0, path.find_last_of("/"));
    path = path.substr(0, path.find_last_of("/"));
    path += "/resourses/output.txt";

    fout.open(path);

    fout << "Minimal path between given vertex and others:";
    fout << "\nvrtx";
    for (int i = 0, m = min.size(); i < m; i++) {
        fout << setw(3) << i;
    }
    fout << "\nlgth";
    for (int i = 0, m = min.size(); i < m; i++) {
        fout << setw(3) << min[i];
    }

    fout << "\n\nMaximal path between given vertex and others:";
    fout << "\nvrtx";
    for (int i = 0, m = max.size(); i < m; i++) {
        fout << setw(3) << i;
    }
    fout << "\nlgth";
    for (int i = 0, m = max.size(); i < m; i++) {
        fout << setw(3) << max[i];
    }

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "vertices: "
         << one_vertex;

    fout << "\n\nQuantity of paths between given vertices without repeating "
            "edges: "
         << one_edge;

    fout.close();

    return 0;
}
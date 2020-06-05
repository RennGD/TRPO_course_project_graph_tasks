#include "in_out.h"

#define PATH_LENGTH 1024

using namespace std;

#ifdef __unix__
string getExePath()
{
    string path;
    path.resize(PATH_LENGTH);

    auto ret = readlink("/proc/self/exe", &path[0], PATH_LENGTH);

    path.resize(ret);
    path = path.substr(0, path.find_last_of("\\/"));

    return path;
}
#endif
#ifdef _WIN32
string getExePath()
{
    WCHAR path[PATH_LENGTH];
    GetCurrentDirectoryW(PATH_LENGTH, path);
    wstring ws = path;
    string s(ws.begin(), ws.end());

    return s;
}
#endif

int input(
        int& main_peak, int& secondary_peak, vector<vector<int>>& table_length)
{
    int N, k, l, x;
    ifstream fin;
    string path;
    path = getExePath();
    path = path.substr(0, path.find_last_of("\\/"));

#ifdef __unix__
    path += "/resourses/input.txt";
#endif
#ifdef _WIN32
    path += "\\resourses\\input.txt";
#endif

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

    if (N < 1) {
        cerr << "Number of vertices mast be more 0";
        return 1;
    }
    if ((main_peak < 0) || (main_peak >= N)) {
        cerr << "Given main peak doesnt exist";
        return 1;
    }
    if ((secondary_peak < 0) || (secondary_peak >= N)) {
        cerr << "Given secondary peak doesnt exist";
        return 1;
    }

    table_length.resize(N);
    for (int i = 0, size = table_length.size(); i < size; i++) {
        table_length[i].resize(N);
    }

    while (fin >> k >> l >> x) {
        if ((k < 0) || (k >= N) || (l < 0) || (l >= N) || (x < 1)) {
            cerr << "Incorrect data when reading edges";
            return 1;
        }
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
    path = path.substr(0, path.find_last_of("\\/"));

#ifdef __unix__
    path += "/resourses/output.txt";
#endif
#ifdef _WIN32
    path += "\\resourses\\output.txt";
#endif

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
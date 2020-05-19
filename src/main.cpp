#include "all_path.h"
#include "connect.h"
#include "one_path.h"
#include <vector>

using namespace std;

int main()
{
    int a, b, one_vertex, one_edge;
    vector<vector<int>> A;
    vector<int> Min, Max;

    input(a, b, A);

    Min = DijkstraMin(A.size(), a, A);
    Max = DijkstraMax(A.size(), a, A);
    one_vertex = 0;
    one_edge = 0;

    output(Min, Max, one_vertex, one_edge);

    return 0;
}
#include "all_path.h"
#include "in_out.h"
#include "one_path.h"
#include <vector>

using namespace std;

int main()
{
    int main_peak, secondary_peak, one_vertex, one_edge;
    vector<vector<int>> table_length;
    vector<int> min, max;

    if (input(main_peak, secondary_peak, table_length))
        return 1;

    min = dijkstra_min(table_length.size(), main_peak, table_length);
    max = dijkstra_max(table_length.size(), main_peak, table_length);
    one_vertex = 0;
    one_edge = 0;

    if (output(min, max, one_vertex, one_edge))
        return 1;

    return 0;
}
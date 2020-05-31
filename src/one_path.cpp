#include "one_path.h"

vector<int>
dijkstra_min(int cities, int main_peak, vector<vector<int>> table_length)
{
    vector<int> min_dist;
    min_dist.resize(cities);
    bool visit_top[cities];
    for (int i = 0; i < cities; ++i) {
        if (!table_length[main_peak][i])
            min_dist[i] = INT_MAX;
        else
            min_dist[i] = table_length[main_peak][i];
        visit_top[i] = false;
    }

    min_dist[main_peak] = 0;
    int index = 0, u = 0;
    for (int i = 0; i < cities; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < cities; ++j) {
            if (!visit_top[j] and min_dist[j] < min) {
                min = min_dist[j];
                index = j;
            }
        }
        u = index;
        visit_top[u] = true;
        for (int j = 0; j < cities; ++j) {
            if (!visit_top[j] and table_length[u][j] != 0
                and min_dist[u] != INT_MAX
                and (min_dist[u] + table_length[u][j] < min_dist[j])) {
                min_dist[j] = min_dist[u] + table_length[u][j];
            }
        }
    }
    return min_dist;
}

vector<int>
dijkstra_max(int cities, int main_peak, vector<vector<int>> table_length)
{
    vector<int> max_dist;
    max_dist.resize(cities);
    bool visit_top[cities];
    for (int i = 0; i < cities; ++i) {
        if (!table_length[main_peak][i])
            max_dist[i] = INT_MIN;
        else
            max_dist[i] = table_length[main_peak][i];
        visit_top[i] = false;
    }

    max_dist[main_peak] = 0;
    int index = 0, u = 0;
    for (int i = 0; i < cities; ++i) {
        int max = -1;
        for (int j = 0; j < cities; ++j) {
            if (!visit_top[j] and max_dist[j] > max) {
                max = max_dist[j];
                index = j;
            }
        }
        u = index;
        visit_top[u] = true;
        for (int j = 0; j < cities; ++j) {
            if (!visit_top[j] and table_length[u][j] != 0
                and max_dist[u] != INT_MIN
                and (max_dist[u] + table_length[u][j] > max_dist[j])) {
                max_dist[j] = max_dist[u] + table_length[u][j];
            }
        }
    }
    return max_dist;
}
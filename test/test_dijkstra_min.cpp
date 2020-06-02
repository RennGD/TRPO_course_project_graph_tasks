#include "catch.hpp"
#include "one_path.h"

TEST_CASE("Check dijkstra min for correctness", "[dijkstra_min]")
{
    std::vector<vector<int>> v(2, vector<int>());
    std::vector<vector<int>> ve(3, vector<int>());
    std::vector<int> min_dist;

    min_dist.resize(2);
    v[0][0] = v[1][1] = min_dist[0] = 0;
    v[1][0] = v[0][1] = min_dist[1] = 5;

    REQUIRE(dijkstra_min(2, 0, v) == min_dist);

    v[1][0] = v[0][1] = min_dist[0] = 9;
    min_dist[1] = 0;

    REQUIRE(dijkstra_min(2, 1, v) == min_dist);

    min_dist.resize(3, 0);
    ve[2][2] = ve[0][0] = ve[1][1] = min_dist[0] = 0;
    ve[0][1] = ve[1][0] = min_dist[1] = 3;
    ve[0][2] = ve[2][0] = 8;
    ve[1][2] = ve[2][1] = 4;
    min_dist[2] = 7;

    REQUIRE(dijkstra_min(3, 0, ve) == min_dist);

    ve[0][1] = ve[1][0] = 9;
    min_dist[0] = 8;
    min_dist[1] = 4;
    min_dist[2] = 0;

    REQUIRE(dijkstra_min(3, 2, ve) == min_dist);
}

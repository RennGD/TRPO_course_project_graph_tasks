#include "catch.hpp"
#include "one_path.h"

TEST_CASE("Check dijkstra max for correctness", "[dijkstra_max]")
{
    std::vector<vector<int>> v;
    std::vector<vector<int>> ve;
    std::vector<int> max_dist;

    v.resize(2, vector<int>(2));
    max_dist.resize(2);
    v[0][0] = v[1][1] = max_dist[0] = 0;
    v[1][0] = v[0][1] = max_dist[1] = 5;
    max_dist[0] = 10;

    REQUIRE(dijkstra_max(2, 0, v) == max_dist);

    v[1][0] = v[0][1] = max_dist[0] = 9;
    max_dist[1] = 18;

    REQUIRE(dijkstra_max(2, 1, v) == max_dist);

    ve.resize(3, vector<int>(3));
    max_dist.resize(3);
    ve[0][2] = ve[2][0] = v[0][0] = v[1][1] = ve[2][2] = 0;
    ve[0][1] = ve[1][0] = max_dist[1] = 3;
    ve[1][2] = ve[2][1] = max_dist[0] = 6;
    max_dist[2] = 9;

    REQUIRE(dijkstra_max(3, 0, ve) == max_dist);

    v[0][2] = v[2][0] = 6;
    v[1][2] = v[2][1] = 0;
    max_dist[0] = 3;
    max_dist[1] = 6;
    max_dist[2] = 9;

    REQUIRE(dijkstra_max(3, 1, ve) == max_dist);
}

#include "catch.hpp"
#include "one_path.h"

TEST_CASE("Check dijkstra min for correctness", "[dijkstra_min]")
{
    std::vector<vector<int>> v;
    std::vector<int> min_dist;

    v.resize(2, vector<int>(2));
    min_dist.resize(2);
    v[0][0] = v[1][1] = min_dist[0] = 0;
    v[1][0] = v[0][1] = min_dist[1] = 5;

    REQUIRE(dijkstra_min(2, 0, v) == min_dist);

    v[1][0] = v[0][1] = min_dist[0] = 9;
    min_dist[1] = 0;

    REQUIRE(dijkstra_min(2, 1, v) == min_dist);

    v.resize(3, vector<int>(3));
    min_dist.resize(3,0);
    v[2][2] = v[0][0] = v[1][1] = min_dist[0] = 0;
    v[0][1] = v[1][0] = min_dist[1] = 3;
    v[0][2] = v[2][0] = 8;
    v[1][2] = v[2][1] = 4;
    min_dist[2] = 7;
    REQUIRE(dijkstra_min(3, 0, v) == min_dist);

    v[0][1] = v[1][0] = 9;
    min_dist[0] = 8;
    min_dist[1] = 4;
    min_dist[2] = 0;
    REQUIRE(dijkstra_min(3, 3, v) == min_dist);
}

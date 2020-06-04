#include "catch.hpp"
#include "check_graph.h"

TEST_CASE("Check connectivity for correctness", "[connectivity]")
{
    std::vector<vector<int>> v;
    std::vector<vector<int>> ve;

    v.resize(2, vector<int>(2));
    v[0][0] = v[1][1] = v[1][0] = v[0][1] = 0;

    REQUIRE(connectivity(v, 2, 0) == false);

    v[1][0] = v[0][1] = 5;

    REQUIRE(connectivity(v, 2, 1) == true);

    ve.resize(3, vector<int>(3));
    ve[0][2] = ve[2][0] = ve[0][0] = ve[1][1] = ve[2][2] = ve[1][2] = ve[2][1]
            = 0;
    ve[0][1] = ve[1][0] = 3;

    REQUIRE(connectivity(ve, 3, 0) == false);

    ve[1][2] = ve[2][1] = 6;

    REQUIRE(connectivity(ve, 3, 1) == true);
}

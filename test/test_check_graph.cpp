#include "catch.hpp"
#include "check_graph.h"

using namespace std;

TEST_CASE("Check connectivity for correctness", "[connectivity]")
{
    vector<vector<int>> v;
    vector<vector<int>> ve;

    v.resize(2, vector<int>(2));
    v[0][0] = v[1][1] = v[1][0] = v[0][1] = 0;

    REQUIRE(connectivity(v, 0) == false);

    v[1][0] = v[0][1] = 5;

    REQUIRE(connectivity(v, 0) == true);

    ve.resize(3, vector<int>(3));
    ve[0][2] = ve[2][0] = ve[0][0] = ve[1][1] = ve[2][2] = ve[1][2] = ve[2][1]
            = 0;
    ve[0][1] = ve[1][0] = 3;

    REQUIRE(connectivity(ve, 0) == false);

    ve[1][2] = ve[2][1] = 6;

    REQUIRE(connectivity(ve, 0) == true);
}

TEST_CASE("Test check_loop", "[check_loop]")
{
    vector<vector<int>> v;

    v = {{0}};
    REQUIRE(check_loop(v) == false);

    v = {{1}};
    REQUIRE(check_loop(v) == true);

    v = {{0, 1}, {1, 0}};
    REQUIRE(check_loop(v) == false);

    v = {{1, 1}, {1, 0}};
    REQUIRE(check_loop(v) == true);

    v = {{1, 1}, {1, 1}};
    REQUIRE(check_loop(v) == true);
}

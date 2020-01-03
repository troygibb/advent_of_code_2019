#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "libs/catch.hpp"
#include "day_3.cpp"

typedef vector<vector<string>> str_map;

TEST_CASE("String maps are computed", "create_wire_map")
{
  str_map base_map;
  SECTION("row")
  {

    vector<string> directions = {"R4"};
    str_map wire_map = {{"o", "-", "-", "-", "-"}};
    REQUIRE(create_wire_map(base_map, directions) == wire_map);
  }

  SECTION("column")
  {

    vector<string> directions = {"U4"};
    str_map wire_map = {{"|"}, {"|"}, {"|"}, {"|"}, {"o"}};
    REQUIRE(create_wire_map(base_map, directions) == wire_map);
  }

  SECTION("multi-directions")
  {

    vector<string> directions = {"U2", "R2"};
    str_map wire_map = {{"+", "-", "-"}, {"|"}, {"o"}};
    REQUIRE(create_wire_map(base_map, directions) == wire_map);
  }

  SECTION("cross itself")
  {

    vector<string> directions = {"U3", "R3", "D2", "L4"};
    str_map wire_map = {
        {"+", "-", "-", "-"},
        {"|", ".", ".", "|"},
        {"-", "|", "-", "-", "|"},
        {"o"}};
    REQUIRE(create_wire_map(base_map, directions) == wire_map);
  }
}
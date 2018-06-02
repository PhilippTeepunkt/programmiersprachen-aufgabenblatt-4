#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>

#include "List.hpp"

TEST_CASE("constructor and mainMethods","[List]")
{
    List<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size()==0);
}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
}

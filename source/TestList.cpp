#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>

#include "List.hpp"

TEST_CASE("constructor and mainGetter","[List]")
{
    List<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size()==0);
}

TEST_CASE("mainModifiers","[List]")
{
    SECTION("add an element with push_front")
    {
        List<int>list;
        list.push_front(42);
        REQUIRE(42 == list.front());
    }

    SECTION("add an element with push_back")
    {
        List<int>list2;
        list2.push_back(24);
        REQUIRE(24 == list2.back());
    }

    SECTION("remove an element with pop_front")
    {
        List<int>list3;
        list3.push_back(42);
        list3.push_back(24);
        list3.pop_front();
        REQUIRE(24 == list3.front());
    }

    SECTION("remove an element with pop_back")
    {   
        List<int>list4;
        list4.push_back(24);
        list4.pop_back();
        REQUIRE(list4.empty());
    }
}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
}

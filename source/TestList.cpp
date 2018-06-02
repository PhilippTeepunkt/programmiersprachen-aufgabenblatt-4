#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>

#include "List.hpp"

TEST_CASE("constructors and mainGetter","[List]")
{
    List<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size()==0);

    SECTION("copy constructor")
    {
        List<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);
        List<int> list2{list};
        REQUIRE(list==list2);
    }
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

    SECTION("should be empty after cleaning")
    {
        List<int> list5;
        list5.push_front(1);
        list5.push_front(2);
        list5.push_front(3);
        list5.push_front(4);
        list5.clear();
        REQUIRE(list5.empty());
    }
}

TEST_CASE ("iterators","[List]")
{
    SECTION("should be an empty range after default construction")
    {
        List<int> list6;
        auto b = list6.begin();
        auto e = list6.end();
        REQUIRE(b==e);
    }

    SECTION("provide access to the first element with begin")
    {
        List<int> list7;
        list7.push_front(42);
        REQUIRE(42==*list7.begin());
    }

}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
}

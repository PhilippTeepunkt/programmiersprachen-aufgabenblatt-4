#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

#include "List.hpp"

TEST_CASE("constructors and mainGetter","[List]")
{
    SECTION("size and empty")
    {
        List<int> list;
        REQUIRE(list.empty());
        REQUIRE(list.size()==0);
    }

    SECTION("copy constructor")
    {
        List<int> list2;
        list2.push_front(1);
        list2.push_front(2);
        list2.push_front(3);
        list2.push_front(4);
        List<int> list3{list2};
        REQUIRE(list2==list3);
    }

    SECTION("brace-enclosed")
    {
        List<int>list4{9,5,38,1000};
        REQUIRE(9==*list4.begin());
        REQUIRE(1000==list4.back());
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
        List<int>list5;
        list5.push_front(1);
        list5.push_front(2);
        list5.push_front(3);
        list5.push_front(4);
        list5.clear();
        REQUIRE(list5.empty());
    }


    SECTION("reverse list")
    {
        List<int> list6;
        list6.push_front(1);
        list6.push_front(2);
        list6.push_front(3);
        list6.push_front(4);   
        list6.reverse();
        REQUIRE(1==list6.front());
        REQUIRE(4==list6.back());
    }

    SECTION("return reverse list")
    {
        List<int> list7;
        list7.push_front(1);
        list7.push_front(2);
        list7.push_front(3);
        list7.push_front(4);
        list7.push_front(5);
        List<int>list8 = reverse(list7);
        REQUIRE(1==list8.front());
        REQUIRE(5==list8.back());
    }

    SECTION("sum")
    {
        auto list10 = List<int>{1,2,3,4,5} + List<int>{6,7,8,9};
        REQUIRE(1==list10.front());
        REQUIRE(9==list10.back());
        REQUIRE(9==list10.size());
    }
}

TEST_CASE ("iterators","[List]")
{
    SECTION("should be an empty range after default construction")
    {
        List<int> list;
        auto b = list.begin();
        auto e = list.end();
        REQUIRE(b==e);
    }

    SECTION("provide access to the first element with begin")
    {
        List<int> list2;
        list2.push_front(42);
        REQUIRE(42==list2.front());
    }

}

TEST_CASE ("copys","[List]")
{
    SECTION("std::copy")
    {
        List<int> list1;
        list1.push_front(1);
        list1.push_front(2);
        list1.push_front(3);
        list1.push_front(4);
        list1.push_front(5);

        std::vector<int> vec(5);
        std::copy(list1.begin(),list1.end(),vec.begin());

        REQUIRE(5==*vec.begin());
        REQUIRE(1==vec.back());
    }

    SECTION("assignment operator")
    {
        List<int> list1;
        list1.push_back(1);
        list1.push_back(2);
        list1.push_back(3);
        list1.push_back(4);
        list1.push_back(5);

        List<int> list2;
        list2.push_back(6);
        list2.push_back(7);
        list2.push_back(8);

        list2=list1;
        REQUIRE(1==list2.front());
        REQUIRE(5==list2.back());
    }

    SECTION("move constructor")
    {
        List<int> list{1,2,3,4};
        List<int> list2 = std::move(list);
        REQUIRE(0==list.size());
        REQUIRE(list.empty());
        REQUIRE(4==list2.size());
    }
}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc,argv);
}

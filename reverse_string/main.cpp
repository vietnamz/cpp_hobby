#include <iostream>
#include <lest.hpp>
#include <algorithm>

using namespace std;


void reverse(string& str)
{
    // reverse the input string in place
    int low = 0;
    int hi = str.size()-1;
    while ( hi > low )
    {
        swap(str[hi], str[low]);
        hi--;
        low++;
    }
}


// tests

const lest::test tests[] = {
        {CASE("empty string") {
            const string expected;
            string actual;
            reverse(actual);
                    EXPECT(actual == expected);
        }},
        {CASE("single character string") {
                 const string expected("A");
                 string actual("A");
                 reverse(actual);
                         EXPECT(actual == expected);
             }},
        {CASE("longer string") {
                 const string expected("EDCBA");
                 string actual("ABCDE");
                 reverse(actual);
                         EXPECT(actual == expected);
             }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
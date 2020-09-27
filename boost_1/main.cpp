#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t changePossibilities(int amountLeft,
                                  const vector<int>& denominations,
                                  size_t currentIndex = 0)
{

    // base cases:
    // we hit the amount spot on. yes!
    if (amountLeft == 0) {
        return 1;
    }

    // we overshot the amount left (used too many coins)
    if (amountLeft < 0) {
        return 0;
    }

    // we're out of denominations
    if (currentIndex == denominations.size()) {
        return 0;
    }

    cout << "checking ways to make " << amountLeft << " with [";
    for (size_t i = currentIndex; i < denominations.size(); ++i) {
        if (i > currentIndex) {
            cout << ", ";
        }
        cout << denominations[i];
    }
    cout << "]" << endl;

    // choose a current coin
    int currentCoin = denominations[currentIndex];

    // see how many possibilities we can get
    // for each number of times to use currentCoin
    size_t numPossibilities = 0;
    while (amountLeft >= 0) {
        numPossibilities += changePossibilities(amountLeft,
                                                       denominations, currentIndex + 1);
        amountLeft -= currentCoin;
        cout << "amountLeft=" << amountLeft << " numPossibilities=" << numPossibilities << endl;
    }

    return numPossibilities;
}
// tests

const lest::test tests[] = {
        {CASE("sample input") {
            const size_t actual = changePossibilities(4, {1, 2, 3});
            const size_t expected = 4;
                    EXPECT(actual == expected);
        }},
/*
        {CASE("one way to make zero cents") {
                 const size_t actual = changePossibilities(0, {1, 2});
                 const size_t expected = 1;
                         EXPECT(actual == expected);
             }},

        {CASE("no ways if no coins") {
                 const size_t actual = changePossibilities(1, {});
                 const size_t expected = 0;
                         EXPECT(actual == expected);
             }},

        {CASE("big coin value") {
                 const size_t actual = changePossibilities(5, {25, 50});
                 const size_t expected = 0;
                         EXPECT(actual == expected);
             }},

        {CASE("big target amount") {
                 const size_t actual = changePossibilities(50, {5, 10});
                 const size_t expected = 6;
                         EXPECT(actual == expected);
             }},

        {CASE("change for one dollar") {
                 const size_t actual = changePossibilities(100, {1, 5, 10, 25, 50});
                 const size_t expected = 292;
                         EXPECT(actual == expected);
             }},*/
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
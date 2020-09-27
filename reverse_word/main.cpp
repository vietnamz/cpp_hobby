#include <iostream>

// C++11 lest unit testing framework
#include <lest.hpp>

using namespace std;


const char SPACE = ' ';
const char LAST_DELIM = '\0';
void reverseWords(string& message)
{
    vector<string> words;
    // decode the message by reversing the words
    string iterWord;
    for( const char c : message )
    {
        if ( c == SPACE ) {
            words.insert( words.begin(), iterWord);
            iterWord = string();
        }
        else
        {
            iterWord.push_back(c);
        }
    }
    string result;
    for( const string s : words )
    {
        result += s;
    }
    message = result;
}


















// tests

const lest::test tests[] = {
        {CASE("one word") {
            const string expected = "vault";
            string actual = "vault";
            reverseWords(actual);
            EXPECT(actual == expected);
        }},
        {CASE("two words") {
            const string expected = "cake thief";
            string actual = "thief cake";
            reverseWords(actual);
            EXPECT(actual == expected);
        }},
        {CASE("three words") {
            const string expected = "get another one";
            string actual = "one another get";
            reverseWords(actual);
            EXPECT(actual == expected);
        }},
        {CASE("multiple words same length") {
            const string expected = "the cat ate the rat";
            string actual = "rat the ate cat the";
            reverseWords(actual);
            EXPECT(actual == expected);
        }},
        {CASE("multiple words different lengths") {
            const string expected = "chocolate bundt cake is yummy";
            string actual = "yummy is cake bundt chocolate";
            reverseWords(actual);
            EXPECT(actual == expected);
        }},
        {CASE("empty string") {
            const string expected;
            string actual;
            reverseWords(actual);
            EXPECT(actual == expected);
        }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
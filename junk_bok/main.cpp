#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>
#include <sstream>
#include <string>

/*
 * space : O(n + n ) = O(2N) = Q(n)
 * time :Q(n + n + n ) = O(3n) = O(n)
 */
std::vector<std::string> sortedJunkBoxes( int numOfBoxes, const std::vector<std::string>& boxes )
{
    std::unordered_map<std::string, std::string> cache;
    std::vector<std::string> result;
    for(std::string box : boxes ) {
        size_t position = box.find( ' ' );
        std::string identifier = box.substr(0, position);
        std::cout << "identifier " << identifier << std::endl;
        std::string version = box.substr(position + 1, box.size() );
        std::cout << "version " << version << std::endl;
        std::pair<std::string, std::string> pair = std::make_pair(identifier, version);
        cache.insert(pair);
    }
    std::string numericOnly("\\d+");
    std::string alphaString("[A-Za-z]+");
    // older box have the english string.
    // regex = '[A-Za-Z]+'
    // newer box has the positive integer.
    // regex = '\d+'
    std::unordered_map<std::string, std::string>::const_iterator iter = cache.cbegin();
    while( iter != cache.cend() )
    {
        // if we only have numeric this is a newer box.
        if ( std::regex_match(iter->second, std::regex(alphaString) ) )
        {
            result.push_back(iter->first + " " + iter->second);
        }
        iter++;
    }
    iter = cache.cbegin();
    while( iter != cache.cend() )
    {
        // if we only have numeric this is a newer box.
        if ( std::regex_match(iter->second, std::regex(numericOnly) ) )
        {
            result.push_back(iter->first + " " + iter->second);
        }
        iter++;
    }
    std::sort(cache.begin(), cache.end(), [=](std::pair<std::string, std::string> first, std::pair<std::string, std::string> second ) {
        bool bothDigit = std::regex_match(first.first, std::regex(numericOnly) ) & std::regex_match(first.first, std::regex(numericOnly) );
        bool bothAlpha = std::regex_match(first.first, std::regex(numericOnly) ) & std::regex_match(first.first, std::regex(numericOnly) );
        if ( bothDigit )
        {
        }
        else if ( bothAlpha )
        {
            return  [=]() -> bool {
                if ( first.second  > second.second )
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }();
        }
        else
        {
           if ( std::regex_match(first.first, std::regex(numericOnly) ) )
           {
               return true;
           }
           else{
               return false;
           }
        }
    });
    return result;
}
int main() {
    // input

    int numOfBoxes = 3;
    std::vector<std::string> boxes = { "8AB749171 ab", "8AB749172 1890", "8AB749173 cdaf"};

    std::vector<std::string> sortedBoxes = sortedJunkBoxes(numOfBoxes, boxes);
    for( auto box : sortedBoxes )
    {
        std::cout << "Box is " << box << std::endl;
    }
    return 0;
}
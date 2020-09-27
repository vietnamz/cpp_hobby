#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <string>

typedef std::map<std::string, std::vector<std::string>> HobbiesMap;

void increment(int* array, int index)
{
    array[index]++;
    int a = (*(array + index))++;
}
std::vector<std::string> findAllHobbyists(const std::string& hobby, const HobbiesMap& hobbies)
{
    std::vector<std::string> result;
    for(auto iter = hobbies.cbegin(); iter != hobbies.cend(); iter++ )
    {
        std::string name = iter->first;
        std::vector hisHobbies  = iter->second;
        for(auto item = hisHobbies.cbegin(); item != hisHobbies.cend(); item++)
        {
            if ( *item == hobby)
            {
                result.push_back(name);
                break;
            }
        }
    }
    return result;
}

int main()
{
    HobbiesMap hobbies
            {
                    {"Steve", {"Fashion", "Piano", "Reading"}},
                    {"Patty", {"Drama", "Magic", "Pets"}},
                    {"Chad", {"Puzzles", "Pets", "Yoga"}}
            };

    std::vector<std::string> hobbyists = findAllHobbyists("Yoga", hobbies);
    for (std::string hobbyist: hobbyists)
    {
        std::cout << hobbyist << std::endl;
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <utility>

using namespace std;

bool isAnagram( string s1, string s2)
{
    if ( s1.size() != s2.size() )
    {
        return false;
    }
    int idx1 = 0;
    int idx2 = s2.size() - 1;
    while( idx1 <= idx2 )
    {
        if( s1[idx1] != s2[idx2])
        {
            return false;
        }
        idx1++;
        idx2--;
    }
    return true;
}
vector<string> getSubStrings(string s)
{
    assert( s.size() != 0);
    vector<string> result;
    for(int i = 0; i < s.size(); ++i)
    {
        for ( int len = 1; len <= s.size() - i; ++len )
        {
            result.push_back(s.substr(i, len));
        }
    }
    for( string s : result )
    {
        cout << s << endl;
    }
    return result;
}
// Complete the sherlockAndAnagrams function below.
struct pair_hash {
    template<typename T1, typename T2>
    size_t operator()(pair<T1,T2>const &pair) const
    {
        size_t h1 = std::hash<T1>()(pair.first);
        size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    };
};
int sherlockAndAnagrams(string s) {
    const vector<string> substrings= getSubStrings(s);
    unordered_set<size_t> caches;
    for( int i = 0; i < substrings.size(); ++i)
    {
        for( int j = i + 1; j < substrings.size(); ++j)
        {
            if ( isAnagram(substrings[i], substrings[j]))
            {
               size_t hashString = std::hash<string>{}(substrings[i]) | std::hash<string>{}(substrings[j]);
               cout << "hashString is " << hashString << " first str " << substrings[i] << " second str " << substrings[j] << endl;
               if ( caches.find(hashString) == caches.end()) 
               {
                   caches.insert(hashString);
               }
            }
        }
    }
    return caches.size();
}

int main()
{
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << "\n";
    }
    return 0;
}


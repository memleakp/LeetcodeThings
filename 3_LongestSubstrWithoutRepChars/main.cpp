/**
 * Problem 3
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <cassert>

class Solution
{
public:
    // return a length of the longest substring without
    // repeating characters
    //
    // this solution is not optimal, but it works
    int lenght_of_longest_substring(const std::string& s)
    {
        if (s.size() == 0) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }

        std::unordered_set<char> entries{};
        int max_size = 0;
        int curr_size = 0;

        for (std::size_t i = 0; i < s.size() - 1; ++i) {
            const char& curr_ch = s[i];
            entries.insert(curr_ch);
            ++curr_size;
            for (std::size_t j = i + 1; j < s.size(); ++j) {
                const char& ch_to_compare = s[j];
                if (entries.find(ch_to_compare) != entries.end()) {
                    break;
                }
                entries.insert(ch_to_compare);
                ++curr_size;
            }
            if (curr_size > max_size) {
                max_size = curr_size;
            }
            curr_size = 0;
            entries.clear();
        }

        return max_size;
    }
};

int main()
{
    Solution sol{};

    assert(sol.lenght_of_longest_substring("abcabcbb") == 3);
    assert(sol.lenght_of_longest_substring("bbbbb") == 1);
    assert(sol.lenght_of_longest_substring("pwwkew") == 3);
    assert(sol.lenght_of_longest_substring("aab") == 2);
    assert(sol.lenght_of_longest_substring("dvdf") == 3);
    assert(sol.lenght_of_longest_substring("d") == 1);

    return 0;
}

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 */

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return std::vector<int>{i, j};   
                }
            }          
        }
        return std::vector<int>{-1, -1};
    }

    std::vector<int> twoSumWithHashMap(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> storage{}; 
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = storage.find(target - nums[i]);
            if (it != storage.end())
            {
                std::pair<int, int> value = *it;
                return std::vector<int>{value.second, i};
            }
            storage[nums[i]] = i;
        }
        return std::vector<int>{-1, -1};
    }
};

void PrintVector(const std::vector<int>& v)
{
    std::cout << "Vector{ ";
    for (const auto& entry : v)
    {
        std::cout << entry << ' '; 
    }
    std::cout << '}';
}

int main()
{
    Solution sl{};
    { // Example 1
        std::vector<int> input{ 2, 7, 11, 15 };
        int target = 9;
        std::vector<int> got1{ sl.twoSum(input, target) };
        std::vector<int> got2{ sl.twoSumWithHashMap(input, target) };
        assert(got1 == want);
        assert(got2 == want);
    }
    { // Example 2
        std::vector<int> input{ 3, 2, 4 };
        int target = 6;
        std::vector<int> want{ 1, 2 };
        assert(sl.twoSum(input, target) == want);
        assert(sl.twoSumWithHashMap(input, target) == want);
    }
    { // Example 3
        std::vector<int> input{ 3, 3 };
        int target = 6;
        std::vector<int> want{ 0, 1 };
        assert(sl.twoSum(input, target) == want);
        assert(sl.twoSumWithHashMap(input, target) == want);
    }
    std::cout << "Problem 1: All tests are completed successfuly" << std::endl;
}

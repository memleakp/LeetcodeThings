/// Problem 4

#include <vector>
#include <iostream>
#include <cassert>

class Solution
{
public:
    static double find_median_sorted_arrays(std::vector<int>&& nums1, std::vector<int>&& nums2)
    {
        // simple solution:
        // step 1: merge to vectors to one
        // step 2: return vec[size/2] if size is not even, (vec[size/2] + vec[size/2+1])/2.0 otherweise

        std::vector<int> merged_nums{};
        std::size_t nums1_sz = nums1.size();
        std::size_t nums2_sz = nums2.size();

        for (std::size_t idx1 = 0, idx2 = 0; idx1 < nums1_sz || idx2 < nums2_sz;) {
            if (idx1 < nums1_sz and idx2 < nums2_sz) {
                merged_nums.push_back(nums1[idx1] < nums2[idx2] ? nums1[idx1++] : nums2[idx2++]);
            } else {
                merged_nums.push_back(idx1 < nums1_sz ? nums1[idx1++] : nums2[idx2++]);
            }
        }

        if (merged_nums.empty()) {
            return 0.0;
        }
        std::size_t merged_sz = merged_nums.size();
        return merged_sz % 2 != 0 ? merged_nums[merged_sz / 2] : (merged_nums[merged_sz / 2] + merged_nums[merged_sz / 2 - 1]) / 2.0;
    }
};

int main()
{
    assert(Solution::find_median_sorted_arrays({1, 3}, {2}) == 2.0);
    assert(Solution::find_median_sorted_arrays({1, 2}, {3, 4}) == 2.5);
    assert(Solution::find_median_sorted_arrays({1}, {}) == 1.0);
}
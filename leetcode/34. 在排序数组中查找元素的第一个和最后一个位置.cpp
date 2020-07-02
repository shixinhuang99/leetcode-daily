/*
 * @Author       : ApassEr
 * @Date         : 2020-07-02 14:06:28
 * @LastEditTime : 2020-07-02 14:23:53
 * @Description  : 34. 在排序数组中查找元素的第一个和最后一个位置
 * @Algorithm    : 二分查找/STL
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        auto a = equal_range(nums.begin(), nums.end(), target);
        if (a.first == a.second) {
            return ans;
        }
        ans[0] = (int)(a.first - nums.begin());
        ans[1] = (int)(a.second - nums.begin()) - 1;
        return ans;
    }
};

class Solution {
public:
    int lowerBound(vector<int>& vi, int key) {
        int first = 0;
        int len = vi.size();
        int half, mid;
        while (len > 0) {
            half = len >> 1;
            mid = first + half;
            if (vi[mid] < key) {
                first = mid + 1;
                len = len - half - 1;
            } else {
                len = half;
            }
        }
        return first;
    }

    int upperBound(vector<int>& vi, int key) {
        int first = 0;
        int len = vi.size();
        int half, mid;
        while (len > 0) {
            half = len >> 1;
            mid = first + half;
            if (vi[mid] <= key) {
                first = mid + 1;
                len = len - half - 1;
            } else {
                len = half;
            }
        }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = lowerBound(nums, target);
        ans[1] = upperBound(nums, target);
        if (ans[0] == ans[1]) {
            return {-1, -1};
        }
        ans[1] -= 1;
        return ans;
    }
};
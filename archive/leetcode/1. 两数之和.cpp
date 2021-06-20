/*
 * @Author       : ApassEr
 * @Date         : 2020-03-17 17:49:35
 * @LastEditTime : 2020-03-17 18:02:07
 * @Description  : 1. Two Sum
 * 一遍哈希
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b(2, 0);
        map<int, int>::iterator it;
        for (int i = 0; i < (int)nums.size(); ++i) {
            it = a.find(target - nums[i]);
            if (it != a.end()) {
                b[1] = i;
                b[0] = it->second;
                break;
            }
            a.insert(pair<int, int> (nums[i], i));
        }
        return b;
    }
};
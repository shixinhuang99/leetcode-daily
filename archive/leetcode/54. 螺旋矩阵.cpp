/*
 * @Author       : ApassEr
 * @Date         : 2020-06-06 00:44:55
 * @LastEditTime : 2020-06-06 00:47:36
 * @Description  : 54. 螺旋矩阵
 * @Algorithm    : 模拟
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty()) {
            return v;
        }
        int l = 0;
        int r = matrix[0].size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        int max = matrix.size() * matrix[0].size();
        while (max > 0) {
            for (int i = l; i <= r && max > 0; ++i) {
                v.push_back(matrix[t][i]);
                --max;
            }
            ++t;
            for (int i = t; i <= b && max > 0; ++i) {
                v.push_back(matrix[i][r]);
                --max;
            }
            --r;
            for (int i = r; i >= l && max > 0; --i) {
                v.push_back(matrix[b][i]);
                --max;
            }
            --b;
            for (int i = b; i >= t && max > 0; --i) {
                v.push_back(matrix[i][l]);
                --max;
            }
            ++l;
        }
        return v;
    }
};
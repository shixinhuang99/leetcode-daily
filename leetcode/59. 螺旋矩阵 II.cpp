/*
 * @Author       : ApassEr
 * @Date         : 2020-06-18 16:29:08
 * @LastEditTime : 2020-06-18 16:43:27
 * @Description  : 59. 螺旋矩阵 II
 * @Algorithm    : 模拟
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vvi(n, vector<int>(n));
        int init = 1;
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        while (init <= n * n) {
            for (int i = left; i <= right; ++i) {
                vvi[top][i] = init++;
            }
            ++top;
            for (int i = top; i <= bottom; ++i) {
                vvi[i][right] = init++;
            }
            --right;
            for (int i = right; i >= left; --i) {
                vvi[bottom][i] = init++;
            }
            --bottom;
            for (int i = bottom; i >= top; --i) {
                vvi[i][left] = init++;
            }
            ++left;
        }
        return vvi;
    }
};
/*
** 公式法：
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vvi(n, vector<int>(n));
        auto foo = [n] (int i, int j) -> int {
            int q = min(i, min(j, min(n - i + 1, n - j + 1)));
            int Aq = 4 * (n - 2 * q + 1);
            int Sq_1 = (4 * (q - 1)) * (n - (q - 1));
            int dit = i + j - 2 * q + 1;
            int ans;
            if (i <= j) {
                ans = Sq_1 + dit;
            } else {
                ans = Sq_1 + Aq - dit + 2;
            }
            return ans;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vvi[i][j] = foo(i + 1, j + 1);
            }
        }
        return vvi;
    }
};
 */
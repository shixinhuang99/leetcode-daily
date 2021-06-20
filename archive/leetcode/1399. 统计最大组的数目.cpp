class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int, int> m;
    int maxVal = 0;
    for (int i = 1; i <= n; i++) {
      int key = 0;
      int _i = i;
      while (_i) {
        key += _i % 10;
        _i /= 10;
      }
      m[key]++;
      maxVal = max(m[key], maxVal);
    }
    int res = 0;
    for (auto item : m) {
      if (item.second == maxVal) {
        res++;
      }
    }
    return res;
  }
};
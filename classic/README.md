# DP
## 求最长(上升/不下降/下降/不上升)子序列
### 洛谷 p1020
a为给定序列，全置为一个极小值  
最长不上升子序列：`upper_bound()`  
最长下降子序列：`lower_bound()`
```cpp
vector<int> dp(a.size() + 1, -1);
for (int i = 0; i < (int)a.size(); ++i) {
    *upper_bound(dp.begin(), dp.end(), a[i], greater<int>()) = a[i];
}
```
同上，但全置为一个极大值  
最长不下降子子序列：`upper_bound()`  
最长上升子序列：`lower_bound()`
```cpp
dp.assign(dp.size(), 1e6);
for (int i = 0; i < (int)a.size(); ++i) {
    *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
}
```
# 数学
### Dilworth定理
链的最少划分数 = 反链的最长长度  
例：8 5 2 7 6 4 3 1  
最长不上升子序列的划分数：{8,7,6,4,3,1},{5,2} -> 2  
最长上升子序列的长度：{2,7} -> 2
/*
 * @Author       : ApassEr
 * @Date         : 2020-03-15 17:24:53
 * @LastEditTime : 2020-03-15 19:24:41
 * @Description  : P1015 回文数
 * 模拟，高精度
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> m;
    int hex[6] = {10, 11, 12, 13, 14, 15};
    size_t sSize = s.size();
    for (size_t i = 0; i != sSize; ++i) {
        if (isalpha(s[i])) {
            toupper(s[i]);
            m.push_back(hex[s[i] - 'A']);
        } else {
            m.push_back(s[i] - '0');
        }
    }
    bool isPd = false;
    int stepCnt = -1;
    for ( ; stepCnt <= 30 && !isPd; ++stepCnt) {
        isPd = true;
        auto beg = m.begin();
        auto end = m.end() - 1;
        int len = m.size() % 2 == 0 ? 1 : 0;
        for ( ; end - beg != len; ++beg, --end) {
            if (*beg != *end) {
                isPd = false;
                break;
            }
        }
        if (isPd) {
            isPd = *beg == *end ? true : false;
        }
        size_t mSize = m.size();
        int mCopy[mSize + 1] = {};
        int mRve[mSize + 1] = {};
        for (size_t i = 0, j = mSize - 1; i < mSize; ++i, --j) {
            mCopy[i] = m[i];
            mRve[i] = m[j];
        }
        for (size_t i = 0; i < mSize + 1; ++i) {
            mCopy[i] += mRve[i];
            if (mCopy[i] >= n) {
                mCopy[i + 1] += 1;
                mCopy[i] -= n;
            }
        }
        if (mCopy[mSize] != 0) {
            m.push_back(0);
        }
        bool first = true;
        for (size_t i = 0, j = mSize; i < mSize + 1; --j) {
            if (first && mCopy[j] == 0) {
                first = false;
                continue;
            }
            m[i++] = mCopy[j];
            first = false;
        }
    }
    if (stepCnt <= 30) {
        cout << "STEP=" << stepCnt;
    } else {
        cout << "Impossible!";
    }
    return 0;
}
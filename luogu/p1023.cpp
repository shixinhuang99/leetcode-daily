/*
 * @Author       : ApassEr
 * @Date         : 2020-03-15 22:18:29
 * @LastEditTime : 2020-03-16 13:37:46
 * @Description  : P1023 税收与补贴问题
 * 暴力，枚举
 */
#include<bits/stdc++.h>

using namespace std;

struct info {
    int price = 0;
    int sales = 0;
    int profit = 0;
};

int main() {
    vector<info> list;
    int expect;
    cin >> expect;
    int a, b;
    while (cin >> a >> b) {
        struct info temp;
        temp.price = a;
        temp.sales = b;
        if (a != -1 && b != -1) {
            list.push_back(temp);
        } else {
            break;
        }
    }
    int rs;
    cin >> rs;
    int d = (list.begin()->sales - (list.end() - 1)->sales) / ((list.end() - 1)->price - list.begin()->price);
    int maxPrice = (list.end() - 1)->price;
    int maxSales = (list.end() - 1)->sales;
    int cost = list.begin()->price;
    int tempPrice = cost;
    int tempSales = list.begin()->sales;
    while (tempPrice < maxPrice) {
        bool add = true;
        ++tempPrice;
        tempSales -= d;
        for (auto i : list) {
            if (i.price == tempPrice) {
                add = false;
                break;
            }
        }
        if (add) {
            struct info temp;
            temp.price = tempPrice;
            temp.sales = tempSales;
            list.push_back(temp);
        }
    }
    tempPrice = maxPrice;
    tempSales = maxSales;
    while (tempSales > rs) {
        struct info temp;
        temp.price = ++tempPrice;
        tempSales -= rs;
        temp.sales = tempSales;
        list.push_back(temp);
    }
    int tos = 0;
    int expectProfit = 0;
    int ans = 0;
    int max = 0;
    int cnt = 0;
    bool quit = false;
    while (!quit) {
        for (auto &i : list) {
            i.profit = (i.price - cost + tos) * i.sales;
            if (i.price == expect) {
                expectProfit = i.profit;
            }
        }
        max = list.begin()->profit;
        for (auto i : list) {
            if (i.profit > max) {
                max = i.profit;
            }
        }
        if (max == expectProfit) {
            ans = tos;
            quit = true;
        }
        if (cnt < 100) {
            --tos;
        } else if (cnt == 100) {
            tos = 0;
        } else if (cnt < 200){
            ++tos;
        } else {
            quit = true;
        }
        ++cnt;
    }
    if (ans == 0) {
        cout << "NO SOLUTION";
    } else {
        cout << ans;
    }
    return 0;
}
/*
 * @Author       : ApassEr
 * @Date         : 2020-05-26 15:19:53
 * @LastEditTime : 2020-05-26 19:16:44
 * @Description  : UVA122 Trees on the level
 * @Algorithm    : 构造树，二叉树的层次遍历
 */
#include<bits/stdc++.h>

using namespace std;

struct Node {
    bool have_value;
    int value;
    Node *left, *right;
    Node() : have_value(false), left(nullptr), right(nullptr) {}
};

Node* root;

Node* newNode() {
    return new Node();
}

bool failed;
void addNode(int value, string &s) {
    int len = s.length();
    Node *t = root;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'L') {
            if (t->left == nullptr) {
                t->left = newNode();
            }
            t = t->left;
        } else if (s[i] == 'R') {
            if (t->right == nullptr) {
                t->right = newNode();
            }
            t = t->right;
        }
    }
    if (t->have_value) {
        failed = true;
    }
    t->value = value;
    t->have_value = true;
}

void removeTree(Node *n) {
    if (n == nullptr) {
        return;
    }
    removeTree(n->left);
    removeTree(n->right);
    delete n;
}

string str;
bool readInput() {
    failed = false;
    removeTree(root);
    root = newNode();
    while (1) {
        if (!(cin >> str)) {
            return false;
        }
        if (str == "()") {
            break;
        }
        str.erase(str.begin());
        stringstream stoi(str);
        int v;
        stoi >> v;
        auto index = str.find(',', 0);
        string t = str.substr(index + 1);
        addNode(v, t);
    }
    return true;
}

bool bfs(vector<int> &ans) {
    ans.clear();
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        if (!t->have_value) {
            return false;
        }
        ans.push_back(t->value);
        if (t->left != nullptr) {
            q.push(t->left);
        }
        if (t->right != nullptr) {
            q.push(t->right);
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> ans;
    while (readInput()) {
        if (!bfs(ans)) {
            failed = true;
        }
        if (failed) {
            cout << "not complete" << '\n';
        } else {
            for (int i = 0; i < ans.size(); ++i) {
                if (i != 0) {
                    cout << ' ';
                }
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
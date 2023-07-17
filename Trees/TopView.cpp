#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(mp.find(line) == mp.end()) mp[line] = node->data;
            
            if(node->left != NULL)
                q.push({node->left, line - 1});
            
            if(node->right != NULL)
                q.push({node->right, line + 1});
        }
        
        for(auto it : mp)
            ans.push_back(it.second);
        
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    pair<int,int> dfs(TreeNode* r) {
        if(!r) return {0,0};

        auto l = dfs(r->left);
        auto x = dfs(r->right);

        int sum = l.first + x.first + r->val;
        int cnt = l.second + x.second + 1;

        if(sum / cnt == r->val) ans++;

        return {sum,cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
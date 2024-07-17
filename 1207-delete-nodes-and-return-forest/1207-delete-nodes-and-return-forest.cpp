/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    set<int> todelete;
    vector<TreeNode*> forest;

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return {};
        todelete = set<int>(to_delete.begin(), to_delete.end());

        delNodesHelper(root);
        if (!todelete.contains(root->val))
            forest.push_back(root);
        else {
            if (root->right)
                forest.push_back(root->right);
            if (root->left)
                forest.push_back(root->left);
            delete root;
        }

        return forest;
    }

    void delNodesHelper(TreeNode* root) {
        if (root->right) {
            delNodesHelper(root->right);

            if (todelete.contains(root->right->val)) {
                if (root->right->right)
                    forest.push_back(root->right->right);
                if (root->right->left)
                    forest.push_back(root->right->left);

                delete root->right;
                root->right = nullptr;
            }
        }

        if (root->left) {
            delNodesHelper(root->left);

            if (todelete.contains(root->left->val)) {

                if (root->left->right)
                    forest.push_back(root->left->right);
                if (root->left->left)
                    forest.push_back(root->left->left);
                delete root->left;
                root->left = nullptr;
            }
        }
    }
};
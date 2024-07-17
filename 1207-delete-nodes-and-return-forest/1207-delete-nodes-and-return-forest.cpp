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
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> todelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> returnVect;
        delNodesHelper(root, returnVect, todelete);
        if (!todelete.contains(root->val))
            returnVect.push_back(root);
        else {
            if (root->right)
                returnVect.push_back(root->right);
            if (root->left)
                returnVect.push_back(root->left);
            delete root;
        }

        return returnVect;
    }

    void delNodesHelper(TreeNode* root, vector<TreeNode*>& forest,
                        set<int>& todelete) {
        if (!root)
            return;

        if (root->right) {
            delNodesHelper(root->right, forest, todelete);

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
            delNodesHelper(root->left, forest, todelete);

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
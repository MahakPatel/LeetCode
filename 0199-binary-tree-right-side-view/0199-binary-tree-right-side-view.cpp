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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; // to storing ans
        recursion(root,0,res);

        return res;
    }

    void recursion(TreeNode* root, int level, vector<int> &res){
        if(root == NULL) return;

        if(res.size() == level) res.push_back(root->val); // if res size is eqaul to level then push that value in res

        recursion(root->right,level+1,res); // first call right side
        recursion(root->left,level+1,res); // then call left side
    }

// +++++++++++++++++ if question is LeftSideView ++++++++++++++++
    // void recursion(TreeNode* root, int level, vector<int> &res){
    //     if(root == NULL) return;

    //     if(res.size() == level) res.push_back(root->val); // if res size is eqaul to level then push that value in res

    //     recursion(root->left,level+1,res); // first call left side
    //     recursion(root->right,level+1,res); // then call right side
    // }
};
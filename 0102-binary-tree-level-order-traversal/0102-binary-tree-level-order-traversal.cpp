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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // to store the ans
        if (root == NULL)
            return ans;

        queue<TreeNode*> q; // craete empty queue

        q.push(root); // push root node

        while (!q.empty()) { // run till queue is not empty
            int size = q.size(); // find the size of the queue
            vector<int> level; // to store the level wise node

            for (int i = 0; i < size; i++) { 
                TreeNode* node = q.front(); // take front node of the queue
                q.pop();

                if (node->left != NULL) // if left node present then
                    q.push(node->left); // push into queue
                if (node->right != NULL)// if right node present then
                    q.push(node->right); // push into queue

                level.push_back(node->val); // push node value into level vector
            }

            ans.push_back(level); // finally push level wise node into final ans
        }

        return ans;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // for storing result

        if(root == NULL) return result;

        queue<TreeNode*> q; // create e,mpty queue
        q.push(root);

        // True = leftToRight , false = RightToLeft
        bool leftToRight = true; // check travesal is left to right or right to left

        while(!q.empty()){
            int size = q.size(); // size number of nodes in queue
            vector<int> row(size);  // for numbers of node per level

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : (size - 1 - i); // if leftToRight is true then put node at 1st place, if leftToRight is false then put node from back side

                row[index] = node->val; // put the node valu into the node 

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

            }

            leftToRight = !leftToRight; // after every level change leftToRight 

            result.push_back(row); // finally put row's node in to result
        }

        return result;
    }
};